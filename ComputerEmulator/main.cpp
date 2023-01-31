
#include <iostream>
#include <fstream>
#include "main.h"
#include "centralProcessing.h"

int main()
{
	char a;
	CPU* main = new CPU(0);
	main->run();
	std::cin >> a;
}

