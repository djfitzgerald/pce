/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/arch/sim405/msg.h                                        
 * @date       2018-12-24 
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


#ifndef PCE_SIM405_MSG_H
#define PCE_SIM405_MSG_H 1


#include "sim405.h"


/*****************************************************************************
 * @short Send a message to the emulator core
 * @param msg The message
 * @param val The message parameter
 *****************************************************************************/
int s405_set_msg (sim405_t *sim, const char *msg, const char *val);


#endif
