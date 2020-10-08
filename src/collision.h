/***************************************************************************
 *   collision.h														   *
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

#include <SFML/Graphics.hpp>

#include "object.h"

using std::min;
using std::max;

static bool detect_collision(const object *_obj1, const object *_obj2, collision_type _col_type = col_type_png){
	if(_col_type != col_type_box){
		if(_obj1->get_kind() == obj_kind_rectangle && _obj2->get_kind() == obj_kind_rectangle)
			_col_type = col_type_box;
		else if(_obj1->get_kind() == obj_kind_rectangle)
			_col_type = col_type_first_box;
		else if(_obj2->get_kind() == obj_kind_rectangle)
			_col_type = col_type_second_box;
	}
	if(_col_type == col_type_second_box){
		_col_type = col_type_first_box;
		return detect_collision(_obj2, _obj1, _col_type);
	}
	int x1min = _obj1->get_x(), x1max = x1min + _obj1->get_width();
	int y1min = _obj1->get_y(), y1max = y1min + _obj1->get_height();
	int x2min = _obj2->get_x(), x2max = x2min + _obj2->get_width();
	int y2min = _obj2->get_y(), y2max = y2min + _obj2->get_height();
	if(x2min > x1max || x2max < x1min || y2min > y1max || y2max < y1min)
		return false;
	if(_col_type == col_type_box)
		return true;
	sf::Image image1, image2;
	if(_col_type == col_type_png)
		image1.LoadFromFile(_obj1->get_image_path());
	image2.LoadFromFile(_obj2->get_image_path());
	sf::Sprite sprite1, sprite2;
	if(_col_type == col_type_png)
		sprite1.SetImage(image1);
	sprite2.SetImage(image2);
	int start_x = max(x2min - x1min, 0);
	int end_x = min(_obj1->get_width(), x2max - x1min);
	int start_y = max(y2min - y1min, 0);
	int end_y = min(_obj1->get_height(), y2max - y1min);
	for(int i = start_x; i < end_x; i++)
		for(int j = start_y; j < end_y; j++){
			if(_col_type == col_type_first_box || sprite1.GetPixel(i, j).a != 0){
				int k = i + x1min - x2min;
				int l = j + y1min - y2min;
				if(k >= 0 && k < _obj2->get_width() && l >= 0 && l < _obj2->get_height() && sprite2.GetPixel(k, l).a != 0)
					return true;
			}
		}
	return false;
}
