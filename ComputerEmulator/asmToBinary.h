#pragma once

#include <fstream>
#include <iostream>

class Converter
{
public:
	//the file manipulation part of convert
	void convert()
	{
		//setting up filestream objects
		std::ifstream inputStream("ASM.txt", std::ifstream::in);
		std::filebuf fb;
		fb.open("test.txt", std::ios::out);
		std::ostream os(&fb);


		int gcount = 0;

		for (int i = 0; i < 5; i++)//make sure to change loop after testing
		{
			//setting up arrays for reading
			char* input = new char[128];
			char* output = new char[33];

			//reads input from ASM.txt
			inputStream.getline(input, 128, '\n');
			gcount = gcount + inputStream.gcount() + 1;
			inputStream.seekg(gcount);


			//converts input into output
			output = process(input);

			//writes output to RAM.txt
			os.write(output, 33);

			//cleaning up arrays
			delete[] output;
			delete[] input;
		}
	}

private:

	//non filestream parts of the converter
	char* process(char* input)
	{
		char* output = new char[33] {0};
		int type;

		//checks what an instruction is, sets type and opcode
		if (compare(input, "add "))
		{
			type = 1;
			output = setOpCode(0);
		}
		else if (compare(input, "addu "))
		{
			type = 1;
			output = setOpCode(0);
		}
		else if (compare(input, "sub "))
		{
			type = 1;
			output = setOpCode(0);
		}
		else if (compare(input, "subu "))
		{
			type = 1;
			output = setOpCode(0);
		}

		//assigns registers based on the type of command
		output = getRegisters(type, input);

		//makes sure the output has a newline after it
		output[32] = '\n';
		return output;
	}

	//basic string compare
	bool compare(char* input, const char* compare)
	{
		return true;
	}

	//gets registers based on type of instruction
	char* getRegisters(int type, char* input)
	{
		//r type instructions
		if (type == 1)
		{

		}
	}

	//sets the opcode from the integer value;
	char* setOpCode(int opCode)
	{
		char* output = new char[32];
		char* binaryOP = convertToBinary(opCode);
		for (int i = 0; i < 6; i++)
		{
			output[i] = binaryOP[i];
		}
		return output;
	}

	char* convertToBinary(int value)
	{

	}
};