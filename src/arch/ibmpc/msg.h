/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/arch/ibmpc/msg.h                                         
 * @date       2004-09-25 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2004-2010 Hampa Hug <hampa@hampa.ch>                        
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


#ifndef PCE_MSG_H
#define PCE_MSG_H 1


#include "ibmpc.h"


int pc_set_msg (ibmpc_t *pc, const char *msg, const char *val);


#endif
