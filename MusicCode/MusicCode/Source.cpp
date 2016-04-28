#include "Probability\Distribution.hpp"



int main()
{
	Distribution<int> myDistr;

	myDistr.addRelativeChance(1, 1);
	myDistr.addRelativeChance(10, 10);
	myDistr.addRelativeChance(3, 3);

	std::cout << myDistr.generateObj();

	while (true);

	return 0;

}
