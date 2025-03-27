// use std::stack
#include "RPN.hpp"
#include <iostream>

bool parseExpression(std::string expression)
{
	int nbOperator = 0;
	int nbOperand = 0;
	for (size_t i = 0; i < expression.length(); ++i)
	{
		if (expression[i] == ' ')
			continue;
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
		{
			nbOperator++;
			if (nbOperator >= nbOperand)
			{
				std::cerr << "Error: too much operators in the expression" << std::endl;
				return false;
			}
		}
		else if (isdigit(expression[i]))
			nbOperand++;
		else
		{
			std::cerr << "Error: token not recognized. Only digits and operators [+ - * /] are accepted" << std::endl;
			return false;
		}
	}
	return true;
}

/*
TODO:
- parsing:
	- nbOperator must always be less than nbOperand
		=> finding a space -> forget and go next no matter the number of spaces
		=> finding anything but numbers, space and operators -> error
		=> when finding operator, add 1 to nbOperator
		=> when finding operand, add 1 to nbOperand
		=> at each operator found, compare nbOperator with nbOperand
		eg:  1 2 / *				-> error bc nbOperator = nbOperand
		eg2: 1 2 /					-> good bc nbOperator < nbOperand
		eg3: 1 2 / * 2				-> error bc nbOperator = nbOperand
		eg4: 1 2 2 2 / * 2 / / / 	-> error bc nbOperator = nbOperand
	- number will always be counted as one digit
		eg:  -1						-> error bc nbOperator > nbOperand
		eg2: 123/					-> good bc 1 2 3 (nbOperands = 3) and / (nbOperator = 1)

- exec:
	- push each number encountered to the stack
	- finding an operator -> remove two numbers and execute operation with them (first out is after operator)
	- after operation -> push result to stack
*/

void executeExpression(std::string expression)
{
	for (int i = 0; i < expression.length(); ++i)
	{
		if (expression[i] == ' ')
			continue;
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
			executeOperation();
		else
			// move number to stack
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " [inverted polish mathematical expression in quotes]" << std::endl;
		return 1;
	}
	if (!parseExpression(av[1]))
		return 1;
	executeExpression(av[1]);
}

/*use exceptions or cerr?*/
