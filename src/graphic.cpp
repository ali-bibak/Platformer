/***************************************************************************
 *   graphic.cpp														   *
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

#include "graphic.h"
#include <cstring>
#include <iostream>

using std::cerr;
using std::endl;

graphic::graphic(){
	title = "Untitled";
	game_window = NULL;
	input = NULL;
	width = 600;
	height = 600;
	new_window();
}

graphic::graphic(const string &_title, int _width, int _height){
	title = _title;
	game_window = NULL;
	width = _width;
	height = _height;
	input = NULL;
	new_window();
}

graphic::~graphic(){
	close();
}

void graphic::reset(){
	clear();
	obj.clear();
	bg_obj.clear();
}

void graphic::set_width(int _width){
	width = _width;
}

void graphic::set_height(int _height){
	height = _height;
}

void graphic::set_size(int _width, int _height){
	width = _width;
	height = _height;
}

void graphic::new_window(){
	if(is_open())
		close();
	game_window = new sf::RenderWindow(sf::VideoMode(width, height, 64), title, sf::Style::Close | sf::Style::Titlebar);
}

void graphic::repaint(){
	if(!is_open())
		return;
	clear();
	for(int i = 0; i < (int)bg_obj.size(); i++)
		paint(bg_obj[i]);
	for(int i = 0; i < (int)obj.size(); i++)
		paint(obj[i]);
	display();
}

void graphic::clear(){
	if(!is_open())
		return;
	game_window->Clear();
}

void graphic::close(){
	if(is_open())
		game_window->Close();
	if(game_window == NULL)
		delete game_window;
}

bool graphic::is_open() const{
	if(game_window == NULL)
		return false;
	return game_window->IsOpened();
}

bool graphic::collide(int _id1, int _id2, collision_type _col_type) const{	
	const object *obj1 = NULL, *obj2 = NULL;
	for(int i = 0; i < (int)obj.size(); i++)
		if(obj[i]->get_id() == _id1)
			obj1 = obj[i];
		else if(obj[i]->get_id() == _id2)
			obj2 = obj[i];
	if(obj1 == NULL || obj2 == NULL)
		return false;
	return detect_collision(obj1, obj2, _col_type);
}

bool graphic::collide(int _id1, object_kind _obj_kind, collision_type _col_type) const{
	if(_col_type == col_type_second_box){
		cerr << "bad argument '_col_type'" << endl;
		exit(1);
	}
	const object *obj1 = NULL;
	vector<const object *> candidates;
	for(int i = 0; i < (int)obj.size(); i++)
		if(obj[i]->get_id() == _id1)
			obj1 = obj[i];
		else if(obj[i]->get_kind() == _obj_kind)
			candidates.push_back(obj[i]);
	if(obj1 == NULL)
		return false;
	for(int i = 0; i < (int)candidates.size(); i++)
		if(detect_collision(obj1, candidates[i], _col_type))
			return true;
	return false;
}

bool graphic::collide(int _id1, object_type _obj_type, collision_type _col_type) const{
	if(_col_type == col_type_second_box){
		cerr << "bad argument '_col_type'" << endl;
		exit(1);
	}
	const object *obj1 = NULL;
	vector<const object *> candidates;
	for(int i = 0; i < (int)obj.size(); i++)
		if(obj[i]->get_id() == _id1)
			obj1 = obj[i];
		else if(obj[i]->get_type() == _obj_type)
			candidates.push_back(obj[i]);
	if(obj1 == NULL)
		return false;
	for(int i = 0; i < (int)candidates.size(); i++)
		if(detect_collision(obj1, candidates[i], _col_type))
			return true;
	return false;
}

void graphic::add_obj(const object *_obj){
	obj.push_back(_obj);
}

void graphic::add_bg_obj(const object *_bg_obj){
	bg_obj.push_back(_bg_obj);
}

void graphic::change_obj(const object *_obj){
	for(int i = 0; i < (int)obj.size(); i++)
		if(obj[i]->get_id() == _obj->get_id()){
			obj[i] = _obj;
			break;
		}
}

void graphic::change_bg_obj(const object *_bg_obj){
	for(int i = 0; i < (int)bg_obj.size(); i++)
		if(bg_obj[i]->get_id() == _bg_obj->get_id()){
			bg_obj[i] = _bg_obj;
			break;
		}
}

void graphic::remove_obj(const object *_obj){
	vector<const object *>::iterator it = obj.begin();
	for(int i = 0; i < (int)obj.size(); i++, it++)
		if(obj[i]->get_id() == _obj->get_id()){
			obj.erase(it);
			break;
		}
}

void graphic::remove_bg_obj(const object *_bg_obj){
	vector<const object *>::iterator it = bg_obj.begin();
	for(int i = 0; i < (int)bg_obj.size(); i++, it++)
		if(bg_obj[i]->get_id() == _bg_obj->get_id()){
			bg_obj.erase(it);
			break;
		}
}

bool graphic::get_event(){
	return is_open() && game_window->GetEvent(event);
}

bool graphic::closed() const{
	return is_open() && event.Type == sf::Event::Closed;
}

bool graphic::key_pressed() const{
	return is_open() && event.Type == sf::Event::KeyPressed;
}

bool graphic::key_released() const{
	return is_open() && event.Type == sf::Event::KeyReleased;
}

bool graphic::mouse_pressed() const{
	return is_open() && event.Type == sf::Event::MouseButtonPressed;
}

bool graphic::mouse_released() const{
	return is_open() && event.Type == sf::Event::MouseButtonReleased;
}

bool graphic::mouse_wheel_moved() const{
	return is_open() && event.Type == sf::Event::MouseWheelMoved;
}

bool graphic::mouse_moved() const{
	return is_open() && event.Type == sf::Event::MouseMoved;
}

bool graphic::mouse_entered() const{
	return is_open() && event.Type == sf::Event::MouseEntered;
}

bool graphic::mouse_left() const{
	return is_open() && event.Type == sf::Event::MouseLeft;
}

void graphic::get_input(){
	if(is_open())
		input = &game_window->GetInput();
}

bool graphic::alpha_key_down(char _ch) const{
	if(!is_open() || input == NULL)
		return false;
	_ch = toupper(_ch);
	if(_ch < 'A' || _ch > 'Z')
		return false;
	int ind = (int)sf::Key::A + _ch - 'A';
	return input->IsKeyDown((sf::Key::Code)ind);
}

bool graphic::num_key_down(int _num) const{
	if(!is_open() || input == NULL)
		return false;
	if(_num < 0 || _num > 9)
		return false;
	int ind = (int)sf::Key::Num0 + _num;
	return input->IsKeyDown((sf::Key::Code)ind);
}

bool graphic::right_key_down() const{
	if(!is_open() || input == NULL)
		return false;
	return input->IsKeyDown(sf::Key::Right);
}

bool graphic::left_key_down() const{
	if(!is_open() || input == NULL)
		return false;
	return input->IsKeyDown(sf::Key::Left);
}

bool graphic::up_key_down() const{
	if(!is_open() || input == NULL)
		return false;
	return input->IsKeyDown(sf::Key::Up);
}

bool graphic::down_key_down() const{
	if(!is_open() || input == NULL)
		return false;
	return input->IsKeyDown(sf::Key::Down);
}

bool graphic::right_button_down() const{
	if(!is_open() || input == NULL)
		return false;
	return input->IsMouseButtonDown(sf::Mouse::Right);
}

bool graphic::left_button_down() const{
	if(!is_open() || input == NULL)
		return false;
	return input->IsMouseButtonDown(sf::Mouse::Left);
}

int graphic::mouse_x() const{
	if(!is_open() || input == NULL)
		return -1;
	return input->GetMouseX();
}

int graphic::mouse_y() const{
	if(!is_open() || input == NULL)
		return -1;
	return input->GetMouseY();
}

void graphic::paint(const object *_obj){
	if(!is_open())
		return;
	if(_obj->get_kind() == obj_kind_rectangle)
		return;
	sf::Image image;
	image.LoadFromFile(_obj->get_image_path());
	sf::Sprite sprite;
	sprite.SetImage(image);
	int x = _obj->get_x();
	int y = _obj->get_y();
	sprite.SetPosition(x, y);
	game_window->Draw(sprite);
}

void graphic::display(){
	if(is_open())
		game_window->Display();
}
