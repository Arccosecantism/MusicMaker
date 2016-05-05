#include "Probability\Distribution.hpp"
#include "Utility\INIParser.hpp"
#include "Music\TimeStructure\BeatGenerator.hpp"



int main()
{
	//Distribution<int> myDistr;

	//myDistr.addRelativeChance(1, 1);
	//myDistr.addRelativeChance(10, 10);
	//myDistr.addRelativeChance(3, 3);

	//std::cout << myDistr.generateObj();
	srand(time(NULL));
	std::cout << time(NULL) << std::endl;

	INIParser parser;
	parser.setDirectory("INI_Files");
	BeatGenerator testBeatGenerator;
	testBeatGenerator.setINIParser(parser);
	std::cout << testBeatGenerator.generateRhythm() << std::endl;
	std::cout << testBeatGenerator.generateRhythm() << std::endl;
	std::cout << testBeatGenerator.generateRhythm() << std::endl;



	while (true);

	return 0;

}
