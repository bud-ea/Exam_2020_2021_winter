#include "BolleanFunc.h"

int num_of_args(std::vector<bool> f)
{
	return ceil(log2(f.size())); //округление в большую логарифма с основанием 2
}

std::vector<bool> read_from_file(std::string file_name)
{
	std::string bufLine;
	std::vector<bool> resultVector;

	std::ifstream inputStream(file_name);
	if (inputStream.is_open())
	{
		while (std::getline(inputStream, bufLine))
		{
			for (int i = 0; i < bufLine.size(); i++) //перебираем полученную из файла строку
			{
				if (bufLine[i] == '0') resultVector.push_back(false);
				else resultVector.push_back(true);
			}
		}
	}

	return resultVector;
}

bool write_to_file(std::string file_name, std::vector<bool> f)
{
	std::ofstream outputStream(file_name, std::ios::out);
	if (outputStream.is_open())
	{
		for (auto i : f)
		{
			outputStream << i; //использу€ поток вывода пишем вектор в файл
		}
		return true;
	}
	else
	{
		return false;
	}
}

std::string table(std::vector<bool> f)
{
	std::string bufStr;
	for (int i = 0; i < f.size(); i++)
	{
		std::bitset<8> bit(i); //преобразуем int в битовое представление
		bufStr = bufStr + bit.to_string() + "\t" + std::to_string(f[i]) + "\n";
	}

	return bufStr;
}