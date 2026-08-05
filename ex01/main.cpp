#include "Data.hpp"
#include "Serializer.hpp"

#define RESET	"\033[0m"
#define MAGENTA	"\033[35m"

int	main(void) {
	Data	data = {1, "Manon"};

	std::cout << MAGENTA << "Before serialization: " << RESET << std::endl;
	std::cout << data.name << std::endl;
	std::cout << data.nb << std::endl;
	std::cout << &data << std::endl;

	std::cout << MAGENTA << "After serialization: " << RESET << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << raw << std::endl;

	std::cout << MAGENTA << "Deserialization: " << RESET << std::endl;
	Data* back= Serializer::deserialize(raw);
	std::cout << back->name << std::endl;
	std::cout << back->nb << std::endl;
	std::cout << back << std::endl;

	return (0);
}