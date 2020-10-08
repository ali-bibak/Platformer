/***************************************************************************
 *   monster.cpp														   *
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

#include "monster.h"
#include <cstdlib>
#include <ctime>

monster::monster(int _id, int _x, int _y, int _width, int _height)
	: object(_id, _x, _y, _width, _height)
{
	folder_path = "../data/images/monster/";
	default_speed = 6;
	image_path = folder_path + "none/01.png";
	if(id == -3)
		image_path = folder_path + "none/02.png";
	speed = default_speed;
	direction dd[2] = {dir_left, dir_right};
	int r = rand() % 2;
	dir = dd[r];
	obj_kind = obj_kind_danger;
	obj_type = obj_type_monster;
}

monster::~monster(){
}

int monster::get_default_speed() const{
	return default_speed;
}

void monster::set_default_speed(int _default_speed){
	default_speed = _default_speed;
}

void monster::move(){
	point point_dir = point_steady;
	switch(dir){
		case dir_up:
			point_dir = point_up;
			break;
		case dir_down:
			point_dir = point_down;
			break;
		case dir_right:
			point_dir = point_right;
			break;
		case dir_left:
			point_dir = point_left;
			break;
	}
	int _x = x, _y = y;
	_x += speed * point_dir.real();
	_y += speed * point_dir.imag();
	if(_x <= 0 || _x >= 600 - 64){
		x = _x;
		if(dir == dir_left)
			dir = dir_right;
		else if(dir == dir_right)
			dir = dir_left;
	}
	x = _x;
	y = _y;
}
