/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/arch/simarm/main.h                                       
 * @date       2004-11-04 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2004-2013 Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2004-2006 Lukas Ruf <ruf@lpr.ch>                            
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

/*****************************************************************************
 * This software was developed at the Computer Engineering and Networks      *
 * Laboratory (TIK), Swiss Federal Institute of Technology (ETH) Zurich.     *
 *****************************************************************************/


#ifndef PCE_SIMARM_MAIN_H
#define PCE_SIMARM_MAIN_H 1


#include <config.h>


extern int      par_verbose;

extern unsigned par_xlat;

extern struct simarm_s *par_sim;

extern unsigned par_sig_int;


#endif
