#pragma once
#include <iostream>
#include <thread>
#include <functional>
#include <conio.h>
#include "Notification.h"

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
			void selectMenu(int&, char);
		};
	}
}
