#include "Beat.hpp"


Beat::Beat()
{
	rhythmDistr.addRelativeChance(2, "Q");
	rhythmDistr.addRelativeChance(3, "E,E");
	rhythmDistr.addRelativeChance(3, "S,S,S,S");
	rhythmDistr.addRelativeChance(4, "E,S,S");
	rhythmDistr.addRelativeChance(4, "S,S,E");
	rhythmDistr.addRelativeChance(6, "S,E,S");
	rhythmDistr.addRelativeChance(4, "dE,S");
	rhythmDistr.addRelativeChance(4, "S,dE");


}


Beat::~Beat()
{
}

void Beat::setBeatSpeed(const double& bsp)
{
	beatSpeed = bsp;
}


