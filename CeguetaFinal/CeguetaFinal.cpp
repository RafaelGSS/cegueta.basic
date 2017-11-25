#include "stdafx.h"
#include "Config.h"
#include "Speaker.h"
#include "Input.h"
#include <thread>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Portuguese");
	//std::string str("C:\\Users\\rafae\\json.json");
	//auto st = cegueta::reader::JsonReader::readerFile(str);
	//std::wstring s = StringToWString(st["voice"].get<std::string>());
	std::thread([]() {
		cegueta::ios::Input::get()->waitCommand();
	}).detach();

	auto code = cegueta::settings::Config::get()->initialize();
	cegueta::ios::Speaker::get()->speakerFile("C:\\Users\\rafae\\testing.txt");

	system("pause");
}

