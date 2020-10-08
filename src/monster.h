/***************************************************************************
 *   monster.h															   *
 *                             -------------------						   *
 *   begin: Sat Aug 02 2014												   *
 *	 last modified: Mon Aug 04 2014 									   *
 *   copyright: (C) 2014 by Ali Bibak									   *
 *   email: 															   *
 *                             -------------------						   *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef monster_h
#define monster_h

#include "types.h"
#include "object.h"

class monster : public object{
	public:
		monster(int _id, int _x = 0, int _y = 0, int _width = 0, int _height = 0);
		virtual ~monster();

		int get_default_speed() const;

		void set_default_speed(int _default_speed);

		void move();
	protected:
		int default_speed;
};

#endif
