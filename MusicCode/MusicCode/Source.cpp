#include "Probability\Distribution.hpp"
#include "Utility\INIParser.hpp"
#include "Music\Measure.hpp"



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
	testBeatGenerator.setINIParser(parser);

	for (int i = 0; i < 10; i++)
	{
		Measure testMeasure;
		testMeasure.setTimeSignature(4);
		testMeasure.createMeasure(testBeatGenerator);
		testMeasure.testMeasure(1, .1);
	}



	while (true);

	return 0;

}
