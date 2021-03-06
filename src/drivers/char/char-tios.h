/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/drivers/char/char-tios.h                                 
 * @date       2009-03-06 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2009 Hampa Hug <hampa@hampa.ch>                             
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


#ifndef PCE_DRIVERS_CHAR_TIOS_H
#define PCE_DRIVERS_CHAR_TIOS_H 1


#include <stdio.h>

#include <drivers/char/char.h>


typedef struct char_tios_t {
	char_drv_t cdrv;

	char       *fname;

	int        fd;
} char_tios_t;


#endif
