#include "Class.h"
#include <vector>
#include <string>

int num_of_args(std::vector<bool>f)
{
	return log2(f.size());
}

std::string table(std::vector <bool> f)
{
	std::string table;
	int argNum = num_of_args(f);
	for (int i = 1; i <= argNum; i++)
	{
		table += "x" + std::to_string(i) + "\t";
	}

	return table;
}

/*vector <bool> read_from_file(std::string file_name)
{

}

bool write_to_file(std::string file_name, vector<bool> f)
{

}

string func_sdnf(std::vector<bool> f)
{

}

string func_sknf(std::vector<bool> f)
{

}

string func_Zhegalkin(std::vector<bool> f)
{

}
*/