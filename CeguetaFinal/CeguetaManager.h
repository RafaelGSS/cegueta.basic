#pragma once
#include <thread>
#include <functional>
#include "Config.h"
#include "Speaker.h"
#include "Notification.h"

namespace cegueta {
	class CeguetaManager
	{
	public:
		CeguetaManager();
		~CeguetaManager();
		void run();
		static CeguetaManager* get();
	private:
		void runnerCegueta();
		static bool running;
	};

}