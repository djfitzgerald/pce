/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/utils/pce-img/rebase.c                                   
 * @date       2017-12-10 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2017-2018 Hampa Hug <hampa@hampa.ch>                        
 * @copyright  GNU Public License, version 2
 */

/*****************************************************************************
 * This program is free software. You can redistribute it and / or modify it *
 * under the terms of the GNU General Public License version 2 as  published *
 * by the Free Software Foundation.                                          *
 *                                                                           *
 * This program is distributed in the hope  that  it  will  be  useful,  but *
 * WITHOUT  ANY   WARRANTY,   without   even   the   implied   warranty   of *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General *
 * Public License for more details.                                          *
 *****************************************************************************/


#include "pce-img.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <drivers/block/block.h>

#include <lib/getopt.h>


static pce_option_t opts_rebase[] = {
	{ '?', 0, "help", NULL, "Print usage information" },
	{ 'b', 1, "base", "string", "Set the base file name [none]" },
	{ 'c', 1, "cylinders", "int", "Set the number of cylinders [0]" },
	{ 'C', 1, "min-cluster-size", "int", "Set the minimum cluster size for QED [0]" },
	{ 'f', 1, "offset", "int", "Set the data offset [0]" },
	{ 'g', 3, "geometry", "3*int", "Set the disk geometry (c h s)" },
	{ 'h', 1, "heads", "int", "Set the number of heads [0]" },
	{ 'i', 1, "input", "string", "Set the input file name [stdin]" },
	{ 'I', 1, "input-type", "string", "Set the input file type [auto]" },
	{ 'n', 1, "size", "int", "Set the disk size in 512 byte blocks [0]" },
	{ 'o', 1, "output", "string", "Set the output file name [stdout]" },
	{ 'O', 1, "output-type", "string", "Set the output file type [auto]" },
	{ 'q', 0, "quiet", NULL, "Be quiet [no]" },
	{ 's', 1, "sectors", "int", "Set the number of sectors per track [0]" },
	{ 'V', 0, "version", NULL, "Print version information" },
	{ 'w', 1, "cow", "string", "Set the COW file name [none]" },
	{ 'W', 1, "cow-type", "string", "Set the cow file type [auto]" },
	{  -1, 0, NULL, NULL, NULL }
};


static
void print_help (void)
{
	pce_getopt_help (
		"pce-img rebase: Rebase COW images",
		"usage: pce-img rebase [options] input base output",
		opts_rebase
	);

	fflush (stdout);
}

static
int dsk_rebase (disk_t *dst, disk_t *src)
{
	uint32_t      i, n, m;
	uint32_t      prg_i, prg_n;
	unsigned      k;
	uint16_t      msk;
	unsigned char *buf1, *buf2;

	n = dsk_get_block_cnt (dst);
	m = dsk_get_block_cnt (src);

	if ((buf1 = pce_get_buf (16384)) == NULL) {
		return (1);
	}

	buf2 = buf1 + 8192;

	prg_i = 0;
	prg_n = n;

	i = 0;
	while (n > 0) {
		m = (n < 16) ? n : 16;

		if (dsk_read_lbaz (src, buf1, i, m)) {
			return (1);
		}

		if (dsk_read_lba (dst, buf2, i, m)) {
			return (1);
		}

		msk = 0;
		for (k = 0; k < m; k++) {
			if (memcmp (buf1 + 512 * k, buf2 + 512 * k, 512) != 0) {
				msk |= 1U << k;
			}
		}

		if (msk == 0xffff) {
			if (dsk_write_lba (dst, buf1, i, m)) {
				return (1);
			}
		}
		else if (msk != 0) {
			for (k = 0; k < m; k++) {
				if (msk & (1U << k)) {
					if (dsk_write_lba (dst, buf1 + 512 * k, i + k, 1)) {
						return (1);
					}
				}
			}
		}

		i += m;
		n -= m;

		if (par_quiet == 0) {
			prg_i += m;
			if (prg_i >= 4096) {
				fprintf (stdout, "[%6.2f%%] block %lu of %lu\r",
					(100.0 * (i + 1)) / prg_n,
					(unsigned long) i,
					(unsigned long) prg_n
				);

				prg_i = 0;

				fflush (stdout);
			}
		}
	}

	if (par_quiet == 0) {
		fprintf (stdout, "[%6.2f%%] block %lu of %lu\n",
			100.0, (unsigned long) prg_n, (unsigned long) prg_n
		);
	}

	return (0);
}

