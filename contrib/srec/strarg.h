/*****************************************************************************
 * misc-utils                                                                *
 *****************************************************************************/

/**
 * @file       strarg.h                                                     
 * @date       2004-04-12 
 * @author     Hampa Hug <hampa@hampa.ch>                     
 * @copyright  (C) 2004 Hampa Hug <hampa@hampa.ch>                             
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


#ifndef MISC_STRARG_H
#define MISC_STRARG_H 1


int str_isarg2 (const char *str, const char *arg1, const char *arg2);

int str_isarg1 (const char *str, const char *arg);


#endif
