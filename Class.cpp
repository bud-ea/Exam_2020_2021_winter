#include "Class.h"
#include <vector>
#include <string>
#include <fstream>

int num_of_args(std::vector<bool>f)
{
	return log2(f.size());
}

std::string table(std::vector <bool> f)
{
	int count = 0;
	std::string table;
	int argNum = num_of_args(f);
	for (int i = 1; i <= argNum; i++)
	{
		table += "x" + std::to_string(i) + "\t";
	}
	table += "f\n";
    for (int i = 0; i < f.size(); i++)
    {
        for (int j = 0; j <= argNum; j++)
        {
			table += std::to_string(f[count]) + "\t";
			if (count<f.size()-1)
			count++;
        }
        table += "\n";
    }

    return table;
}

std::vector<bool> read_from_file(std::string file_name)
{
	std::ifstream inf(file_name);
	std::vector <bool> f;
	while (inf)
	{
		bool i;
		inf >> i;
		f.push_back(i);
	}
	inf.close();
	return f;
}

bool write_to_file(std::string file_name, std::vector <bool> f)
{
	std::ofstream outf(file_name);
	int i = 0;
	for (int i = 0; i < f.size(); i++)
		outf << f[i] << ' ';
	outf.close();
	return true;
}