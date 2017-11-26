#include "stdafx.h"
#include "CeguetaManager.h"

using namespace cegueta;

CeguetaManager::CeguetaManager()
{
}


CeguetaManager::~CeguetaManager()
{
}

void CeguetaManager::run()
{

	std::thread(
		std::bind(
			&CeguetaManager::runnerCegueta,
			this
		)
	).detach();
}

void CeguetaManager::runnerCegueta()
{
	std::pair<KEYWORD, std::string> _tmpNotification;
	auto code = settings::Config::get()->initialize();
	ios::Speaker::get()->welcomeMenu();
	while (true)
	{
		if (events::Notification::get()->verifyNotifications()) {
			events::Notification::get()->getNotification(_tmpNotification);
			switch (_tmpNotification.first)
			{
			case SPEAKER:
				ios::Speaker::get()->speakerText(_tmpNotification.second);
				break;
			case SPEAKER_FILE:
				ios::Speaker::get()->speakerFile(_tmpNotification.second);
				break;
			case SPEAKER_MENU:
				ios::Speaker::get()->speakerFile(std::string("C:\\Users\\rafae\\") +_tmpNotification.second);
			default:
				break;
			}
		}
	}
}

CeguetaManager* CeguetaManager::get()
{
	static CeguetaManager* singleton = nullptr;
	if (!singleton)
		singleton = new CeguetaManager;

	return singleton;
}
