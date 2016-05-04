#include "Probability\Distribution.hpp"
#include "Utility\INIParser.hpp"



int main()
{
	//Distribution<int> myDistr;

	//myDistr.addRelativeChance(1, 1);
	//myDistr.addRelativeChance(10, 10);
	//myDistr.addRelativeChance(3, 3);

	//std::cout << myDistr.generateObj();

	INIParser tmptest;
	tmptest.setDirectory("INI_Files");
	tmptest.readINI("test_ini.ini");
	tmptest.setSection("Test_Section");
	std::cout << tmptest.getValue<std::string>("testkey1") << std::endl;
	std::cout << tmptest.getValue<std::string>("testkey2") << std::endl;


	while (true);

	return 0;

}
