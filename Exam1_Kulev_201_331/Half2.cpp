#include "Half2.h"
#include "StringExt.h"
#include <map> // To implement conversions from Roman numbers to Arabic

using Misc::StrExt;

int roman_to_arab(std::string roman_number)
{
	int arabic = 0;

	// Typical Roman numbers
	std::map<std::string, int> romanNums =
	{
		{"I", 1},
		{"V", 5},
		{"X", 10},
		{"L", 50},
		{"C", 100},
		{"D", 500},
		{"M", 1000}
	};

	// Untypical Roman numbers
	std::map<std::string, int> romanExpressions =
	{
		{"IV", 4},
		{"IX", 9},
		{"XL", 40},
		{"XC", 90},
		{"CD", 400},
		{"CM", 900}
	};

	// Firstly, we need to find all "expressive" numbers
	for (auto kvp : romanExpressions) 
	{
		size_t occurences = StrExt::ReplaceAll(roman_number, kvp.first, "");

		arabic += occurences * kvp.second;
	}

	// And then typical ones
	for (auto kvp : romanNums)
	{
		size_t occurences = StrExt::ReplaceAll(roman_number, kvp.first, "");

		arabic += occurences * kvp.second;
	}

	return arabic;
}

std::vector<int> func_Pascal(int k)
{
	return std::vector<int>();
}
