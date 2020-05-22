#include <iostream>
#include "Vector.h"
#include "Test.h"
#include "interface.h"

int main()
{
	std::cout << "Choose the type of vector: " << std::endl;
	std::cout << "1.int" << std::endl;
	std::cout << "2.double" << std::endl;

	int choose(0);
	std::cin >> choose;

	if ((choose > 2 ) || (choose < 1))
	{
		std::cout << "Choosed number is wrong" << std::endl;
		exit(1);
	}

	if (choose == 1)
		Interface<int>();
	else
		Interface<double>();

	return 0;
}