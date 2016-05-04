#include "Beat.hpp"


Beat::Beat()
{



}


Beat::~Beat()
{
}

void Beat::setINIParser(INIParser& inip)
{
	ip = &inip;
}

void Beat::setBeatSpeed(const double& bsp)
{
	beatSpeed = bsp;
}

void Beat::generateRhythm()
{

}


void Beat::setupMap()
{
	
	ip->readINI("beat_pattern_elements.ini");
	ip->setSection("Names");

	const unsigned int elementNumber = ip->getValue<int>("size");
	const std::string prekey = ip->getValue<std::string>("keyName");

	std::vector<std::string> sectionNames;

	std::string tmpSectionName = "";
	for (unsigned int i = 0; i < elementNumber; i++)
	{
			tmpSectionName = prekey + boost::xorabl
	}

}

void Beat::setupDistr()
{
	rhythmDistr.addRelativeChance(2, "Q");
	rhythmDistr.addRelativeChance(3, "E,E");
	rhythmDistr.addRelativeChance(3, "S,S,S,S");
	rhythmDistr.addRelativeChance(4, "E,S,S");
	rhythmDistr.addRelativeChance(4, "S,S,E");
	rhythmDistr.addRelativeChance(6, "S,E,S");
	rhythmDistr.addRelativeChance(4, "dE,S");
	rhythmDistr.addRelativeChance(5, "S,dE");

	rhythmDistr.addRelativeChance(5, "S,dE");
	rhythmDistr.addRelativeChance(5, "S,dE");
	rhythmDistr.addRelativeChance(5, "S,dE");
	rhythmDistr.addRelativeChance(5, "S,dE");
	rhythmDistr.addRelativeChance(5, "S,dE");
	rhythmDistr.addRelativeChance(5, "S,dE");
	rhythmDistr.addRelativeChance(5, "S,dE");
}

void Beat::setMapValue(const std::string& nam, const double& tim, const bool& note)
{
	timeMap[nam] = std::make_pair(tim, note);
}