#include "Funcs.h"

int num_of_args(std::vector<bool> f)
{
	return std::log(f.size()) / std::log(2);
}

std::vector<bool> read_from_file(std::string file_name)
{
		std::vector<bool> result;
		std::ifstream file(file_name, std::ios::in);
		if (file.is_open()) {
			while (!file.eof()) 
			{
				bool buf;
				file >> buf;
				result.push_back(buf);
			}
		}
		return result;
}


bool write_to_file(std::string file_name, std::vector<bool> f)
{
	std::ofstream output;
	output.open(file_name, std::ofstream::out);
	if (output.is_open()) {
		for (int i = 0; i < f.size(); i++)
		{
			output << f[i];
			if (i != f.size() - 1)
			{
				output << ' ';
			}
		}
		
		return true;
	}
	else {
		return false;
	}
}

std::string table(std::vector<bool> f);

std::string func_sdnf(std::vector<bool> f);

std::string func_sknf(std::vector<bool> f);

std::string func_Zhegalkin(std::vector<bool> f);