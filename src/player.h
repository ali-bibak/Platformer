/***************************************************************************
 *   player.h															   *
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

#ifndef player_h
#define player_h

#include "types.h"
#include "object.h"
#include <string>

using std::string;

class player : public object{
	public:
		player(int _id, int _num, player_name _name, int _x = 0, int _y = 0, int _width = 0, int _height = 0);
		virtual ~player();

		int get_num() const;
		player_name get_name() const;
		int get_default_speed() const;
		
		void set_num(int _num);
		void set_name(player_name _name);
		void set_default_speed(int _default_speed);

		bool is_alive() const;
		void die();
		
		void stop();
		void move();
		void move(direction _dir);
		void undo_move();
		void slide();
		void jump();
	protected:
		int num;
		player_name name;
		int default_speed;
		int prev_x;
		int prev_y;
		bool alive;
};

#endif
