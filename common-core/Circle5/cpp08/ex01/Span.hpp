#ifndef _SPAN_HPP_
#define _SPAN_HPP_

class Span
{
	public:
		Span();
		Span(&Span copy);
		~Span();

		Span operator=(Span& rhs);

		addNumber(); // add a single number to the Span; throw exception if more than _max allowed
		shortestSpan(); // find the shortest span (= dist) between all numbers stored and return it
		longestSpan(); // find the longest span (= dist) between all numbers stored and return it
		// -> for both => no number stored or only 1 = exception bc no span can be found

	private:
		unsigned int _max;
};

#endif

// TODO after the class: create method to add multiple numbers to Span using a range of iterators instead of numerous calls to addNumber()
