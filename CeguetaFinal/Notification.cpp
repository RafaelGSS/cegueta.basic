#include "stdafx.h"
#include "Notification.h"

using namespace cegueta;
using namespace events;

Notification::Notification()
{
}


Notification::~Notification()
{
}

Notification* Notification::get()
{
	static Notification* singleton = nullptr;
	if (!singleton)
		singleton = new Notification();

	return singleton;
}

bool Notification::verifyNotifications()
{
	return _notifications.size() > 0;
}

void Notification::getNotification(std::pair<KEYWORD, std::string>& _notification)
{
	_notification = _notifications[0];
	_notifications.erase(_notifications.begin());

}

void Notification::addNotification(KEYWORD key, std::string value)
{
	_notifications.push_back(
		std::make_pair(key, value)
	);
}