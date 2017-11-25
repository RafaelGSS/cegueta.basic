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

void Input::waitCommand()
{
	char ctrl;
	while (true)
	{
		ctrl = getchar();
		if (ctrl == 'p')
			Speaker::get()->keyPausePressed();
	}
}