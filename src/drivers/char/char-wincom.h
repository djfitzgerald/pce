/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/drivers/char/char-wincom.h                               
 * @date       2009-03-07 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2009-2015 Hampa Hug <hampa@hampa.ch>                        
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


#ifndef PCE_DRIVERS_CHAR_WINCOM_H
#define PCE_DRIVERS_CHAR_WINCOM_H 1


#include <stdio.h>

#include <drivers/char/char.h>

#include <windows.h>


typedef struct char_wincom_t {
	char_drv_t cdrv;

	char       *fname;

	HANDLE     h;
} char_wincom_t;


#endif
