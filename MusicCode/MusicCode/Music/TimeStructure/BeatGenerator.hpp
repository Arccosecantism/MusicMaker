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
	Beat generateBeat();



private:

	void setupDistr();
	

	std::vector<std::string> getSectionNames(const std::string& filename);

	std::string rhythmPattern;

	Distribution<std::string> rhythmDistr;


	INIParser* ip;

};

