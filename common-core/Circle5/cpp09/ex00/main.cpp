#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <limits>

bool dataExist()
{
	std::ifstream file("data.csv");
	if (file.is_open())
		return true;
	return false;
}

bool isLeapYear(int year)
{
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

bool checkDate(std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 7).c_str());
	int day = atoi(date.substr(8, date.length()).c_str());
	if (year < 1970) // epoch
		return false;
	// have a max time? maybe the YMD of today by taking current time? "we don't do previsions"
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

bool parseLine(std::string line)
{
	if (line.empty())
	{
		std::cout << "Error: empty line" << std::endl;
		return false;
	}
	std::string::iterator it = std::find_if(line.begin(), line.end(), isSpaceOrPipe);
	size_t pos = std::distance(line.begin(), it);
	if (!checkDate(line.substr(0, pos)))
	{
		std::cout << "Error: wrong date format at line [" << line << "]" << std::endl;
		return false;
	}
	if (line.length() < 13 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return false;
	if (line.length() < 14)
	{
		std::cout << "Error: no value given at line [" << line << "]" << std::endl;
		return false;
	}
	else if (!checkValue(line.substr(line.find('|') + 2)))
	{
		if (line.substr(line.find('|') + 2)[0] == '-')
			std::cout << "Error: not a positive number at line [" << line << "]" << std::endl;
		else
			std::cout << "Error: too large a number at line [" << line << "]" << std::endl;
		return false;
	}
	return true;
}

float getValue(std::string line)
{
	char *end;
	std::string val = line.substr(line.find('|') + 2);
	return strtof(val.c_str(), &end);
}

void executeOperation(std::string line, BitcoinExchange& data)
{
	std::string date = line.substr(0, line.find(' '));
	std::map<std::string, float>::iterator it = data.getMap().lower_bound(date);
	float value = getValue(line);
	if (it == data.getMap().begin())
		std::cout << "Error: no date found in data.csv for this line: [" << line << "]" << std::endl;
	else
	{
		if (it == data.getMap().end() || it->first != date)
			--it;
		std::cout << date << " => " << value << " = " << it->second * value << std::endl;
	}
}

bool parseAndExecute(std::string fileName, BitcoinExchange& data)
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open " << fileName << std::endl;
		return false;
	}
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
	{
		std::cout << "Error: " << line << " must be 'date | value' as the first line of the file" << std::endl;
		return false;
	}
	while (std::getline(file, line))
	{
		if (parseLine(line))
			executeOperation(line, data);
	}
	return true;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: " << av[0] << " [file]" << std::endl;
		return 1;
	}
	(void)av;
	if (!dataExist())
	{
		std::cout << "Error: " << av[0] << " needs data.csv to work" << std::endl;
		return 1;
	}
	BitcoinExchange data;
	data.fillMap();
	if (!parseAndExecute(av[1], data))
		return 1;
}

/*
TODO:
- stop max date to time of today
*/
