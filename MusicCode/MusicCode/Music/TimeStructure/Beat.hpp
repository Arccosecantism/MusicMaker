#pragma once
#include <string>
#include <vector>
#include <map>
#include "../../Probability/Distribution.hpp"
#include "../../Utility/INIParser.hpp"


class Beat
{
public:
	Beat();
	~Beat();

	void setINIParser(INIParser& inip);
	void setBeatSpeed(const double& bsp);
	void generateRhythm();

	

private:

	void setupMap();
	void setupDistr();
	void setMapValue(const std::string& nam, const double& tim, const bool& note);



	double beatSpeed;

	std::string rhythmPattern;

	Distribution<std::string> rhythmDistr;

	std::map<std::string, std::pair<double, bool> > timeMap;

	INIParser* ip;

};

