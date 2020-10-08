/***************************************************************************
 *   types.h															   *
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

#ifndef types_h
#define types_h

#include <complex>

using std::complex;

typedef complex<int> point;

const point point_steady(0, 0);
const point point_up(0, -1);
const point point_left(-1, 0);
const point point_down = -point_up;
const point point_right = -point_left;
const point point_upright = point_up + point_right;
const point point_upleft = point_up + point_left;
const point point_downright = point_down + point_right;
const point point_downleft = point_down + point_left;

const int first_speed = 3;
const int second_speed = 5;

typedef enum{
	player_name_first,
	player_name_second,
} player_name;

typedef enum{
	obj_kind_player,
	obj_kind_box,
	obj_kind_danger,
	obj_kind_graphics,
	obj_kind_rectangle,
	obj_kind_debug
} object_kind;

typedef enum{
	obj_type_none,
	obj_type_ammu_box,
	obj_type_apple_box,
	obj_type_tnt,
	obj_type_nitro,
	obj_type_missile,
	obj_type_speedup,
	obj_type_speeddown,
	obj_type_monster,
	obj_type_append,
} object_type;

typedef enum{
	dir_none,
	dir_up,
	dir_left,
	dir_down,
	dir_right,
	dir_upright,
	dir_upleft,
	dir_downright,
	dir_downleft
} direction;

typedef enum{
	stat_none,
	stat_steady_right,
	stat_steady_left,
	stat_moving_right,
	stat_moving_left,
	stat_jumping_right,
	stat_jumping_left,
	stat_breaking,
	stat_blowing,
} status;

typedef enum{
	col_type_png,
	col_type_box,
	col_type_first_box,
	col_type_second_box
} collision_type;

typedef enum{
	level_stat_win,
	level_stat_lose,
	level_stat_closed,
} level_stat;

#endif
