#pragma once

#include <fstream>
#include <iostream>

class Converter
{
	public:
		void convert()
		{
			//read from ASM.txt
			std::ifstream inputStream("ASM.txt", std::ifstream::in);
			
			int gcount = 0;

			for (int i = 0; i < 5; i++)
			{
				char* streamInput = new char[128];
				inputStream.getline(streamInput, 128, '\n');
				gcount = gcount + inputStream.gcount() + 1;
				inputStream.seekg(gcount);
				for (int i = 0; i < 128; i++)
				{
					std::cout << streamInput[i];
				}
				std::cout << std::endl;
			}
			

			//convert to binary

			//write to RAM.txt
		}
};