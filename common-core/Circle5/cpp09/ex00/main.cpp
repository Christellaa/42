#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
// use std::map

bool dataExist()
{
	std::ifstream file("data.csv");
	if (file.is_open())
		return true;
	return false;
}

bool isFileTxt(std::string file)
{
	if (file.length() < 4)
		return false;
	if (file.compare(file.length() - 4, 4, ".txt") == 0)
		return true;
	return false;
}

bool checkLine(std::string line)
{
	;
}
/*
To check the date:
-Y = between 2009 and 2022 (from data.csv)
-M = between 01 and 12
-D = between 01 and 31
with '-' between each

' | ' afterwards

To check the value:
- must be between 0 and 1000
- must be int or float (without the .0f)
*/

bool parseFile(std::string fileName)
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
	{
		std::cout << "Couldn't open " << fileName << std::endl;
		return false;
	}
	std::string line;
	std::getline(file, line);
	std::cout << line << std::endl; // for debug
	if (line != "date | value")
	{
		std::cout << line << " must be 'date | value'" << std::endl;
		return false;
	}
	while (std::getline(file, line))
	{
		std::cout << line << std::endl; // for debug
		if (!checkLine(line))
			return false;
		// for each line:
		// - check its date
		// - check its followed by space and | and space
		// - check its number
	}
	return true;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << " [file.txt]" << std::endl;
		return 1;
	}
	(void)av;
	if (!dataExist())
	{
		std::cout << av[0] << " needs data.csv to work" << std::endl;
		return 1;
	}
	if (!isFileTxt(av[1]))
	{
		std::cout << av[1] << " must have .txt extension" << std::endl;
		return 1;
	}
	if (!parseFile(av[1]))
		return 1;
	// create std:map and add each key-value (as date-value?) -> use the class (two maps? for .csv and .txt)
	// multiply value of file with value of data.csv for each date
}

/*
err msg != exception
for parsing, what to do for:
- empty file.txt
- X number of spaces before |, after |, between lines => error msg bc we want 'date | value'
*/
