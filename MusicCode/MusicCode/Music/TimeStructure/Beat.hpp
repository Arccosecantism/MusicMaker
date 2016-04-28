#pragma once
#include <string>
#include <vector>
#include "../../Probability/Distribution.hpp"

class Beat
{
public:
	Beat();
	~Beat();

	void setBeatSpeed(const double& bsp);

	

private:

	double beatSpeed;

	std::vector<std::string> rhythmPattern;

	Distribution<std::string> rhythmDistr;

};

