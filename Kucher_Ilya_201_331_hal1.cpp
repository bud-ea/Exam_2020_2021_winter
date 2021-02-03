#include "Kucher_Ilya_201_331_hal1.h"
#include <vector> // библиотека для подключения вектора
#include <iostream> // библиотека вводавывода
#include <string> // библиотека для работы с с++ строками
#include <fstream> // библиотека для работы с файлами
#include <unordered_set> // библиотека для подключения неупорядоченного множества

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

int roman_to_arab(std::string roman_number)
{
	int result = 0;
	for (int i = 0; i < roman_number.length(); i++)
	{
		if (roman_number[i] == 'M')
			result += 1000;
		if (roman_number[i] == 'C' && roman_number[i+1] == 'M')
		{
			result += 900;
			i++;
		}
		if (roman_number[i] == '‎D')
			result += 500;
		if (roman_number[i] == 'C' && roman_number[i + 1] == 'D')
		{
			result += 400;
		i++;
		}
		if (roman_number[i] == 'C')
			result += 100;
		if (roman_number[i] == 'X' && roman_number[i + 1] == 'C')
		{
			result += 90;
			i++;
		}
		if (roman_number[i] == 'L')
			result += 50;
		if (roman_number[i] == 'X' && roman_number[i + 1] == 'L')
		{
			result += 40;
		i++;
		}
		if (roman_number[i] == 'X')
			result += 10;
		if (roman_number[i] == 'I' && roman_number[i + 1] == 'X')
		{
			result += 9;
		i++;
		}
		if (roman_number[i] == 'V')
			result += 5;
		if (roman_number[i] == 'I' && roman_number[i + 1] == 'V')
		{
			result += 4;
		i++;
		}
		if (roman_number[i] == 'I')
			result += 1;
	}
	return result;
}

int C(int m, int n) //вспомогательная функция для func_Pascal (считает число в строке слева направо)
{
	int fact_n = 1;
	int fact_m = 1;
	int fact_n_m = 1;
	for (int i = 1; i <= n; i++) 
	{
		fact_n *= i;
	}
	for (int i = 1; i <= m; i++) 
	{
		fact_m *= i;
	}
	for (int i = 1; i <= (n - m); i++) 
	{
		fact_n_m *= i;
	}
	return fact_n / (fact_m * fact_n_m);
}

std::vector <int> func_Pascal(int k) 
{
	std::vector <int> result;
	for (int i = 0; i < k + 1; i++) 
	{
		result.push_back(C(i, k));
	}
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i];
	}
	return result;
}

int func_substr_len(std::string input_str)
{
	std::unordered_set <int> longstr;
	int counter;
	int maxstr = 0;
	for (int i = 0; i < input_str.length(); i++) 
	{
		counter = 0;
		int j = i + 1;
		longstr.clear();
		while (true) 
		{
			if (j < input_str.length() && longstr.find(input_str[j]) == longstr.end()) 
			{
				longstr.insert(input_str[j]);
				counter++;
				j++;
			}
			else
			{
				if (counter > maxstr) 
				{
					maxstr = counter;
				}
				break;
			}
		}
	}
	return maxstr;
}
