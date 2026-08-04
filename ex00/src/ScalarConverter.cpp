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
				return (false);
			return (true);
		}
	}
	else {
		for (size_t i = 0; i < input.length(); ++i) {
			if (!isdigit(input[i]))
				return (false);
			return (true);
		}
	}
	return (false);
}

bool	isChar(const std::string &input) {
	if (input.length() == 1 && !isdigit(input[0]) && isprint(input[0]))
		return (true);
	return (false);
}

bool isFloat(const std::string &input) {
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return true;

	size_t len = input.length();
	if (len < 2 || input[len - 1] != 'f')
		return false;

	size_t i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;

	int nb_dot = 0;
	int nb_digit = 0;

	for (; i < len - 1; ++i) {
		if (input[i] == '.')
			nb_dot++;
		else if (std::isdigit(input[i]))
			nb_digit++;
		else
			return false;
	}

	if (nb_dot == 1 && nb_digit > 0)
		return (true);
	else
		return (false);
}

bool	isDouble(const std::string &input) {
	if (input == "-inf" || input == "+inf" || input == "nan")
		return true;

	size_t len = input.length();
	size_t i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;

	int nb_dot = 0;
	int nb_digit = 0;

	for (; i < len - 1; ++i) {
		if (input[i] == '.')
			nb_dot++;
		else if (std::isdigit(input[i]))
			nb_digit++;
		else
			return false;
	}

	if (nb_dot == 1 && nb_digit > 0)
		return (true);
	else
		return (false);
}

void	ScalarConverter::convert(const std::string &input) {
	if (IsInt(input)) {
		long int result = std::strtol(input.c_str(), NULL, 10);

		float	to_float = static_cast<float>(result);
		double	to_double =  static_cast<double>(result);

		if (result < 0 || result > 127)
			std::cout << "char: " << RED << "impossible" << RESET << std::endl;
		else if (!isprint(static_cast<char>(result)))
			std::cout << "char: " << RED << "Non displayable" << RESET << std::endl;
		else
			std::cout << "char: '" << GREEN << static_cast<char>(result) << RESET << "'\n";

		if (result < INT_MIN || result > INT_MAX)
			std::cout << "int " << RED << "impossible" << RESET << std::endl;
		else
			std::cout << "int: " << GREEN << static_cast<int>(result) << RESET << std::endl;

		std::cout << "float: " << GREEN << to_float << ".0f" << RESET << std::endl;
		std::cout << "double: " << GREEN << to_double << ".0" << RESET << std::endl;
	}

	else if (isDouble(input)) {
		double result = std::strtod(input.c_str(), NULL);

		bool	is_pseudo_it = (input == "nan" || input == "+inf" || input == "-inf" || 
					input == "nanf" || input == "+inff" || input == "-inff");

		if (result < -FLT_MAX || result > FLT_MAX)
			std::cout << "float: " << RED << "impossible" << RESET << std::endl;
		else {
			std::cout << "float: " << GREEN << static_cast<float>(result) << RESET;
			if (!is_pseudo_it && result == std::floor(result)) //checks if this is a whole number
				std::cout << GREEN << ".0" << RESET;
			std::cout << GREEN << "f" << RESET << std::endl;
		}

		if (input == "nan" || input == "+inf" || input == "-inf" || result < INT_MIN || result > INT_MAX)
			std::cout << "int: " << RED << "impossible" << RESET << std::endl;
		else
			std::cout << "int: " << GREEN << static_cast<int>(result) << RESET << std::endl;

		if (input == "nan" || input == "+inf" || input == "-inf" || result < 0 || result > 127)
			std::cout << "char: " << RED << "impossible" << RESET << std::endl;
		else if (!isprint(static_cast<char>(result)))
			std::cout << "char: " << RED << "Non displayable" << RESET << std::endl;
		else
			std::cout << "char: '" << GREEN << static_cast<char>(result) << RESET << "'\n";
		
		std::cout << "double: " << GREEN << result << RESET;
		if (!is_pseudo_it && result == std::floor(result)) {
			std::cout << GREEN << ".0" << RESET;
		}
		std::cout << std::endl;
	}

	else if (isFloat(input)) {
		double result = std::strtod(input.c_str(), NULL);

		bool	is_pseudo_it = (input == "nan" || input == "+inf" || input == "-inf" || 
					input == "nanf" || input == "+inff" || input == "-inff");

		if (result < -FLT_MAX || result > FLT_MAX)
			std::cout << "float: " << RED << "impossible" << RESET << std::endl;
		else {
			std::cout << "float: " << GREEN << static_cast<float>(result) << RESET;
			if (!is_pseudo_it && result == std::floor(result))
				std::cout << GREEN << ".0" << RESET;
			std::cout << GREEN << "f" << RESET << std::endl;
		}

		if (input == "nanf" || input == "+inff" || input == "-inff" || result < INT_MIN || result > INT_MAX)
			std::cout << "int: " << RED << "impossible" << RESET << std::endl;
		else
			std::cout << "int: " << GREEN << static_cast<int>(result) << RESET << std::endl;

		if (input == "nanf" || input == "+inff" || input == "-inff" || result < 0 || result > 127)
			std::cout << "char: " << RED << "impossible" << RESET << std::endl;
		else if (!isprint(static_cast<char>(result)))
			std::cout << "char: " << RED << "Non displayable" << RESET << std::endl;
		else
			std::cout << "char: '" << GREEN << static_cast<char>(result) << RESET << "'\n";
		
		std::cout << "double: " << GREEN << result << RESET;
		if (!is_pseudo_it && result == std::floor(result)) {
			std::cout << GREEN << ".0" << RESET;
		}
		std::cout << std::endl;
	}

	else if (isChar(input)) {
		char result = input[0];

		std::cout << "char: '" << GREEN << result << RESET << "'\n";
		std::cout << "int: " << GREEN << static_cast<int>(result) << RESET << "\n";
		std::cout << "float: " << GREEN << static_cast<float>(result) << RESET << ".0f\n"; 
		std::cout << "double: " << GREEN << static_cast<double>(result) << RESET << ".0\n"; 
	}
	else
		std::cout << RED << "Incorrect input" << RESET << std::endl;
}