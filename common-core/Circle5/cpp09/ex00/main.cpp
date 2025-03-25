#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <limits>
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

/*
To check the date:
-Y = between 2009 and 2022 (from data.csv)
-M = between 01 and 12
-D = between 01 and 31
with '-' between each
*/

bool isLeapYear(int year)
{
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

bool checkDate(std::string date)
{
	// std::cout << "'" << date << "'" << " len: " << date.length() << " date[4]: " << date[4] << " date[7]: " << date[7] << std::endl;
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 7).c_str());
	int day = atoi(date.substr(8, date.length()).c_str());
	std::cout << "y: " << year << " m: " << month << " d: " << day << std::endl;
	if (year < 1970) // epoch
		return false;
	// have a max year? maybe the YMD of today by taking current time?
	if (month < 1 || month > 12 || day < 1)
		return false;
	char dayPerMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
		dayPerMonths[2] = 29;
	if (day > dayPerMonths[month])
		return false;
	return true;
}

bool isSpaceOrPipe(char c)
{
	return (c == ' ' || c == '|');
}

bool isIntOrFloat(std::string value)
{
	char *end = NULL;
	float number = std::strtof(value.c_str(), &end);
	if (number < -std::numeric_limits<float>::infinity() || number > std::numeric_limits<float>::infinity())
		return false;
	if (number < 0 || number > 1000)
		return false;
	return true;
}

bool checkValue(std::string value)
{
	// std::cout << "value: '" << value << "'" << std::endl;
	bool dot = false;
	for (size_t i = 0; i < value.length(); ++i)
	{
		if (value[i] == '.')
		{
			if (dot)
				return false;
			dot = true;
		}
		else if (!isdigit(value[i]))
			return false;
	}
	if (!isIntOrFloat(value))
		return false;
	return true;
}

bool checkLine(std::string line)
{
	if (line.empty())
	{
		std::cout << "Empty line" << std::endl;
		return false;
	}
	std::string::iterator it = std::find_if(line.begin(), line.end(), isSpaceOrPipe);
	size_t pos = std::distance(line.begin(), it);
	if (!checkDate(line.substr(0, pos)))
	{
		std::cout << "Wong date format at line " << line << std::endl;
		return false;
	}
	if (line.length() < 13 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return false;
	if (line.length() < 14 || !checkValue(line.substr(13)))
	{
		std::cout << "Wrong value format at line " << line << std::endl;
		return false;
	}
	return true;
}

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
		if (!
			checkLine(line))
			return false;
		// if bad line: error msg then continue
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
