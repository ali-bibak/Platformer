/***************************************************************************
 *   box.h																   *
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

#ifndef box_h
#define box_h

#include "types.h"
#include "object.h"

class box : public object{
	public:
		box(int _id, int _x = 0, int _y = 0, int _width = 0, int _height = 0);
		virtual ~box();
};

#endif
