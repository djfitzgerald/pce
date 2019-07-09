/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/arch/ibmpc/m24.h                                         
 * @date       2012-01-07 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2012 Hampa Hug <hampa@hampa.ch>                             
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


#ifndef PCE_IBMPC_M24_H
#define PCE_IBMPC_M24_H 1


#include "ibmpc.h"


int m24_get_port8 (ibmpc_t *pc, unsigned long addr, unsigned char *val);
int m24_set_port8 (ibmpc_t *pc, unsigned long addr, unsigned char val);

void m24_set_video_mode (ibmpc_t *pc, unsigned mode);

void pc_setup_m24 (ibmpc_t *pc, ini_sct_t *ini);


#endif
