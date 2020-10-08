/***************************************************************************
 *   player.cpp															   *
 *                             -------------------						   *
 *   begin: Fri Aug 01 2014												   *
 *	 last modified: Thu Aug 07 2014 									   *
 *   copyright: (C) 2014 by Ali Bibak									   *
 *   email: 															   *
 *                             -------------------						   *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "player.h"
#include <fstream>

using std::ifstream;

player::player(int _id, int _num, player_name _name, int _x, int _y, int _width, int _height)
	: object(_id, _x, _y, _width, _height)
{
	num = _num;
	name = _name;
	string _directory = "../data/images";
	switch(name){
		case player_name_first:
			default_speed = first_speed;
			_directory += "/first";
			break;
		case player_name_second:
			default_speed = second_speed;
			_directory += "/second";
			break;
	}
	if(id == 0)
		stat = stat_steady_right;
	set_directory(_directory);
	update_paths();
	speed = default_speed;
	prev_x = x;
	prev_y = y;
	alive = true;
	obj_kind = obj_kind_player;
}

player::~player(){
}

int player::get_num() const{
	return num;
}

player_name player::get_name() const{
	return name;
}

int player::get_default_speed() const{
	return default_speed;
}

void player::set_num(int _num){
	num = _num;
}

void player::set_name(player_name _name){
	name = _name;
}

void player::set_default_speed(int _default_speed){
	default_speed = _default_speed;
}

bool player::is_alive() const{
	return alive;
}

void player::die(){
	alive = true;
}

void player::stop(){
	if(dir == dir_right)
		stat = stat_steady_right;
	else if(dir == dir_left)
		stat = stat_steady_left;
	t = 0;
	update_paths();
}

void player::move(){
	move(dir);
}

void player::move(direction _dir){
	point point_dir = point_steady;
	switch(_dir){
		case dir_up:
			point_dir = point_up;
			break;
		case dir_left:
			point_dir = point_left;
			stat = stat_moving_left;
			break;
		case dir_down:
			point_dir = point_down;
			break;
		case dir_right:
			point_dir = point_right;
			stat = stat_moving_right;
			break;
	}
	prev_x = x;
	prev_y = y;
	x += speed * point_dir.real();
	y += speed * point_dir.imag();
	update_paths();
	if(dir != _dir){
		t = 0;
		dir = _dir;
	}
	else
		t++;
}

void player::undo_move(){
	x = prev_x;
	y = prev_y;
}

void player::slide(){
	point point_dir = point_steady;
	switch(dir){
		case dir_right:
			point_dir = point_right;
			stat = stat_steady_right;
			break;
		case dir_left:
			point_dir = point_left;
			stat = stat_steady_left;
			break;
	}
	prev_x = x;
	prev_y = y;
	x += speed * point_dir.real();
	y += speed * point_dir.imag();
	update_paths();
	t++;
}

void player::jump(){
	switch(dir){
		case dir_right:
			stat = stat_jumping_right;
			break;
		case dir_left:
			stat = stat_jumping_left;
			break;
	}
	update_paths();
}
