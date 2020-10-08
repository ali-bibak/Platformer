/***************************************************************************
 *   watcher.cpp														   *
 *                             -------------------						   *
 *   begin: Mon Aug 04 2014												   *
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

#include "watcher.h"

watcher::watcher(int _id, const object *_to, int _app_x, int _app_y, int _width, int _height)
	: append(_id, _to, _app_x, _app_y, _width, _height)
{
	obj_kind = obj_kind_rectangle;
}

watcher::~watcher(){
}
