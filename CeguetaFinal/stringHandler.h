#pragma once
#include <string>
#include <Windows.h>

namespace cegueta {
	namespace handler {
		struct string
		{
			static std::wstring stringToWString(const std::string &s);
			static std::wstring stringToWinWStr(const std::string& s);
			static std::string trimString(std::string const& source, char const* delims = " \t\r\n");
		};
	}
}

