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
	setupMap();
	setupDistr();
}

void BeatGenerator::setBeatSpeed(const double& bsp)
{
	beatSpeed = bsp;
}

std::string BeatGenerator::generateRhythm()
{
	return rhythmDistr.generateObj();
}


void BeatGenerator::setupMap()
{

	std::vector<std::string> sectionNames = getSectionNames("beat_pattern_elements.ini");


	for (unsigned int i = 0; i < sectionNames.size(); i++)
	{
		ip->setSection(sectionNames[i]);
		setMapValue(sectionNames[i], ip->getValue<double>("duration"), ip->getValue<bool>("sound"));
	}

}

void BeatGenerator::setupDistr()
{
	std::vector<std::string> sectionNames = getSectionNames("beat_patterns.ini");

	for (unsigned int i = 0; i < sectionNames.size(); i++)
	{
		ip->setSection(sectionNames[i]);
		rhythmDistr.addRelativeChance(ip->getValue<unsigned int>("rarity"), sectionNames[i]);
	}

}

void BeatGenerator::setMapValue(const std::string& nam, const double& tim, const bool& note)
{
	timeMap[nam] = std::make_pair(tim, note);
}


std::vector<std::string> BeatGenerator::getSectionNames(const std::string& filename)
{
	ip->readINI(filename);
	ip->setSection("SectionNames");

	const unsigned int elementNumber = ip->getValue<int>("size");
	const std::string prekey = ip->getValue<std::string>("keyName");

	std::vector<std::string> sectionNames;

	std::string tmpSectionName = "";

	for (unsigned int i = 0; i < elementNumber; i++)
	{
		tmpSectionName = prekey + boost::lexical_cast<std::string>(i);
		sectionNames.push_back(ip->getValue<std::string>(tmpSectionName));
	}

	return sectionNames;
}