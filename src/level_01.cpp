/***************************************************************************
 *   level_01.cpp														   *
 *                             -------------------						   *
 *   begin: Tue Aug 05 2014												   *
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

#include "level_01.h"
#include "player.h"
#include "box.h"
#include "monster.h"
#include "rectangle.h"

level_01::level_01(const string &_title, int _width, int _height)
	: level(_title, _width, _height)
{
}

level_01::~level_01(){
}

level_stat level_01::play(){
	player *simon = new player(0, 0, player_name_first, 5, 330);
	box *acc = new box(1, 50, 350, 300, 300);
	monster *mon = new monster(2, 400, 350, 30, 30);
	monster *mon2 = new monster(3, 430, 350, 30, 30);
	monster *mon3 = new monster(4, 500, 350, 30, 30);
	monster *mon4 = new monster(5, 530, 350, 30, 30);
	acc->set_type(obj_type_speedup);
	game->add_obj(acc);
	game->add_obj(simon);
	game->add_obj(mon);
	game->add_obj(mon2);
	game->add_obj(mon3);
	game->add_obj(mon4);
	game->repaint();
	game->get_input();
	direction cur_dir, prev_dir = dir_none;
	bool slide = false, moving = false, can_jump = true, from_accelerator = false, jumping = false, jump_from_accelerator, resting = false;
	int slide_speed, max_slide_speed = 5, slide_speed_growth = 3, slide_ratio = 30, time_moving_on = 0, jump_time = 33, rest_time = 10, time_jumping = 0, time_resting = 0;
	simon->set_dir(dir_right);
	while(true){
		// player's movement
		bool stop = false, just_jumped = false;
		if(simon != NULL && simon->is_alive()){
			if(game->right_key_down()){
				simon->move(dir_right);
				cur_dir = dir_right;
				moving = true;
			}
			else if(game->left_key_down()){
				simon->move(dir_left);
				cur_dir = dir_left;
				moving = true;
			}
			else{
				stop = true;
				cur_dir = dir_none;
			}
			if(jumping)
				if(time_jumping >= jump_time){
					jumping = false;
					resting = true;
					time_jumping = 0;
					time_resting = 0;
					stop = true;
				}
				else{
					if(time_jumping == jump_time-3)		
						simon->set_y(simon->get_y()+25);
					else if(time_jumping == jump_time-2)
						simon->set_y(simon->get_y()+15);
					else if(time_jumping == jump_time-1)
						simon->set_y(simon->get_y()+10);
				}
			if(resting)
				if(time_resting >= rest_time)
					resting = false;
				else
					time_resting++;
			if(!game->alpha_key_down('x'))
				can_jump = true;
			else if(can_jump && !jumping && !resting){
				jumping = true;
				jump_from_accelerator = from_accelerator;
				can_jump = false;
				just_jumped = true;
			}
		}
		if(jumping){
			time_jumping++;
			switch(time_jumping){
				case 1:
					simon->set_y(simon->get_y()-25);
					break;
				case 2:
					simon->set_y(simon->get_y()-15);
					break;
				case 3:
					simon->set_y(simon->get_y()-10);
					break;
			}
		}
		else
			jump_from_accelerator = false;
		// accelerator
		int slide_time = slide_speed * slide_ratio;
		simon->set_speed(simon->get_default_speed());
		if(jump_from_accelerator || game->collide(0, obj_type_speedup)){
			from_accelerator = true;
			if(stop && moving){
				slide = true;
				simon->set_t(0);
			}
			else if(simon->get_t() >= slide_time)
				slide = false;
			if(time_moving_on == 0 && !slide)
				slide_speed = 2;
			simon->set_speed(slide_speed);
			if(stop){
				time_moving_on = 0;
				moving = false;
				if(slide){
					simon->set_speed(slide_speed-(simon->get_t()/(slide_time/slide_speed)));
					simon->slide();
				}
				else
					simon->stop();
			}
			else{
				simon->move();
				if(cur_dir != prev_dir){
					time_moving_on = 0;
					slide_speed = 2;
				}
				else{
					time_moving_on++;
					int sq = (int)sqrt(time_moving_on), prev_sq = (int)sqrt(time_moving_on-1);
					if(!jumping && sq % slide_speed_growth == 0 && prev_sq % slide_speed_growth != 0){
						slide_speed++;
						if(slide_speed >= 5)
							slide_speed++;
					}
					slide_speed = min(slide_speed, max_slide_speed);
				}
			}
		}
		else{
			from_accelerator = false;
			time_moving_on = 0;
			slide_speed = 2;
			slide = false;
			if(stop)
				if(moving || resting){
					simon->stop();
					moving = false;
				}
				else
					simon->pass();
		}
		if(jumping){
			simon->jump();
			//exit(1);
		}
		// out of stage
		if(simon->get_x() < 0)
			simon->set_x(0);
		if(simon->get_x() > width-simon->get_width())
			simon->set_x(width-simon->get_width());
		// danger
		if(game->collide(0, obj_kind_danger)){
			game->repaint();
			return level_stat_lose;
		}
		// closing
		if(game->get_event()){
			if(game->closed()){
				game->close();
				break;
			}
		}
		game->repaint();
		prev_dir = cur_dir;
	}
	return level_stat_closed;
}
