#pragma once
#include <math.h>
#include <windows.h>
#include <time.h>


namespace utility
{
	typedef unsigned int uint;

	uint gcf(uint a, uint b)
	{
		uint c;
		while (b != 0)
		{
			c = a % b;
			a = b;
			b = c;
		}
		return a;
	}

	uint lcm(const uint& a, const uint& b)
	{
		return a * b / gcf(a, b);
	}

	int imax(const int& a, const int& b)
	{
		if (a < b)
		{
			return b;
		}
		return a;
	}

	int imin(const int& a, const int& b)
	{
		if (a > b)
		{
			return b;
		}
		return a;
	}

	double dmax(const double& a, const double& b)
	{
		if (a < b)
		{
			return b;
		}
		return a;
	}


	double dmin(const double& a, const double& b)
	{
		if (a > b)
		{
			return b;
		}
		return a;
	}


	bool inInterval_i(const int& a, const int& lb, const int& hb)
	{
		return ((a >= lb) && (a <= hb));
	}

	bool inInterval_d(const double& a, const double& lb, const double& hb)
	{
		return ((a >= lb) && (a <= hb));
	}


	int iclamp(const int& val, const int& lbound, const int& hbound)
	{
		if (val < lbound)
		{
			return lbound;
		}
		else if (val > hbound)
		{
			return hbound;
		}
		return val;
	}


	double dclamp(const double& val, const double& lbound, const double& hbound)
	{
		if (val < lbound)
		{
			return lbound;
		}
		else if (val > hbound)
		{
			return hbound;
		}
		return val;
	}

	bool isNearAbs(const double& a, const double& b, const double& error)
	{
		return (fabs(a - b) < error);
	}

	bool isNearPercent(const double& observed, const double& theoretical, const double& error)
	{
		return ((fabs(observed - theoretical) / theoretical)  < error);
	}

	int randInt()
	{
		srand(time(NULL));
		return rand();
	}

	int randInt(const int& lo, const int& hi)
	{
		srand(time(NULL));
		return rand() % (hi - lo + 1) + lo;
	}

	double randUnitDouble()
	{
		srand(time(NULL));
		return rand() / ((float)(RAND_MAX));
	}

	double randDouble()
	{
		return randInt() + randUnitDouble();
	}


	std::vector<std::string> spiltStringAtSubstring(std::string bigstr, const std::string& substr)
	{
		if (substr.size())
		{
			for (uint i = 0; i < bigstr.size(); i++)
			{
				if (bigstr[i] == substr[0])
				{
					bool same = true;
					for (uint k = 1; k < substr.size(); k++)
					{

						if (bigstr[imin(i + k, bigstr.size() - 1)] != substr[k])
						{
							same = false;
						}
					}
				}
			}
		}
		else
		{

		}
	}

	

}
