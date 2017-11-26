#pragma once
#include <iostream>
#include <thread>
#include <functional>
#include <conio.h>
#include "Notification.h"
#include "Speaker.h"
#include <string>
#include <iostream>
#include <ctype.h>

#define UNDEFINED 0
#define LER_DOC 1
#define AJUDA 2
#define JOGOS 3
#define LER_TEXTO 4

namespace cegueta {
	namespace ios {
		class Input
		{
		public:
			Input();
			~Input();
			static Input* get();
			void run();
			void waitCommand();
			void selectMenu(std::string);
			void verifyEvent(std::string);
			unsigned short menu;
		};
	}
}
