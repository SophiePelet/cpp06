#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

#define RESET	"\033[0m"
#define MAGENTA	"\033[35m"
#define GREEN	"\033[32m"

class	Base {
	public:

	virtual ~Base();

	protected:

	Base();
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif