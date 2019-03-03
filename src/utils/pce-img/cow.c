/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/*****************************************************************************
 * File name:   src/utils/pce-img/cow.c                                      *
 * Created:     2013-01-14 by Hampa Hug <hampa@hampa.ch>                     *
 * Copyright:   (C) 2013-2018 Hampa Hug <hampa@hampa.ch>                     *
 *****************************************************************************/

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


static pce_option_t opts_create[] = {
	{ '?', 0, "help", NULL, "Print usage information" },
	{ 'c', 1, "cylinders", "int", "Set the number of cylinders [0]" },
	{ 'C', 1, "min-cluster-size", "int", "Set the minimum cluster size for QED [0]" },
	{ 'f', 1, "offset", "int", "Set the data offset [0]" },
	{ 'g', 3, "geometry", "3*int", "Set the disk geometry (c h s)" },
	{ 'h', 1, "heads", "int", "Set the number of heads [0]" },
	{ 'i', 1, "input", "string", "Set the input (base) file name" },
	{ 'I', 1, "input-type", "string", "Set the input file type [auto]" },
	{ 'n', 1, "size", "int", "Set the disk size in 512 byte blocks [0]" },
	{ 'o', 1, "output", "string", "Set the output (cow) file name" },
	{ 'O', 1, "output-type", "string", "Set the output file type [auto]" },
	{ 'q', 0, "quiet", NULL, "Be quiet [no]" },
	{ 's', 1, "sectors", "int", "Set the number of sectors per track [0]" },
	{ 'V', 0, "version", NULL, "Print version information" },
	{ 'w', 1, "cow", "string", "Add a COW file" },
	{ 'W', 1, "cow-type", "string", "Set the cow file type [auto]" },
	{  -1, 0, NULL, NULL, NULL }
};

static
void print_help (void)
{
	pce_getopt_help (
		"pce-img cow: Create COW files",
		"usage: pce-img cow [options] [base] [cow...]",
		opts_create
	);

	fflush (stdout);
}

int main_cow (int argc, char **argv)
{
	int    r;
	char   **optarg;
	disk_t *inp;

	inp = NULL;

	while (1) {
		r = pce_getopt (argc, argv, &optarg, opts_create);

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
			if (inp == NULL) {
				if ((inp = dsk_open_inp (optarg[0], inp, 1)) == NULL) {
					return (1);
				}
			}
			else {
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
			if (inp != NULL) {
				if ((inp = pce_cow_create (inp, optarg[0])) == NULL) {
					return (1);
				}
			}
			else {
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
			if ((inp = pce_cow_open (inp, optarg[0])) == NULL) {
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
			else {
				if ((inp = pce_cow_create (inp, optarg[0])) == NULL) {
					return (1);
				}
			}
			break;

		default:
			return (1);
		}
	}

	if (inp != NULL) {
		dsk_del (inp);
	}

	return (1);
}
