#pragma once
#include "Logger.h"
#include "stringHandler.h"
#include "Config.h"

#include <sapi.h>
#include <string>
#include <iostream>
#include <sphelper.h>  
#include <atlbase.h>

namespace cegueta {
	namespace ios {
		class Speaker
		{
		public:
			Speaker();
			~Speaker();
			void welcomeMenu();
			static Speaker* get();
			HRESULT speakerText(std::string);
			HRESULT speakerFile(std::string path);
			HRESULT SetVoice(CComPtr<ISpVoice>  _cpVoice, std::wstring _voiceName);
			void keyPausePressed();

		private:
			CComPtr<ISpVoice>   cpVoice;
			CComPtr<ISpAudio>   cpOutAudio;
		};
	}
}