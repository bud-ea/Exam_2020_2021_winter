#include "Funcs.h"

int num_of_args(std::vector<bool> f) //функция подсчета количества аргументов функции
{
	return std::log(f.size()) / std::log(2);
}

std::vector<bool> read_from_file(std::string file_name) //функция для чтения вектора значений из файла
{
		std::vector<bool> result;
		std::ifstream file(file_name);
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


bool write_to_file(std::string file_name, std::vector<bool> f) //функция вывода вектора значений функции в файл
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
	else 
	{
		return false;
	}
}

std::string table(std::vector<bool> f)		//функция вывлда таблицы истинности
{
	int cols = num_of_args(f);
	std::string result;
	std::string buf;
	int counter = 0;
	for (int i = 0; i < f.size(); i++)
	{
		int j = i;
		counter = 0;
		while (j != 0 || counter < cols)
		{
			buf.append(std::to_string(j % 2));
			j /= 2;
			counter++;
		} 
		std::reverse(buf.begin(), buf.end());
		result.append(buf + ' ' + std::to_string(f[i]) + '\n');
		buf.clear();
	}
	return result;
}

std::string func_sdnf(std::vector<bool> f);

std::string func_sknf(std::vector<bool> f);

std::string func_Zhegalkin(std::vector<bool> f);