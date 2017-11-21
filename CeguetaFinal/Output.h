#pragma once
namespace cegueta {
	namespace ios {
		class Output
		{
		public:
			Output();
			~Output();
			void welcomeMenu();
			void speakMenu(const int pos);
			static Output* get();
		};
	}
}

