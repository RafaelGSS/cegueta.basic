#include "stdafx.h"
#include <sapi.h>
#include "Output.h"
#include "JsonReader.h"
#include <string>

std::wstring StringToWString(const std::string &s)
{
	 std::wstring wsTmp(s.begin(), s.end());
	 return wsTmp;

}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Portuguese");
	//cegueta::ios::Output::get()->welcomeMenu();
	//std::string str("C:\\Users\\rafae\\json.json");
	//auto st = cegueta::reader::JsonReader::readerFile(str);
	//std::wstring s = StringToWString(st["voice"].get<std::string>());

	// TODO criar classe para conversão de strings

	system("pause");
}

