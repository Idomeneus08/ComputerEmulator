
#include <iostream>
#include <fstream>
#include "main.h"
#include "centralProcessing.h"
#include "asmToBinary.h"

int main()
{
	char a;

	Converter* convert = new Converter();
	convert->convert();

	CPU* main = new CPU(0);
	main->run();


	std::cin >> a;
}

