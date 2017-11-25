#pragma once
#include <iostream>
#include "Speaker.h"

namespace cegueta {
	namespace ios {
		class Input
		{
		public:
			Input();
			~Input();
			static Input* get();
			void waitCommand();
		};
	}
}