int main_rebase (int argc, char **argv)
{
	int    r;
	char   **optarg;
	disk_t *inp, *out;

	inp = NULL;
	out = NULL;

	while (1) {
		r = pce_getopt (argc, argv, &optarg, opts_rebase);

		if (r == GETOPT_DONE) {
			break;
		}

		if (r < 0) {
			return (1);
		}

		switch (r) {
		case '?':
			print_help();
			return (0);

		case 'V':
			print_version();
			return (0);

		case 'b':
			if ((out = dsk_open_inp (optarg[0], out, 1)) == NULL) {
				return (1);
			}
			if (inp != NULL) {
				pce_set_disk_parameters (inp);
			}
			break;

		case 'c':
			if (pce_set_c (optarg[0])) {
				return (1);
			}
			break;

		case 'C':
			if (pce_set_min_cluster_size (optarg[0])) {
				return (1);
			}
			break;

		case 'f':
			if (pce_set_ofs (optarg[0])) {
				return (1);
			}
			break;

		case 'g':
			if (pce_set_geo (optarg[0], optarg[1], optarg[2])) {
				return (1);
			}
			break;

		case 'h':
			if (pce_set_h (optarg[0])) {
				return (1);
			}
			break;

		case 'i':
			if ((inp = dsk_open_inp (optarg[0], inp, 1)) == NULL) {
				return (1);
			}
			break;

		case 'I':
			if (pce_set_type_inp (optarg[0])) {
				return (1);
			}
			break;

		case 'n':
			if (pce_set_n (optarg[0])) {
				return (1);
			}
			break;

		case 'o':
			if ((out = pce_cow_create (out, optarg[0])) == NULL) {
				return (1);
			}
			break;

		case 'O':
			if (pce_set_type_cow (optarg[0])) {
				return (1);
			}
			break;

		case 'q':
			pce_set_quiet (1);
			break;

		case 's':
			if (pce_set_s (optarg[0])) {
				return (1);
			}
			break;

		case 'w':
			if (out != NULL) {
				if ((out = pce_cow_open (out, optarg[0])) == NULL) {
					return (1);
				}
			}
			else if (inp != NULL) {
				if ((inp = pce_cow_open (inp, optarg[0])) == NULL) {
					return (1);
				}
			}
			else {
				return (1);
			}
			break;

		case 'W':
			if (pce_set_type_cow (optarg[0])) {
				return (1);
			}
			break;

		case 0:
			if (inp == NULL) {
				if ((inp = dsk_open_inp (optarg[0], inp, 1)) == NULL) {
					return (1);
				}
			}
			else if (out == NULL) {
				if ((out = dsk_open_inp (optarg[0], out, 1)) == NULL) {
					return (1);
				}
				pce_set_disk_parameters (inp);
			}
			else {
				if ((out = pce_cow_create (out, optarg[0])) == NULL) {
					return (1);
				}
			}
			break;

		default:
			return (1);
		}
	}

	if (inp == NULL) {
		fprintf (stderr, "%s: need an input file name\n", arg0);
		return (1);
	}

	if (out == NULL) {
		fprintf (stderr, "%s: need an output file name\n", arg0);
		return (1);
	}

	if (dsk_rebase (out, inp)) {
		fprintf (stderr, "%s: rebase failed\n", arg0);
		return (1);
	}

	dsk_del (out);
	dsk_del (inp);

	return (0);
}
