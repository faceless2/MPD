/*
 * Copyright 2003-2022 The Music Player Daemon Project
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

#include "Path.hxx"
#include "Charset.hxx"

std::string
Path::ToUTF8() const noexcept
{
	try {
		return ToUTF8Throw();
	} catch (...) {
		return {};
	}
}

std::string
Path::ToUTF8Throw() const
{
	return ::PathToUTF8(c_str());
}

Path::const_pointer
Path::GetSuffix() const noexcept
{
	const auto *base = GetBase().c_str();

	/* skip all leading dots (hidden/special files on UNIX-like
	   operating systems) */
	while (*base == '.')
		++base;

	return StringFindLast(base, '.');
}

Path::const_pointer
Path::GetExtension() const noexcept
{
	const auto *result = GetSuffix();
	if (result != nullptr)
		/* skip the dot */
		++result;

	return result;
}
