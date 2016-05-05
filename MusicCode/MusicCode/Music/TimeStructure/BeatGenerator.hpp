#pragma once
#include <string>
#include <vector>
#include <map>
#include "../../Probability/Distribution.hpp"
#include "../../Utility/INIParser.hpp"


class BeatGenerator
{
public:
	BeatGenerator();
	~BeatGenerator();

	void setINIParser(INIParser& inip);
	void setBeatSpeed(const double& bsp);
	std::string generateRhythm();



private:

	void setupMap();
	void setupDistr();
	void setMapValue(const std::string& nam, const double& tim, const bool& note);

	std::vector<std::string> getSectionNames(const std::string& filename);


	double beatSpeed;

	std::string rhythmPattern;

	Distribution<std::string> rhythmDistr;

	std::map<std::string, std::pair<double, bool> > timeMap;

	INIParser* ip;

};

