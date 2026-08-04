#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>

#define RED		"\033[31m"
#define RESET	"\033[0m"
#define GREEN	"\033[32m"

class ScalarConverter {
	public:

	static void	convert(const std::string &input);
	
	private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
};


#endif