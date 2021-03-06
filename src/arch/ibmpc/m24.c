/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/arch/ibmpc/m24.c                                         
 * @date       2012-01-07 
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

/* Olivetti M24 specific code */


#include "main.h"
#include "ibmpc.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#include <lib/log.h>

#include <libini/libini.h>


#ifndef DEBUG_RTC
#define DEBUG_RTC 0
#endif


static
unsigned char m24_rtc_get_uint8 (ibmpc_t *pc, unsigned long addr)
{
	time_t    t;
	struct tm *tm;
	unsigned  yrs, mon, day, hrs, min, sec, dec;

	if (pc->support_rtc) {
#ifdef HAVE_GETTIMEOFDAY
		struct timeval tv;

		if (gettimeofday (&tv, NULL)) {
			t = time (NULL);
			dec = 0;
		}
		else {
			t = tv.tv_sec;
			dec = tv.tv_usec / 100000;
		}
#else
		t = time (NULL);
#endif

		tm = localtime (&t);

		yrs = 1900 + tm->tm_year;
		mon = tm->tm_mon;
		day = tm->tm_mday;
		hrs = tm->tm_hour;
		min = tm->tm_min;
		sec = tm->tm_sec;
	}
	else {
		yrs = 1984;
		mon = 0;
		day = 1;
		hrs = 0;
		min = 0;
		sec = 0;
		dec = 0;
	}

	switch (addr) {
	case 0x01:
		return (dec % 10);

	case 0x02:
		return (sec % 10);

	case 0x03:
		return (sec / 10);

	case 0x04:
		return (min % 10);

	case 0x05:
		return (min / 10);

	case 0x06:
		return (hrs % 10);

	case 0x07:
		return (hrs / 10);

	case 0x08:
		return (day % 10);

	case 0x09:
		return (day / 10);

	case 0x0b:
		return ((mon + 1) % 10);

	case 0x0c:
		return ((mon + 1) / 10);

	case 0x0f:
		return (yrs & 7);

	default:
		pc_log_deb ("m24 rtc get port 8 %04lX\n", addr + 0x70);
		break;
	}

	return (0xff);
}

static
void m24_rtc_set_uint8 (ibmpc_t *pc, unsigned long addr, unsigned char val)
{
}

int m24_get_port8 (ibmpc_t *pc, unsigned long addr, unsigned char *val)
{
	if ((pc->model & PCE_IBMPC_M24) == 0) {
		return (1);
	}

	if ((addr >= 0x70) && (addr <= 0x7f)) {
		*val = m24_rtc_get_uint8 (pc, addr - 0x70);
#if DEBUG_RTC >= 1
		pc_log_deb ("M24 RTC get port 8 %04lX -> %02X\n", addr, *val);
#endif
		return (0);
	}

	switch (addr) {
	case 0x64:
		*val = 1;
		return (0);

	case 0x66:
		*val = pc->m24_config[0];
		return (0);

	case 0x67:
		*val = pc->m24_config[1];
		return (0);
	}

	return (1);
}

int m24_set_port8 (ibmpc_t *pc, unsigned long addr, unsigned char val)
{
	if ((pc->model & PCE_IBMPC_M24) == 0) {
		return (1);
	}

	if ((addr >= 0x70) && (addr <= 0x7f)) {
#if DEBUG_RTC >= 1
		pc_log_deb ("M24 RTC set port 8 %04lX <- %02X\n", addr, val);
#endif
		m24_rtc_set_uint8 (pc, addr - 0x70, val);
		return (0);
	}

	return (1);
}

void m24_set_video_mode (ibmpc_t *pc, unsigned mode)
{
	if (pc->model & PCE_IBMPC_M24) {
		pc->m24_config[1] &= 0xcf;
		pc->m24_config[1] |= (mode & 3) << 4;
	}
}

void pc_setup_m24 (ibmpc_t *pc, ini_sct_t *ini)
{
	unsigned  sw0, sw1;
	ini_sct_t *sct;

	pc->m24_config[0] = 0;
	pc->m24_config[1] = 0;

	if ((pc->model & PCE_IBMPC_M24) == 0) {
		return;
	}

	sct = ini_next_sct (ini, NULL, "m24");

	if (sct == NULL) {
		return;
	}

	ini_get_uint16 (sct, "switches0", &sw0, 0x00);
	ini_get_uint16 (sct, "switches1", &sw1, 0x64);

	pce_log_tag (MSG_INF, "M24:",
		"switches0=0x%02X switches1=0x%02X\n", sw0, sw1
	);

	pc->m24_config[0] = sw0;
	pc->m24_config[1] = sw1;
}
