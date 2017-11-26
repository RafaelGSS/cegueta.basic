#include "stdafx.h"
#include "CeguetaManager.h"

using namespace cegueta;

CeguetaManager::CeguetaManager()
{
	running = false;
}


CeguetaManager::~CeguetaManager()
{
	running = false;
}

void CeguetaManager::run()
{
	if (running)
		return;

	running = true;

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
			case KEYUP:
				ios::Speaker::get()->keyPausePressed();
				break;
			case SPEAKER:
				ios::Speaker::get()->speakerText(_tmpNotification.second);
				break;
			case SPEAKER_FILE:
				ios::Speaker::get()->speakerFile(_tmpNotification.second);
				break;
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
