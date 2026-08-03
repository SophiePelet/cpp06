#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return (*this);
}
ScalarConverter::~ScalarConverter() {}

bool    IsInt(const std::string &input) {
	if (input[0] == '+' || input[0] == '-') {
		for (size_t i = 1; i < input.length(); ++i) {
			if (!isdigit(input[i]))
				return (0);
			return (1);
		}
	}
	for (size_t i = 0; i < input.length(); ++i) {
		if (!isdigit(input[i]))
			return (0);
		return (1);
	}
}

bool	isChar(const std::string &input) {
	if (input.length() == 0 && !isdigit(input[0]) && isprint(input[0]))
		return (1);
	return (0);
}

bool	isFloat(const std::string &input) {
	
}
 
void    ScalarConverter::convert(const std::string &input) {

}