#pragma once

#include <fstream>

class CPU
{
	private:
		int m_programCounter;
		int* m_registers;

	public:

		//initalizes the cpu with the location in ram of the code it
		//should run
		CPU(int location)
		{
			m_programCounter = location;
			m_registers = new int[32];
		}

		//runs the code at the pc
		void run()
		{
			char* input = new char[32];
			std::ifstream inputStream("RAM.txt", std::ifstream::in);
			while (m_programCounter != -1)
			{
				inputStream.seekg(m_programCounter*32);
				inputStream.read(input, 32);
				for (int i = 0; i < 32; i++)
				{
					std::cout << input[i];
				}
				m_programCounter = execute(input);
			}
		}

	private:
		
		//executes the line at the passed in pc, and returns the next pc
		int execute(char* s)
		{
			switch (getOpCode(s))
			{
				case 0:		//add

					int register1 = convertBinary(s, 6, 5);
					int register2 = convertBinary(s, 11, 5);
					int destinationRegister = convertBinary(s, 16, 5);

					m_registers[destinationRegister] = m_registers[register2] + m_registers[register1];
					
				case 1:

				case 2:


			}
			

		}

		//converts part of the input string, starting at location, 
		//and being length long, into an integer from binary
		static int convertBinary(char* s, int location, int length)
		{
			int ret = 0;
			for (int i = 0; i < length; i++)
			{
				ret = (ret | ((((int)s[i+location]) - 48) << i));
			}
			return ret;
		}


		static int getOpCode(char* s)
		{
			return convertBinary(s, 0, 6);
		}
		
};