/***************************************************************************
 *   append.cpp															   *
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

#include "append.h"

append::append(int _id, const object *_to, int _app_x, int _app_y, int _width, int _height)
	: object(_id, to->get_x() + _app_x, to->get_y() + _app_y, _width, _height)
{
	app_x = _app_x;
	app_y = _app_y;
	to = _to;
	obj_type = obj_type_append;
}

append::~append(){
}

int append::get_x() const{
	return app_x + to->get_x();
}

int append::get_y() const{
	return app_y + to->get_y();
}
