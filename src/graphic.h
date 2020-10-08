/***************************************************************************
 *   graphic.h															   *
 *                             -------------------						   *
 *   begin: Fri Aug 01 2014												   *
 *	 last modified: Tue Aug 05 2014 									   *
 *   copyright: (C) 2014 by Ali Bibak									   *
 *   email: 															   *
 *                             -------------------						   *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef graphic_h
#define graphic_h

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "object.h"
#include "collision.h"
#include <vector>

using std::vector;

class graphic{
	public:
		graphic();
		graphic(const string &_title, int _width, int _height);
		virtual ~graphic();

		void reset();

		void set_width(int _width);
		void set_height(int _height);
		void set_size(int _width, int _height);

		virtual void repaint();
		void clear();
		void close();
		bool is_open() const;
		
		bool collide(int _id1, int _id2, collision_type _col_type = col_type_png) const;
		bool collide(int id1, object_kind _obj_kind, collision_type _col_type = col_type_png) const;
		bool collide(int id1, object_type _obj_type, collision_type _col_type = col_type_png) const;

		void add_obj(const object *_obj);
		void add_bg_obj(const object *_bg_obj);
		void change_obj(const object *_obj);
		void change_bg_obj(const object *_bg_obj);
		void remove_obj(const object *_obj);
		void remove_bg_obj(const object *_bg_obj);
		
		bool get_event();
		bool closed() const;
		bool key_pressed() const;
		bool key_released() const;
		bool space_key_released() const;
		bool mouse_pressed() const;
		bool mouse_released() const;
		bool mouse_wheel_moved() const;
		bool mouse_moved() const;
		bool mouse_entered() const;
		bool mouse_left() const;

		void get_input();
		bool alpha_key_down(char _ch) const;
		bool num_key_down(int _num) const;
		bool right_key_down() const;
		bool left_key_down() const;
		bool up_key_down() const;
		bool right_button_down() const;
		bool left_button_down() const;
		bool down_key_down() const;
		bool shift_key_down() const;//
		int mouse_x() const;
		int mouse_y() const;
	protected:
		sf::RenderWindow *game_window;
		sf::Event event;
		const sf::Input *input;

		string title;

		vector<const object *> bg_obj;
		vector<const object *> obj;

		int width;
		int height;

		void new_window();
		void display();
		void paint(const object *_obj);
};

#endif
