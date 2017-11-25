#pragma once
#include <string>
#include <map>
#include <fstream>
#include "Logger.h"
#include "stringHandler.h"

#define ERROR_CODE 0;
#define OK_CODE 10;

typedef unsigned short int CODE;
typedef std::map<std::string, std::string> HashValue;

namespace cegueta {
	namespace settings {
		class Config
		{
		public:
			CODE setConfig(HashValue&);
			HashValue getConfig();
			std::string getConfig(std::string);
			CODE initialize();
			static Config* get();
			Config();
			~Config();
		private:
			HashValue config;
		};
	}
}

