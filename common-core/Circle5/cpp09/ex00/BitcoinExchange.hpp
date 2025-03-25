#ifndef _BITCOIN_EXCHANGE_HPP_
#define _BITCOIN_EXCHANGE_HPP_

#include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& copy);
		~BitcoinExchange();

		BitcoinExchange& operator=(BitcoinExchange const& rhs);

	private:
		std::map<std::string, std::string> map;
};

#endif
