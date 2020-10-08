/***************************************************************************
 *   append.h															   *
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

#ifndef append_h
#define append_h

#include "types.h"
#include "object.h"

class append : public object{
	public:
		append(int _id, const object *_to, int _app_x = 0, int _app_y = 0, int _width = 0, int _height = 0);
		virtual ~append();

		int get_x() const;
		int get_y() const;
	protected:
		int app_x;
		int app_y;
		const object *to;
};

#endif
