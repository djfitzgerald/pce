/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/**
 * @file       src/drivers/sound/sound-wav.h                                
 * @date       2009-10-18 
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


#ifndef PCE_DRIVERS_SOUND_WAV_H
#define PCE_DRIVERS_SOUND_WAV_H 1


#include <drivers/sound/sound.h>


void snd_wav_close (sound_drv_t *sdrv);
int snd_wav_write (sound_drv_t *sdrv, const uint16_t *buf, unsigned cnt);
int snd_wav_set_params (sound_drv_t *sdrv, unsigned chn, unsigned long srate, int sign);
int snd_wav_set_params (sound_drv_t *sdrv, unsigned chn, unsigned long srate, int sign);
int snd_wav_init (sound_drv_t *sdrv, const char *name);


#endif
