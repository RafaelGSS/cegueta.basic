#include "stdafx.h"
#include "Logger.h"
#include <fstream>
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>

#define FILE "C:\\logger.txt"

using namespace cegueta;
using namespace log;

Logger::Logger()
{
	logger.open(FILE, std::ios::in | std::ios::app);
}


Logger::~Logger()
{
}

void Logger::error(std::string error)
{
	auto time = std::chrono::system_clock::now();
	std::time_t timne = std::chrono::system_clock::to_time_t(time);
	logger << error << std::ctime(&timne);
	logger.close();
}

Logger* Logger::get()
{
	static Logger* singleton = nullptr;
	if (!singleton)
		singleton = new Logger;
	return singleton;
}
