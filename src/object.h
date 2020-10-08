/***************************************************************************
 *   object.h															   *
 *                             -------------------						   *
 *   begin: Fri Aug 01 2014												   *
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

#ifndef object_h
#define object_h

#include "types.h"
#include <string>

using std::string;

class object{
	public:
		object(int _id, int _x = 0, int _y = 0, int _width = 0, int _height = 0);
		virtual ~object();

		virtual int get_x() const;
		virtual int get_y() const;
		int get_width() const;
		int get_height() const;
		int get_id() const;
		int get_t() const;
		int get_n() const;
		bool is_open() const;
		int get_speed() const;
		direction get_dir() const;
		status get_stat() const;
		string get_directory() const;
		string get_folder_path() const;
		string get_image_path() const;
		object_kind get_kind() const;
		object_type get_type() const;

		void set(const object &other);
		void set_x(int _x);
		void set_y(int _y);
		void set_pos(int _x, int _y);
		void set_width(int _width);
		void set_height(int _height);
		void set_size(int _width, int _height);
		void set_id(int _id);
		void set_t(int _t);
		void set_n(int _n);
		void close();
		void set_speed(int _speed);
		void set_dir(direction _dir);
		void set_stat(status _stat);
		void set_directory(const string &_directory);
		void set_folder_path(const string &_folder_path);
		void set_image_path(const string &_image_path);
		void set_kind(object_kind _obj_kind);
		void set_type(object_type _obj_type);

		void update_paths();

		void inc_speed(int _c = 1);
		void dec_speed(int _c = 1);
		void pass();
	protected:
		int x;
		int y;
		int width;
		int height;
		int id;
		int t;
		int n;
		bool open;
		int speed;
		direction dir;
		status stat;
		string directory;
		string folder_path;
		string image_path;
		object_kind obj_kind;
		object_type obj_type;
};

#endif
