/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/utils/psi/save.h                                         
 * @date       2013-06-09 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2013-2017 Hampa Hug <hampa@hampa.ch>                        
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


#ifndef PSI_SAVE_H
#define PSI_SAVE_H 1


#include <drivers/psi/psi.h>


int psi_save_sectors (psi_img_t *img, const char *fname);
int psi_save_weak (psi_img_t *img, const char *fname);
int psi_save_tags (psi_img_t *img, const char *fname);


#endif
