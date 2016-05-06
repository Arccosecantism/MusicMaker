#pragma once
#include "TimeStructure\BeatGenerator.hpp"

class Measure
{
public:
	Measure();
	~Measure();

	void setTimeSignature(const unsigned int& ts);

	void createMeasure(BeatGenerator& bg);
	void testMeasure(const double& tempo, const double& spacePercent);

	std::vector<std::pair<double, bool>> getDurations();

private:

	unsigned int timeSignature;
	std::vector<Beat> beatVec;
};

