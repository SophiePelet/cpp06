
#include "Base.hpp"

int	main(void) {
	srand(time(0));

	Base*	test1 = generate();
	identify(test1);
	identify(*test1);

	Base*	test2 = generate();
	identify(test2);
	identify(*test2);

	Base*	test3 = generate();
	identify(test3);
	identify(*test3);

	Base*	test4 = generate();
	identify(test4);
	identify(*test4);

	delete(test1);
	delete(test2);
	delete(test3);
	delete (test4);
}