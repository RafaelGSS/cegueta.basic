#pragma once
#include <fstream>
#include <string>

namespace cegueta {
	namespace log {
		class Logger
		{
		public:
			Logger();
			~Logger();
			static Logger* get();
			void error(std::string);
		private:
			std::ofstream logger;
		};
	}
}

