#include "stdafx.h"
#include "Output.h"
#include <sapi.h>
#include <string>
#include <iostream>
#include <sphelper.h>  

#include <atlbase.h>


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
	std::string myString("Nando puto");
	if (!speakerText(myString))
		std::cout << "An error occurred\n";
}

void Output::speakMenu(const int pos)
{
	
}


bool Output::speakerText(std::string text)
{
	CoInitialize(0);
	CComPtr<ISpVoice>   cpVoice;
	CComPtr<ISpAudio>   cpOutAudio;

	HRESULT hr = cpVoice.CoCreateInstance(CLSID_SpVoice);

	SpCreateDefaultObjectFromCategoryId(SPCAT_AUDIOOUT, &cpOutAudio);

	if (nullptr != cpVoice) {
		hr = cpVoice->SetOutput(cpOutAudio, FALSE);
	}

	SetVoice(cpVoice, L"IVONA 2 Vitória - Brazilian Portuguese female voice [22kHz]");
	if (cpVoice) {
		cpVoice->Speak(L"Marcos gosta de leite de macho!", SVSFIsXML | SVSFPurgeBeforeSpeak, NULL);
	}

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

void Output::SetVoice(CComPtr<ISpVoice>  _cpVoice, std::wstring _voiceName)
{
	IEnumSpObjectTokens *pProfileEnum;
	SpEnumTokens(SPCAT_VOICES, NULL, NULL, &pProfileEnum);

	unsigned long l;
	pProfileEnum->GetCount(&l);

	for (unsigned long i = 0; i < l; ++i) {
		CComPtr<ISpObjectToken> IT;
		pProfileEnum->Item(i, &IT);
		WCHAR *wptr;
		IT->GetId(&wptr);
		CSpDynamicString dstrDefaultName;
		SpGetDescription(IT, &dstrDefaultName);
		if (wcsncmp(dstrDefaultName, _voiceName.c_str(), _voiceName.size()) == 0) {
			_cpVoice->SetVoice(IT);
		}
	}
}

/* TODO IMPLEMENTING

speaker->Release();

*/