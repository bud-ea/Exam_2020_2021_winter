#include "Half1.h" // Forward declaration
#include <fstream> // Used for file stream operations

int num_of_args(std::vector<bool> f)
{
	// 2^x = f.size()
	// log2(f.size()) = x;
	// x is number of arguments of function
	double fLog = log2(f.size());

	// Following code is used to check if size of f is power of 2
	double intpart;
	double fracpart = std::modf(fLog, &intpart);

	// If fractional part is not zero, then f.size isn't power of 2
	if (fracpart != 0.0)
		return 0;

	return (int)fLog;
}

std::vector<bool> read_from_file(std::string file_name)
{
	std::vector<bool> vec;
	std::ifstream in;

	try 
	{
		in.open(file_name);
		if (!in.good()) // checks if file is readable
			return vec;

		// Using istream_iterator for easy and reliable
		// reading of arrays like "0 0 1 0 0 0 1 1"
		std::istream_iterator<bool> start(in), end;

		// Create new vector from stream iterator
		vec = std::vector<bool>(start, end);

		// Surely close file
		in.close();
	}
	catch (const std::exception& e)
	{
		// Handle exception
		printf_s("Error while reading file\n%s\n", e.what());
		return vec;
	}

	return vec;
}

bool write_to_file(std::string file_name, std::vector<bool> f)
{
	std::ofstream out;

	try
	{
		out.open(file_name);
		if (!out.good())
			return false;

		// Loop for each value in f vector
		for (bool b : f)
		{
			// write in read-acceptible format (like as read_from_file)
			out << b << " ";
		}
	}
	catch (const std::exception& e)
	{
		// Handle exception and return false (as declared in exam's task)
		printf_s("Error while writing file\n%s\n", e.what());
		return false;
	}

	// return true on successful read
	return true;
}

std::string table(std::vector<bool> f)
{
	std::string table;
	int argNum = num_of_args(f);

	if (argNum == 0)
		return "Not a valid value set";

	// print table header
	for (int i = 1; i <= argNum; i++)
	{
		table += "x" + std::to_string(i) + "\t";
	}

	table += "f\n";

	// loop for all values of function 
	for (int i = 0; i < f.size(); i++)
	{
		// loop for every row of table
		for (int j = 0; j <= argNum; j++)
		{
			// if we're on function value, just print it to table
			if (j == argNum)
				table += std::to_string(f.at(i));
			else 
				/* 
				Some serious bit math here!

				Basically 'i' variable is a bit set of row of table
				so we're masking it by current column that j var represents
				to obtain useable mask, we need to substract 'j' from arg num
				and pow 2 to its value
				e.g.

				if we're on 3rd row (i = 2), for 3 arguments, row would be 0 1 0
				to obtain bool wariables, we need to bitmask 'i'. Mask would be
				j = 0 : 1 0 0 | 2 & mask == 0
				j = 1 : 0 1 0 | 2 & mask == 1
				j = 2 : 0 0 1 | 2 & mask == 0
				*/
				table += std::to_string((bool)(i & (int) (pow(2, (argNum - j - 1))))) + "\t";
		}
		table += "\n";
	}

	return table;
}

std::string func_sdnf(std::vector<bool> f)
{
	std::string func("f_sdnf(");
	int argNum = num_of_args(f); // obtain number of arguments
	bool hasSFunc = false; // used for handling if function has SDNF

	if (argNum == 0)
		return "Not a valid value set";

	// this loop prints function body, e.g.
	// f_sdnf(x1, x2, x3) = 
	for (int i = 1; i <= argNum; i++)
	{
		func += "x" + std::to_string(i);
		if (i != argNum)
			func += ", ";
	}

	// enclosure for body
	func += ") = ";

	// loop through all values of function
	for (int i = 0; i < f.size(); i++)
	{
		// SDNF is constructed only for true values of function!
		if (f.at(i))
		{
			// notify that function actually has sdnf
			hasSFunc = true;
			func += "(";

			// loop through truth table
			for (int j = 0; j < argNum; j++)
			{
				// same method of obtainig value for an argument used above
				bool arg = (bool)(i & (int)(pow(2, (argNum - j - 1))));

				// handle if argument's value is false
				if (!arg)
					func += "'";

				// just print element of formula
				func += "x" + std::to_string(j + 1);
				if (j != argNum - 1)
					func += " & ";

			}

			func += ") v ";
		}
	}

	// trim 3 chars from the end of string for beaty
	func.replace(func.length() - 3, 3, "");

	return func;
}

// this function works just like as one above, but it's sknf
std::string func_sknf(std::vector<bool> f)
{
	std::string func("f_sknf(");
	int argNum = num_of_args(f);

	if (argNum == 0)
		return "Not a valid value set";

	for (int i = 1; i <= argNum; i++)
	{
		func += "x" + std::to_string(i);
		if (i != argNum)
			func += ", ";
	}

	func += ") = ";

	for (int i = 0; i < f.size(); i++)
	{
		if (!f.at(i))
		{
			func += "(";

			for (int j = 0; j < argNum; j++)
			{
				bool arg = (bool)(i & (int)(pow(2, (argNum - j - 1))));

				if (arg)
					func += "'";

				func += "x" + std::to_string(j + 1);
				if (j != argNum - 1)
					func += " V ";
			}

			func += ") & ";
		}
	}

	func.replace(func.length() - 3, 3, "");

	return func;
}

// meh
std::string func_Zhegalkin(std::vector<bool> f)
{
	return std::string();
}