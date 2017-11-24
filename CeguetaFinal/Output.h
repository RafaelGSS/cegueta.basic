#pragma once
#include "stdafx.h"
#include "Output.h"
#include <sapi.h>
#include <string>
#include <iostream>
#include <sphelper.h>  
#include <atlbase.h>

namespace cegueta {
	namespace ios {
		class Output
		{
		public:
			Output();
			~Output();
			void welcomeMenu();
			static Output* get();
			HRESULT speakerText(std::string);
			HRESULT speakerFile(std::string path);
			std::wstring convertWSTR(const std::string& s);
			HRESULT SetVoice(CComPtr<ISpVoice>  _cpVoice, std::wstring _voiceName);

		private:
			CComPtr<ISpVoice>   cpVoice;
			CComPtr<ISpAudio>   cpOutAudio;
		};
	}
}