#include "stdafx.h"
#include "Speaker.h"


using namespace cegueta;
using namespace ios;


Speaker::Speaker()
{
	if (CoInitialize(0) != S_OK)
		log::Logger::get()->error("Unitialized Library COM ");


	HRESULT hr = cpVoice.CoCreateInstance(CLSID_SpVoice);

	SpCreateDefaultObjectFromCategoryId(SPCAT_AUDIOOUT, &cpOutAudio);

	if (nullptr != cpVoice) {
		hr = cpVoice->SetOutput(cpOutAudio, FALSE);
	}

	std::wstring voice = handler::string::stringToWString(
								settings::Config::get()->getConfig("VOICE")
								);
	if (SetVoice(cpVoice, voice))
		log::Logger::get()->error("Error while setting voice ");
}


Speaker::~Speaker()
{
	::CoUninitialize();
}

void Speaker::welcomeMenu()
{
	// Ler de uma classe com strings predefinidas
	std::string myString("Olá, seja bem vindo ao Cegueta! Eu sou Vitória, e vou lhe guiar nessa aventura!");
	
	HRESULT spc = speakerText(myString);
	if ( spc != S_OK)
		log::Logger::get()->error("An error ocurred in speaking: " + spc);
}


HRESULT Speaker::speakerText(std::string text)
{
	auto converted = handler::string::stringToWinWStr(text);
	LPCWSTR phrase = converted.c_str();

	auto code = cpVoice->Speak(
			phrase,
			SVSFPurgeBeforeSpeak,
			NULL);

	return code;
}

HRESULT Speaker::speakerFile(std::string path)
{
	auto file = handler::string::stringToWinWStr(path);
	return cpVoice->Speak(file.c_str(), SPF_IS_FILENAME, NULL);
}

Speaker* Speaker::get()
{
	static Speaker* singleton = nullptr;
	if (!singleton)
		singleton = new Speaker();
	return singleton;
}




HRESULT Speaker::SetVoice(CComPtr<ISpVoice>  _cpVoice, std::wstring _voiceName)
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

void Speaker::keyPausePressed()
{
	static bool speaking = true;
	if (!speaking) {
		cpVoice->Resume();
		speaking = true;
	}
	else {
		cpVoice->Pause();
		speaking = false;
	}
}
/*

TODO IMPLEMENTING

speaker->Release();

*/