/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/arch/rc759/main.h                                        
 * @date       2012-06-29 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2012-2015 Hampa Hug <hampa@hampa.ch>                        
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


#ifndef PCE_RC759_MAIN_H
#define PCE_RC759_MAIN_H 1


#include <config.h>


extern const char *par_terminal;
extern const char *par_video;


void sim_stop (void);

void sim_log_deb (const char *msg, ...);


#endif
