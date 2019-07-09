/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/arch/ibmpc/atari-pc.h                                    
 * @date       2018-09-01 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2018 Hampa Hug <hampa@hampa.ch>                             
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


#ifndef PCE_IBMPC_ATARI_PC_H
#define PCE_IBMPC_ATARI_PC_H 1


#include "ibmpc.h"


int atari_pc_get_port8 (ibmpc_t *pc, unsigned long addr, unsigned char *val);
int atari_pc_set_port8 (ibmpc_t *pc, unsigned long addr, unsigned char val);

void pc_setup_atari_pc (ibmpc_t *pc, ini_sct_t *ini);
void atari_pc_del (ibmpc_t *pc);


#endif
