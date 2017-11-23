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
			void speakMenu(const int);
			static Output* get();
			bool speakerText(std::string);
			std::wstring convertLp(const std::string& s);
			void SetVoice(CComPtr<ISpVoice>  _cpVoice, std::wstring _voiceName);
		private:
			
		};
	}
}