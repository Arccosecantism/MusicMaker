#include "Beat.hpp"


Beat::Beat()
{



}


Beat::~Beat()
{
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
	setMapValue("Q", 1, true);

	setMapValue("E", .5, true);
	setMapValue("dE", .75, true);

	setMapValue("S", .25, true);


	setMapValue("QR", 1, false);

	setMapValue("ER", .5, false);
	setMapValue("dER", .75, false);

	setMapValue("SR", .25, false);

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