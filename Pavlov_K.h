#pragma once
#include <iostream>// библиотека вводавывода
#include <vector>// библиотека для подключения контейнера вектор
#include <string>// библиотека для работы с с++ строками
#include <fstream> // библиотека для работы с файлами
#include <unordered_set>// библиотека для подключения неупорядоченного множества
using namespace std;
//____________________Zadanie1_________________________
int num_of_args(std::vector <bool> f) {
	int n = 0;// колличество элементов 
	while (pow(2, n) != f.size())
		n++;
	return  n;
	
}
//____________________Zadanie2_________________________
vector <bool> read_from_file(std::string file_name) {
	ifstream file;
	vector <bool> output;
	string str;
	file.open(file_name);
	getline(file, str, '\0');
	file.close();
	for (auto ch : str) {
		output.push_back(ch);
	}
	return output;
}
//____________________Zadanie3_________________________
bool write_to_file(std::string file_name, std::vector <bool> f) {
	std::ofstream file;
	file.open(file_name);
	if (!file) {
		return false;
	}
	for (auto data : f) {
		file << data << ' ';
	}
	file.close();
	return true;
}
//____________________Zadanie4_________________________
string table(std::vector <bool> f) {
	string answ_task_4 = "x1\tx2\tx3\tx4\tF\n";
	string x1 = "0000000011111111";
	string x2 = "0000111100001111";
	string x3 = "0011001100110011";
	string x4 = "0101010101010101";
	string F;
	for (auto num : f) {
		F += char(num);
	}
	for (int i = 0; i < 16; i++) {
		answ_task_4 += char(x1[i]);
		answ_task_4 += '\t';
		answ_task_4 += char(x2[i]);
		answ_task_4 += '\t';
		answ_task_4 += char(x3[i]);
		answ_task_4 += '\t';
		answ_task_4 += char(x4[i]);
		answ_task_4 += '\t';
		answ_task_4 += char(F[i]);
		answ_task_4 += '\n';
	}
	return answ_task_4;
}
//____________________Zadanie5_________________________
string func_sdnf(std::vector <bool> f) {
	string answ;
	int x1[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 };
	int x2[16] = { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1 };
	int x3[16] = { 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1 };
	int x4[16] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };
	for (int i = 0; i < 16; i++) {
		if (f[i] == 1) {
			if (x1[i] == 0) {
				answ += "'x1";
				answ += "&";
			}
			else if (x1[i] == 1) {
				answ += "x1";
				answ += "&";
			}
			if (x2[i] == 0) {
				answ += "'x2";
				answ += "&";
			}
			else if (x2[i] == 1) {
				answ += "x2";
				answ += "&";
			}
			if (x3[i] == 0) {
				answ += "'x3";
				answ += "&";
			}
			else if (x3[i] == 1) {
				answ += "x3";
				answ += "&";
			}
			if (x4[i] == 0) {
				answ += "'x4";
			}
			else if (x4[i] == 1) {
				answ += "x4";
			}
			if (i < 15) {
				answ += " V ";
			}
		}
	}
	return answ;
}
//____________________Zadanie6_________________________
string func_sknf(std::vector <bool> f) {
	string answ;
	int x1[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 };
	int x2[16] = { 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1 };
	int x3[16] = { 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1 };
	int x4[16] = { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 };
	for (int i = 0; i < 16; i++) {
		if (f[i] == 0) {
			if (x1[i] == 1) {
				answ += "'x1";
				answ += "V";
			}
			else if (x1[i] == 0) {
				answ += "x1";
				answ += "V";
			}
			if (x2[i] == 1) {
				answ += "'x2";
				answ += "V";
			}
			else if (x2[i] == 0) {
				answ += "x2";
				answ += "V";
			}
			if (x3[i] == 1) {
				answ += "'x3";
				answ += "V";
			}
			else if (x3[i] == 0) {
				answ += "x3";
				answ += "V";
			}
			if (x4[i] == 1) {
				answ += "'x4";
			}
			else if (x4[i] == 0) {
				answ += "x4";
			}
			if (i < 15) {
				answ += " & ";
			}
		}
	}
	return answ;
}
//____________________Zadanie8_________________________
int roman_to_arab(std::string roman_number)
{
	int result = 0;
	for (int i = 0; i < roman_number.length(); i++)
	{
		if (roman_number[i] == 'M')
			result += 1000;
		if (roman_number[i] == 'C' && roman_number[i + 1] == 'M')
		{
			result += 900;
			i++;
		}
		if (roman_number[i] == 'D')
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
//____________________Zadanie8_________________________
int C(int m, int n) {
	int fact_n = 1;
	int fact_m = 1;
	int fact_n_m = 1;
	for (int i = 1; i <= n; i++) {
		fact_n *= i;
	}
	for (int i = 1; i <= m; i++) {
		fact_m *= i;
	}
	for (int i = 1; i <= (n - m); i++) {
		fact_n_m *= i;
	}
	return fact_n / (fact_m * fact_n_m);
}
vector <int> func_Pascal(int k) {
	vector <int> result;
	for (int i = 0; i < k + 1; i++) {
		result.push_back(C(i, k));
	}
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i];
	}
	return result;
}
	//____________________Zadanie9_________________________
	int func(std::string input_string)
	{
		unordered_set<int> u;
		int counter;
		int max = 0;
		for (size_t i = 0; i < input_string.length(); i++) {
			counter = 0;
			size_t j = i + 1;
			u.clear();
			while (true) {
				if (j < input_string.length() and u.find(input_string[j]) == u.end()) {
					u.insert(input_string[j]);
					counter++;
					j++;
				}
				else {
					if (counter > max) {
						max = counter;
					}
					break;
				}
			}
		}
		return max;
	}