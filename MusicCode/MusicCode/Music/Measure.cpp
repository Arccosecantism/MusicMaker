#include "Measure.hpp"


Measure::Measure()
{
}


Measure::~Measure()
{
}


void Measure::setTimeSignature(const unsigned int& ts)
{
	timeSignature = ts;
}

void Measure::createMeasure(BeatGenerator& bg)
{

	for (unsigned int i = 0; i < timeSignature; i++)
	{
		beatVec.push_back(bg.generateBeat());
	}
}

void Measure::testMeasure(const double& tempo, const double& spacePercent)
{
	for (unsigned int i = 0; i < beatVec.size(); i++)
	{
		beatVec[i].testBeat(tempo, spacePercent);
	}
}

std::vector<std::pair<double, bool>> Measure::getDurations()
{
	std::vector<std::pair<double, bool>> retVec;
	for (unsigned int i = 0; i < beatVec.size(); i++)
	{
		std::vector<std::pair<double, bool>> beatDurations = beatVec[i].getDurations();
		for (unsigned int k = 0; k < beatDurations.size(); k++)
		{
			retVec.push_back(beatDurations[k]);
		}
	}
	return retVec;
}