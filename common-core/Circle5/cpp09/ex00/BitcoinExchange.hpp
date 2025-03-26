#ifndef _BITCOIN_EXCHANGE_HPP_
#define _BITCOIN_EXCHANGE_HPP_

#include <map>
#include <string>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& copy);
		~BitcoinExchange();

		BitcoinExchange& operator=(BitcoinExchange const& rhs);
		void fillMap();
		std::map<std::string, float>& getMap();

	private:
		std::map<std::string, float> _map;
};

#endif
