#include "utils.h"

bool dataExist()
{
	std::ifstream file("data.csv");
	if (file.is_open())
		return true;
	return false;
}

bool isSpaceOrPipe(char c)
{
	return (c == ' ' || c == '|');
}

bool isLeapYear(int year)
{
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
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

float getValue(std::string line)
{
	char *end;
	std::string val = line.substr(line.find('|') + 2);
	return strtof(val.c_str(), &end);
}
