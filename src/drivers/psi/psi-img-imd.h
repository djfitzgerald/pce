/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/drivers/psi/psi-img-imd.h                                
 * @date       2010-08-14 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2010-2013 Hampa Hug <hampa@hampa.ch>                        
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


#ifndef PSI_IMG_IMD_H
#define PSI_IMG_IMD_H 1


#include <drivers/psi/psi.h>


psi_img_t *psi_load_imd (FILE *fp);

int psi_save_imd (FILE *fp, const psi_img_t *img);

int psi_probe_imd_fp (FILE *fp);
int psi_probe_imd (const char *fname);


#endif
