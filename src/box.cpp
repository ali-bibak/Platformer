/***************************************************************************
 *   box.cpp															   *
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

#include "box.h"

box::box(int _id, int _x, int _y, int _width, int _height)
	: object(_id, _x, _y, _width, _height)
{
	folder_path = "../data/images/box/";
	image_path = folder_path + "01.png";
	obj_kind = obj_kind_box;
}

box::~box(){
}
