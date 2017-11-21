#include "stdafx.h"
#include "Output.h"
#include <iostream>


using namespace cegueta;
using namespace ios;

Output::Output()
{
}


Output::~Output()
{
}

void Output::welcomeMenu()
{

}

void Output::speakMenu(const int pos)
{
}

Output* Output::get()
{
	static Output* singleton = nullptr;
	if (!singleton)
		singleton = new Output;
	return singleton;
}
