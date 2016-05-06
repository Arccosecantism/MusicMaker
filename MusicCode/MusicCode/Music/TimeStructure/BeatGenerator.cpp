#include "BeatGenerator.hpp"


BeatGenerator::BeatGenerator()
{

}


BeatGenerator::~BeatGenerator()
{
}

void BeatGenerator::setINIParser(INIParser& inip)
{
	ip = &inip;
	setupDistr();
}

void BeatGenerator::setSpacePercent(const double& sperc)
{
	spacePercent = sperc;
}

void BeatGenerator::setBeatSpeed(const double& bsp)
{
	beatSpeed = bsp;
}

Beat BeatGenerator::generateBeat()
{
	std::string randstr = rhythmDistr.generateObj();
	Beat newBeat;
	newBeat.setupMap(*ip);
	newBeat.setBeatDuration(beatSpeed);
	newBeat.setSpacePercent(spacePercent);
	newBeat.createBeat(randstr);
	return newBeat;
}


void BeatGenerator::setupDistr()
{
	std::vector<std::string> sectionNames = utility::getSectionNames("beat_patterns.ini", *ip);

	for (unsigned int i = 0; i < sectionNames.size(); i++)
	{
		ip->setSection(sectionNames[i]);
		rhythmDistr.addRelativeChance(ip->getValue<unsigned int>("rarity"), sectionNames[i]);
	}

}