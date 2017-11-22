#include "stdafx.h"
#include "Output.h"
#include <sapi.h>
#include <string>
#include <iostream>

using namespace cegueta;
using namespace ios;

Output::Output()
{
	
}


Output::~Output()
{
}

void Output::welcomeMenu()
{
	std::string myString("Hello world");
	if (!speakerText(myString))
		std::cout << "An error occurred\n";
}

void Output::speakMenu(const int pos)
{
	
}


bool Output::speakerText(std::string text)
{
	LPCWSTR result = convertLp(text).c_str();

	ISpVoice* speaker = NULL;
	if (FAILED(::CoInitialize(NULL))) {
		return false;
	}
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&speaker);
	if (SUCCEEDED(hr))
	{
		hr = speaker->Speak(L"HELLO WORLD", 0, NULL);
		speaker->Release();
		speaker = NULL;
	}

	::CoUninitialize();
	return true;
}

Output* Output::get()
{
	static Output* singleton = nullptr;
	if (!singleton)
		singleton = new Output;
	return singleton;
}


std::wstring Output::convertLp(const std::string& s)
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


/* TODO IMPLEMENTING

speaker->Release();

*/