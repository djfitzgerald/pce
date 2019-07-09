/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/arch/rc759/msg.h                                         
 * @date       2012-06-29 
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


#ifndef PCE_RC759_MSG_H
#define PCE_RC759_MSG_H 1


#include "rc759.h"


int rc759_set_msg (rc759_t *sim, const char *msg, const char *val);


#endif
