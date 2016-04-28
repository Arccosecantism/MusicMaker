#pragma once

#include <iostream>

#include <stdlib.h>
#include <string>

#include "windows.h"
#include "winioctl.h"
#include <vector>
#include "../Utility/Utility.hpp"


template<class C>
class Distribution
{

public:

	Distribution()
	{
		distMax = 0;
	}

	void addRelativeChance(const unsigned int& chance, const C& obj)
	{
		probabilities.push_back(chance);
		objVec.push_back(obj);
		intervals.clear();

		unsigned int totLcm = 1;
		for (unsigned int i = 0; i < probabilities.size(); i++)
		{
			totLcm = utility::lcm(totLcm, probabilities[i]);
		}

		unsigned int sum = 0;
		unsigned int oldSum = 0;
		for (unsigned int i = 0; i < probabilities.size(); i++)
		{
			sum += totLcm / probabilities[i];
			intervals.push_back(std::make_pair(oldSum, sum));
			oldSum = sum;
		}
		distMax = sum;
	}



	C generateObj()
	{
		const unsigned int rnum = utility::randInt(0, distMax - 1);

		for (unsigned int i = 0; i < intervals.size(); i++)
		{
			if (utility::inInterval_i(rnum, intervals[i].first, intervals[i].second - 1))
			{
				return objVec[i];
			}
		}

	}


private:



	std::vector<std::pair<unsigned int, unsigned int> > intervals;
	std::vector<C> objVec;
	std::vector<unsigned int> probabilities;
	unsigned int distMax;


};

