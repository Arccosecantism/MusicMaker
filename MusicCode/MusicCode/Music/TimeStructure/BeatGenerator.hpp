#pragma once
#include <string>
#include <vector>
#include <map>
#include "../../Probability/Distribution.hpp"
#include "Beat.hpp"


class BeatGenerator
{
public:
	BeatGenerator();
	~BeatGenerator();

	void setINIParser(INIParser& inip);
	void setSpacePercent(const double& sperc);
	void setBeatSpeed(const double& bsp);
	Beat generateBeat();



private:

	void setupDistr();
	

	std::vector<std::string> getSectionNames(const std::string& filename);


	double beatSpeed;
	double spacePercent;

	std::string rhythmPattern;

	Distribution<std::string> rhythmDistr;

	

	INIParser* ip;

};

