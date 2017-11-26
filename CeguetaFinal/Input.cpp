#include "stdafx.h"
#include "Input.h"

using namespace cegueta;
using namespace ios;


Input::Input()
{
}


Input::~Input()
{
}

Input* Input::get()
{
	static Input* singleton = nullptr;
	if (!singleton)
		singleton = new Input();

	return singleton;
}

void Input::run()
{
	std::thread(
		std::bind(
			&Input::waitCommand,
			this
		)
	).detach();

}

void Input::selectMenu(int& menu, char option)

void Input::waitCommand()
{
	char option;
	while (true)
	{
		option = _getch();
		if (posMenu == 0)
			selectMenu(posMenu, ctrl);
		switch (ctrl)
		{
		case 'L' || 'l':
			break;
		case 'H' || 'h':
			break;
		case 'J' || 'j':
			break;
		case 'T' || 't':
			break;
		default:
			break;
		}
	}
}