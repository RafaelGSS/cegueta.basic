#include "stdafx.h"
#include "Input.h"

using namespace cegueta;
using namespace ios;


Input::Input()
{
	menu = UNDEFINED;
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

void Input::selectMenu(std::string option)
{
	switch (toupper(option[0]))
	{
	case 'L':
		menu = LER_DOC;
		events::Notification::get()->addNotification(SPEAKER, "Qual nome do arquivo que você deseja ler ? ");
		break;
	case 'H':
		menu = AJUDA;
		break;
	case 'J':
		menu = JOGOS;
		break;
	case 'T':
		menu = LER_TEXTO;
		break;
	default:
		break;
	}


}

void Input::verifyEvent(std::string input)
{
	switch (menu)
	{
	case LER_DOC:
		events::Notification::get()->addNotification(SPEAKER_FILE, input);
		break;
	default:
		break;
	}
}

void Input::waitCommand()
{
	Sleep(2000);
	std::string option;
	char pause;
	while (true)
	{
		while(Speaker::get()->speaking != NO_SPEAKING) {
			pause = _getch();
			if (pause == 'P' || pause == 'p' && Speaker::get()->speaking != NO_SPEAKING)
				Speaker::get()->keyPausePressed();
		}

		std::cin >> option;
		if (menu == UNDEFINED) {
			selectMenu(option);
			continue;
		}

		//verifyEvent(option);
		
	}
}