/***************************************************************************
 *   rectangle.cpp														   *
 *                             -------------------						   *
 *   begin: Sat Aug 02 2014												   *
 *	 last modified: Sat Aug 02 2014 									   *
 *   copyright: (C) 2014 by Ali Bibak									   *
 *   email: 															   *
 *                             -------------------						   *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "rectangle.h"

rectangle::rectangle(int _id, int _x, int _y, int _width, int _height)
	: object(_id, _x, _y, _width, _height)
{
	obj_kind = obj_kind_rectangle;
}

rectangle::~rectangle(){
}
