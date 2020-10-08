/***************************************************************************
 *   level.h															   *
 *                             -------------------						   *
 *   begin: Tue Aug 05 2014												   *
 *	 last modified: Tue Aug 05 2014 									   *
 *   copyright: (C) 2014 by Ali Bibak									   *
 *   email: 															   *
 *                             -------------------						   *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef level_h
#define level_h

#include "types.h"
#include "graphic.h"

class level{
	public:
		level(const string &_title, int _width, int _height);
		virtual ~level();

		string get_title() const;
		int get_width() const;
		int get_height() const;

		virtual level_stat play() = 0;
		level_stat pause();

		void reset();
	protected:
		const int width;
		const int height;
		const string title;
		graphic *game;
};

#endif
