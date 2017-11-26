#pragma once
#include <string>
#include <vector>
#include <utility>

#define SPEAKER_FILE 1
#define SPEAKER 2
#define SPEAKER_MENU 3

typedef int KEYWORD;

namespace cegueta {
	namespace events {
		class Notification
		{
		public:
			Notification();
			~Notification();
			static Notification* get();
			bool verifyNotifications();
			void getNotification(std::pair<KEYWORD, std::string>& _notification);	
			void addNotification(KEYWORD, std::string);
		private:
			std::vector<std::pair<KEYWORD, std::string>> _notifications;
		};
	}
}

