#include "converts.h"

void invalidLiteral(std::string& literal)
{
	(void)literal;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void convertSpecial(std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		std::cout << "float: " << (literal[0] == '-' ? "-inff" : "inff") << std::endl;
		std::cout << "double: " << (literal[0] == '-' ? "-inf" : "inf") << std::endl;
	}
}

void convertChar(std::string& literal)
{
	char c = static_cast<char>(literal[0]);
	if (c >= 32 && c <= 126)
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	float f = static_cast<float>(c);
	std::cout << "float: " << f << (f == static_cast<int>(f) ? ".0f" : "f") << std::endl;
	double d = static_cast<double>(c);
	std::cout << "double: " << d << (d == static_cast<int>(d) ? ".0" : "") << std::endl;
}

void convertInt(std::string& literal)
{
	int i = std::atoi(literal.c_str());
	if (i >= 32 && i <= 126)
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}
void convertFloat(std::string& literal)
{
	char *end = NULL;
	float f = std::strtof(literal.c_str(), &end);
	if (f >= 32 && f <= 126)
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else if (f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << (f == static_cast<int>(f) ? ".0f" : "f") << std::endl;
	std::cout << "double: " << static_cast<double>(f) << (f == static_cast<int>(f) ? ".0" : "") << std::endl;
}

void convertDouble(std::string& literal)
{
	char *end = NULL;
	double d = std::strtod(literal.c_str(), &end);
	if (d >= 32 &&  d <= 126)
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else if (d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << (d == static_cast<int>(d) ? ".0f" : "f") << std::endl;
	std::cout << "double: " << d << (d == static_cast<int>(d) ? ".0" : "") << std::endl;
}
