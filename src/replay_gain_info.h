/*
 * Copyright (C) 2003-2010 The Music Player Daemon Project
 * http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef MPD_REPLAY_GAIN_INFO_H
#define MPD_REPLAY_GAIN_INFO_H

#include "check.h"

#include <stdbool.h>

enum replay_gain_mode {
	REPLAY_GAIN_OFF = -1,
	REPLAY_GAIN_ALBUM,
	REPLAY_GAIN_TRACK,
};

struct replay_gain_tuple {
	float gain;
	float peak;
};

struct replay_gain_info {
	struct replay_gain_tuple tuples[2];
};

struct replay_gain_info *
replay_gain_info_new(void);

/**
 * Duplicate a #replay_gain_info object.
 */
struct replay_gain_info *
replay_gain_info_dup(const struct replay_gain_info *src);

void
replay_gain_info_free(struct replay_gain_info *info);

static inline bool
replay_gain_tuple_defined(const struct replay_gain_tuple *tuple)
{
	return tuple->gain > 0.0;
}

#endif
