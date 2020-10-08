/***************************************************************************
 *   main.cpp															   *
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

#include "level_01.h"

int main(){
	const int window_x = 1000, window_y = 400;
	level_01 level01("Castlevania", window_x, window_y);
	while(true){
		if(level01.play() == level_stat_closed)
			return 0;
		level01.reset();
	}
	return 0;
}
