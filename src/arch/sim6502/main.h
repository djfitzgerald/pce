/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/arch/sim6502/main.h                                      
 * @date       2004-05-25 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2004-2009 Hampa Hug <hampa@hampa.ch>                        
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


#ifndef PCE_SIM6502_MAIN_H
#define PCE_SIM6502_MAIN_H 1


#include <config.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "sim6502.h"

#include <lib/cmd.h>
#include <lib/console.h>
#include <lib/iniram.h>
#include <lib/load.h>
#include <lib/monitor.h>
#include <lib/sysdep.h>


extern int       par_verbose;

extern sim6502_t *par_sim;

extern unsigned  par_sig_int;


#endif
