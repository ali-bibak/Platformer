/***************************************************************************
 *   level_01.h															   *
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

#ifndef level_01_h
#define level_01_h

#include "level.h"

class level_01 : public level{
	public:
		level_01(const string &_title, int _width, int _height);
		~level_01();

		level_stat play();
};

#endif
