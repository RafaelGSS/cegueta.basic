#include "stdafx.h"
#include "Input.h"
#include "CeguetaManager.h"
#include <thread>
#include <chrono>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Portuguese");
	//std::string str("C:\\Users\\rafae\\json.json");
	//auto st = cegueta::reader::JsonReader::readerFile(str);
	//std::wstring s = StringToWString(st["voice"].get<std::string>());

	//Run->waitCommand | welcomeSpeak(With Help)
	cegueta::CeguetaManager::get()->run();
	cegueta::ios::Input::get()->run();

	// Precisa analisar Input ao falar e sem falar
	Sleep(6000000000000000000);
	system("pause");
}

