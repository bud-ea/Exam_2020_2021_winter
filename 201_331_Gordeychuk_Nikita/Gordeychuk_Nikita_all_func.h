#pragma once
#include <iostream>
//#include <vector>
//#include <string>
#include <fstream> //работа с файлами
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
std::string table(std::vector <bool> f) {
	std::string answ_task_4 = "x1\tx2\tx3\tx4\tF\n";
	std::string x1 = "0000000011111111";
	std::string x2 = "0000111100001111";
	std::string x3 = "0011001100110011";
	std::string x4 = "0101010101010101";
	std::string F;
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
