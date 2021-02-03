#pragma once
#include <fstream> //работа с файлами
#include <set>
int num_of_arguments(std::vector <bool> f) {
	int len = f.size();
	int answ;
	while (len / 2 > 1) {
		len /= 2;
		answ = len;
	}
	return answ;
}
std::vector <bool> read_from_file(std::string file_name) {
	std::ifstream file;
	std::vector <bool> output;
	std::string str;
	file.open(file_name);
	getline(file, str, '\0');
	file.close();
	for (auto ch : str) {
		output.push_back(ch);
	}
	return output;
}
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
/*std::string table(std::vector <bool> f) {
	std::string answ_task_4 = "x1\tx2\tx3\tx4\tF\n";
	std::string x1 = "0000000011111111";
	std::string x2 = "0000111100001111";
	std::string x3 = "0011001100110011";
	std::string x4 = "0101010101010101";
	std::string F;
	for (auto num : f) {
		if (num) {
			num = 1;
		}
		else {
			num = 0;
		}
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
} */
std::string func_sdnf(std::vector <bool> f) {
	std::string answ;
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
std::string func_sknf(std::vector <bool> f) {
	std::string answ;
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
std::vector <int> func_Pascal(int k) {
	std::vector <int> result;
	for (int i = 0; i < k + 1; i++) {
		result.push_back(C(i, k));
	}
	return result;
}
int func_substr_len(std::string input_str) {
	std::set <int> unique_list;
	int counter;
	int max = 0;
	for (int i = 0; i < input_str.length(); i++) {
		counter = 0;
		int j = i;
		unique_list.clear();
		while (true) {
			if (j < input_str.length() and unique_list.find(input_str[j]) == unique_list.end()) {
				unique_list.insert(input_str[j]);
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
