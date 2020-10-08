/***************************************************************************
 *   level.cpp															   *
 *                             -------------------						   *
 *   begin: Tue Aug 05 2014												   *
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

#include "level.h"

level::level(const string &_title, int _width, int _height)
	: title(_title),
	  width(_width),
	  height(_height)
{
	game = new graphic(title, width, height);
}

level::~level(){
	delete game;
}

string level::get_title() const{
	return title;
}

int level::get_width() const{
	return width;
}

int level::get_height() const{
	return height;
}

void level::reset(){
	game->reset();
}
