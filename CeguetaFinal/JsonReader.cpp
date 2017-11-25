#include "stdafx.h"
#include "JsonReader.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace cegueta;
using namespace reader;
using Json = nlohmann::json;


JsonReader::JsonReader()
{

}


JsonReader::~JsonReader()
{
}

Json JsonReader::readerFile(std::string file)
{
	Json jsonFile;
	std::ifstream ifs(file);
	ifs >> jsonFile;
	//Json j_complete(jsonFile);
	return jsonFile;
}
