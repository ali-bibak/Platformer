/***************************************************************************
 *   object.cpp															   *
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

#include "object.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using std::ios;
using std::stringstream;

object::object(int _id, int _x, int _y, int _width, int _height){
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	id = _id;
	t = 0;
	n = 1;
	obj_type = obj_type_none;
	open = true;
	speed = 0;
	dir = dir_none;
	stat = stat_none;
}

object::~object(){
}

int object::get_x() const{
	return x;
}

int object::get_y() const{
	return y;
}

int object::get_width() const{
	return width;
}

int object::get_height() const{
	return height;
}

int object::get_id() const{
	return id;
}

int object::get_t() const{
	return t;
}

int object::get_n() const{
	return n;
}

bool object::is_open() const{
	return open;
}

int object::get_speed() const{
	return speed;
}

direction object::get_dir() const{
	return dir;
}

status object::get_stat() const{
	return stat;
}

string object::get_directory() const{
	return directory;
}

string object::get_folder_path() const{
	return folder_path;
}

string object::get_image_path() const{
	return image_path;
}

object_kind object::get_kind() const{
	return obj_kind;
}

object_type object::get_type() const{
	return obj_type;
}

void object::set(const object &other){
	x = other.get_x();
	y = other.get_y();
	width = other.get_width();
	height = other.get_height();
	id = other.get_id();
	t = other.get_t();
	n = other.get_n();
	open = other.is_open();
	speed = other.get_speed();
	dir = other.get_dir();
	stat = other.get_stat();
	directory = other.get_directory();
	folder_path = other.get_folder_path();
	image_path = other.get_image_path();
}

void object::set_x(int _x){
	x = _x;
}

void object::set_y(int _y){
	y = _y;
}

void object::set_pos(int _x, int _y){
	x = _x;
	y = _y;
}

void object::set_width(int _width){
	width = _width;
}

void object::set_height(int _height){
	height = _height;
}

void object::set_size(int _width, int _height){
	width = _width;
	height = _height;
}

void object::set_id(int _id){
	id = _id;
}

void object::set_t(int _t){
	t = _t;
}

void object::set_n(int _n){
	n = _n;
}

void object::close(){
	open = false;
}

void object::set_speed(int _speed){
	speed = _speed;
}

void object::set_dir(direction _dir){
	dir = _dir;
}

void object::set_stat(status _stat){
	stat = _stat;
}

void object::set_directory(const string &_directory){
	directory = _directory;
}

void object::set_folder_path(const string &_folder_path){
	folder_path = _folder_path;
}

void object::set_image_path(const string &_image_path){
	image_path = _image_path;
}

void object::set_kind(object_kind _obj_kind){
	obj_kind = _obj_kind;
}

void object::set_type(object_type _obj_type){
	obj_type = _obj_type;
}

void object::update_paths(){
	folder_path = directory;
	switch(stat){
		case stat_none:
			folder_path += "/none";
			break;
		case stat_steady_right:
			folder_path += "/steady_right";
			break;
		case stat_steady_left:
			folder_path += "/steady_left";
			break;
		case stat_moving_left:
			folder_path += "/moving_left";
			break;
		case stat_moving_right:
			folder_path += "/moving_right";
			break;
		case stat_jumping_right:
			folder_path += "/jumping_right";
			break;
		case stat_jumping_left:
			folder_path += "/jumping_left";
			break;
	}
	ifstream fin((folder_path + "/info.txt").c_str(), ios::in);
	int delay;
	fin >> n >> width >> height >> delay;
	stringstream ss;
	ss << ((t/delay) % n) + 1;
	string s;
	ss >> s;
	if((int)s.length() == 1)
		s = "0" + s;
	image_path = folder_path + "/" + s + ".png";
}

void object::inc_speed(int _c){
	speed += _c;
}

void object::dec_speed(int _c){
	speed -= _c;
}

void object::pass(){
	t++;
}
