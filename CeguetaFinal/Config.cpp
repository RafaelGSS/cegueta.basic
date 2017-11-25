#include "stdafx.h"
#include "Config.h"


using namespace cegueta;
using namespace settings;

Config::Config()
{
}


Config::~Config()
{
}

CODE Config::setConfig(HashValue &config)
{
	this->config = config;

	return S_OK;
}

HashValue Config::getConfig()
{

}

std::string Config::getConfig(std::string s)
{
	return config[s];
}

CODE Config::initialize()
{
	std::ifstream cfg;
	cfg.open("C:\\Users\\rafae\\config.txt");
	if (!cfg.is_open()) {
		log::Logger::get()->error("Error while open configuration file ");
		return ERROR_CODE;
	}

	HashValue configT;
	std::string strTmp;
	while (std::getline(cfg, strTmp)) {
		int posDelimiter = strTmp.find('=');

		if (posDelimiter == std::string::npos) {
			log::Logger::get()->error("Error while read line. Not found delimiter '=' ");
			return ERROR_CODE;
		}

		std::string hash = handler::string::trimString(strTmp.substr(0, posDelimiter));
		std::string value = handler::string::trimString(strTmp.substr(posDelimiter + 1));
		configT[hash] = value;
	}

	return setConfig(configT);

}

Config* Config::get()
{
	static Config* singleton = nullptr;
	if (!singleton)
		singleton = new Config();

	return singleton;
}
