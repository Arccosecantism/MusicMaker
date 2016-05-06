#include "Beat.hpp"


Beat::Beat()
{



}


Beat::~Beat()
{
}


void Beat::setupMap(INIParser& ip)
{
	std::vector<std::string> sectionNames = utility::getSectionNames("note_durations.ini", ip);


	for (unsigned int i = 0; i < sectionNames.size(); i++)
	{
		ip.setSection(sectionNames[i]);
		setMapValue(sectionNames[i], ip.getValue<double>("duration"), ip.getValue<bool>("sound"));
	}
}


void Beat::createBeat(std::string beatStr)
{
	std::vector<std::string> substrs = utility::spiltAtSubstring(beatStr, ",");

	for (unsigned int i = 0; i < substrs.size(); i++)
	{
		durations.push_back(timeMap[substrs[i]]);
	}
}

void Beat::testBeat(const double& tempo, const double& spacePercent)
{
	for (unsigned int i = 0; i < durations.size(); i++)
	{
		if (durations[i].second)
		{
			double tmpdur[2] = { 1000 * tempo * durations[i].first * (1 - spacePercent), 1000 * tempo * durations[i].first * spacePercent };
			Beep(440, tmpdur[0]);
			Sleep(tmpdur[1]);
		}
		else
		{
			Sleep(1000 * durations[i].first);
		}
	}
}


std::vector<std::pair<double, bool>> Beat::getDurations()
{
	return durations;
}



void Beat::setMapValue(const std::string& nam, const double& tim, const bool& note)
{
	timeMap[nam] = std::make_pair(tim, note);
}