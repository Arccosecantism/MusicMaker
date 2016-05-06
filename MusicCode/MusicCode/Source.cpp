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
	utility::seedRand();

	//Beep(440, 1000);
	INIParser parser;
	parser.setDirectory("INI_Files");
	BeatGenerator testBeatGenerator;
	testBeatGenerator.setBeatSpeed(.7);
	testBeatGenerator.setSpacePercent(.1);
	std::cout << "xxcHere1" << std::endl;
	testBeatGenerator.setINIParser(parser);
	std::cout << "xxcHere2" << std::endl;
	Beat tBeat = testBeatGenerator.generateBeat();
	tBeat.testBeat();
	std::cout << "xxcHere3" << std::endl;



	while (true);

	return 0;

}
