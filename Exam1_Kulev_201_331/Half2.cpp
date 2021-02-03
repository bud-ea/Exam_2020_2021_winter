#include "Half2.h"
#include "StringExt.h"
#include <map> // To implement conversions from Roman numbers to Arabic
#include <set> // to implement store of sequence elements in task 3

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
	std::vector<int> line = { 1, 1 };

	// Use pre-calculated values to reduce script complexity
	switch (k)
	{
	case 0:
		return std::vector<int> { 1 };

	case 1:
		return line;
	}
	
	for (int i = 2; i <= k; i++)
	{
		// Line always starts from 1
		std::vector<int> currentLine = { 1 };

		// This loop calculates next line of triangle except '1' that added forward
		for (int j = 0; j < i - 1; j++)
		{
			currentLine.push_back(line.at(j) + line.at(j + 1));
		}

		// Add 1 to the end of the line
		currentLine.push_back(1);

		// Set line for next loop
		line = currentLine;
	}

	return line;
}

int func_substr_len(std::string input_str)
{
	int longestSeq = 0, currentSeqCounter = 0;
	std::set<char> currentSequence;

	// loop for each char in str
	for (char c : input_str)
	{
		// let us check if element already exist in sequence
		if (!setContains(currentSequence, c))
		{
			// if no, then we're count it
			currentSeqCounter++;
			currentSequence.insert(c); // and put to sequence
		}
		else 
		{
			// or else we're resetting the counter and the sequence
			// Optionally if sequence was long enough, it will written to variable
			longestSeq = currentSeqCounter > longestSeq ? currentSeqCounter : longestSeq;
			currentSeqCounter = 0;
			currentSequence.clear();
		}
	}

	return longestSeq;
}

bool setContains(const std::set<char>& d, char element)
{
	return d.find(element) != d.end();
}
