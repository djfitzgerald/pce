/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/drivers/pri/pri-img-tc.h                                 
 * @date       2012-02-01 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2012-2013 Hampa Hug <hampa@hampa.ch>                        
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


#ifndef PCE_PRI_IMG_TC_H
#define PCE_PRI_IMG_TC_H 1


#include <drivers/pri/pri.h>


pri_img_t *pri_load_tc (FILE *fp);

int pri_save_tc (FILE *fp, const pri_img_t *img);

int pri_probe_tc_fp (FILE *fp);
int pri_probe_tc (const char *fname);


#endif
