#include "BitcoinExchange.hpp"
#include "utils.h"
#include <algorithm>

bool checkDate(std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 7).c_str());
	int day = atoi(date.substr(8, date.length()).c_str());
	if (year < 1970) // epoch
		return false;
	if (month < 1 || month > 12 || day < 1)
		return false;
	char dayPerMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
		dayPerMonths[2] = 29;
	if (day > dayPerMonths[month])
		return false;
	return true;
}

int checkValue(std::string value)
{
	bool dot = false;
	for (size_t i = 0; i < value.length(); ++i)
	{
		if (value[i] == '.')
		{
			if (dot)
				return -1;
			dot = true;
		}
		else if (!isdigit(value[i]))
		{
			if (i == 0 && value[i] == '+')
				continue;
			else
				return -1;
		}
	}
	if (!isIntOrFloat(value))
		return -2;
	return 0;
}

bool parseLine(std::string line)
{
	if (line.empty())
	{
		std::cerr << "Error: empty line" << std::endl;
		return false;
	}
	std::string::iterator it = std::find_if(line.begin(), line.end(), isSpaceOrPipe);
	size_t pos = std::distance(line.begin(), it);
	if (!checkDate(line.substr(0, pos)))
	{
		std::cerr << "Error: wrong date format at line [" << line << "]" << std::endl;
		return false;
	}
	if (line.length() < 13 || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return false;
	if (line.length() < 14)
	{
		std::cerr << "Error: no value given at line [" << line << "]" << std::endl;
		return false;
	}
	int ret = checkValue(line.substr(line.find('|') + 2));
	if (ret < 0)
	{
		if (line.substr(line.find('|') + 2)[0] == '-')
			std::cerr << "Error: not a positive number at line [" << line << "]" << std::endl;
		else if (ret == -1)
			std::cerr << "Error: wrong value format at line [" << line << "]" << std::endl;
		else
			std::cerr << "Error: too large a number at line [" << line << "]" << std::endl;
		return false;
	}
	return true;
}

void executeOperation(std::string line, BitcoinExchange& data)
{
	std::string date = line.substr(0, line.find(' '));
	std::map<std::string, float>::iterator it = data.getMap().lower_bound(date);
	float value = getValue(line);
	if (it == data.getMap().begin())
		std::cerr << "Error: no date found in data.csv for this line: [" << line << "]" << std::endl;
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
		std::cerr << "Error: could not open " << fileName << std::endl;
		return false;
	}
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
	{
		std::cerr << "Error: " << line << " must be 'date | value' as the first line of the file" << std::endl;
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
		std::cerr << "Usage: " << av[0] << " [file]" << std::endl;
		return 1;
	}
	if (!dataExist())
	{
		std::cerr << "Error: " << av[0] << " needs data.csv to work" << std::endl;
		return 1;
	}
	BitcoinExchange data;
	data.fillMap();
	if (!parseAndExecute(av[1], data))
		return 1;
}

