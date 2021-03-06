/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/utils/psi/new.h                                          
 * @date       2013-06-09 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2013-2018 Hampa Hug <hampa@hampa.ch>                        
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


#ifndef PSI_NEW_H
#define PSI_NEW_H 1


#include <drivers/psi/psi.h>


int psi_new (psi_img_t **img);

psi_img_t *psi_new_image (const char *type, const char *size);

int psi_regular (psi_img_t **img, const char *def);


#endif
