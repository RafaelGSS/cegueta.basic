#include "stdafx.h"
#include <sapi.h>
#include "Output.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Portuguese");
	
	cegueta::ios::Output::get()->welcomeMenu();
	system("pause");
}