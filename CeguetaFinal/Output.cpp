#include "stdafx.h"
#include "Output.h"
#include "Logger.h"

#include <sapi.h>
#include <string>
#include <iostream>
#include <sphelper.h>  
#include <atlbase.h>

#define VOICE L"IVONA 2 Vitória - Brazilian Portuguese female voice [22kHz]"

using namespace cegueta;
using namespace ios;

Output::Output()
{
	if (CoInitialize(0) != S_OK);
		log::Logger::get()->error("Unitialized Library COM");


	HRESULT hr = cpVoice.CoCreateInstance(CLSID_SpVoice);

	SpCreateDefaultObjectFromCategoryId(SPCAT_AUDIOOUT, &cpOutAudio);

	if (nullptr != cpVoice) {
		hr = cpVoice->SetOutput(cpOutAudio, FALSE);
	}

	if (SetVoice(cpVoice, VOICE));
		log::Logger::get()->error("Error while setting voice");
}


Output::~Output()
{
	::CoUninitialize();
}

void Output::welcomeMenu()
{
	// Ler de uma classe com strings predefinidas
	std::string myString("Olá, seja bem vindo ao Cegueta! Eu sou Vitória, e vou lhe guiar nessa aventura!");
	
	HRESULT spc = speakerText(myString);
	if ( spc != S_OK);
		log::Logger::get()->error("An error ocurred in speaking: " + spc);
}


HRESULT Output::speakerText(std::string text)
{
	auto converted = convertWSTR(text);
	LPCWSTR phrase = converted.c_str();

	return cpVoice->Speak(phrase,SVSFPurgeBeforeSpeak, NULL);
}

HRESULT Output::speakerFile(std::string path)
{

}

Output* Output::get()
{
	static Output* singleton = nullptr;
	if (!singleton)
		singleton = new Output;
	return singleton;
}


std::wstring Output::convertWSTR(const std::string& s)
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

HRESULT Output::SetVoice(CComPtr<ISpVoice>  _cpVoice, std::wstring _voiceName)
{
	IEnumSpObjectTokens *pProfileEnum;
	SpEnumTokens(SPCAT_VOICES, NULL, NULL, &pProfileEnum);

	unsigned long voices;
	pProfileEnum->GetCount(&voices);

	for (unsigned long i = 0; i < voices; ++i) {
		CComPtr<ISpObjectToken> IT;
		pProfileEnum->Item(i, &IT);
		CSpDynamicString dstrDefaultName;
		SpGetDescription(IT, &dstrDefaultName);
		if (wcsncmp(dstrDefaultName, _voiceName.c_str(), _voiceName.size()) == 0) {
			return _cpVoice->SetVoice(IT);
		}
	}

	return E_INVALIDARG;
}

/*

TODO IMPLEMENTING

speaker->Release();

*/