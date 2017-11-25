#pragma once
#include "stdafx.h"
#include "stringHandler.h"

using namespace cegueta;
using namespace handler;


std::wstring string::stringToWString(const std::string &s)
{
	std::wstring wsTmp(s.begin(), s.end());
	return wsTmp;
}

std::wstring string::stringToWinWStr(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

std::string string::trimString(std::string const& source, char const* delims)
{
	std::string result(source);
	std::string::size_type index = result.find_last_not_of(delims);
	if (index != std::string::npos)
		result.erase(++index);

	index = result.find_first_not_of(delims);
	if (index != std::string::npos)
		result.erase(0, index);
	else
		result.erase();
	return result;
}