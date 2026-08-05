#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*
	Constructor/destructor, copy constructor, copy assignment operator
*/
Base::Base() {}
Base::~Base() {}

/*
	Functions
*/
Base*	generate(void) {
	Base*	new_class;

	int	random = rand() % 3;
	if (random == 0) {
		new_class = new A;
		return (new_class);
	}
	else if (random == 1) {
		new_class = new B;
		return (new_class);
	}
	else {
		new_class = new C();
		return (new_class);
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "p is of type: " << MAGENTA << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "p is of type: " << MAGENTA << "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "p is of type: " << MAGENTA << "C" << RESET << std::endl;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
			std::cout << "p is of type: " << MAGENTA << "A" << RESET << std::endl;
			return;
	}
	catch (const std::exception &e) {}
	try {
		(void)dynamic_cast<B&>(p);
			std::cout << "p is of type: " << MAGENTA << "B" << RESET << std::endl;
			return;
	}
	catch (const std::exception &e) {}
	try {
		(void)dynamic_cast<C&>(p);
			std::cout << "p is of type: " << MAGENTA << "C" << RESET << std::endl;
			return;
	}
	catch (const std::exception &e) {}
}