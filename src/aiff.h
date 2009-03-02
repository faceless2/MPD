/*
 * Copyright (C) 2003-2009 The Music Player Daemon Project
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/** \file
 *
 * A parser for the AIFF file format.
 */

#ifndef MPD_AIFF_H
#define MPD_AIFF_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/**
 * Seeks the AIFF file to the ID3 chunk.
 *
 * @return the size of the ID3 chunk on success, or 0 if this is not a
 * AIFF file or no ID3 chunk was found
 */
size_t
aiff_seek_id3(FILE *file);

#endif
