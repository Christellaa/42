#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy) : _map(copy._map) {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
	if (this != &rhs)
		this->_map = rhs._map;
	return *this;
}

void BitcoinExchange::fillMap()
{
	std::ifstream data("data.csv");
	std::string line;
	std::getline(data, line);
	while (std::getline(data, line))
	{
		std::string date = line.substr(0, line.find(','));
		char *end = NULL;
		std::string val = line.substr(line.find(',') + 1);
		float value = strtof(val.c_str(), &end);
		this->_map.insert(std::make_pair(date, value));
	}
}

std::map<std::string, float>& BitcoinExchange::getMap()
{
	return this->_map;
}
