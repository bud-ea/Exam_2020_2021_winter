#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
int num_of_arguments(std::vector <bool> f) {
	int len = f.size();
	int answ;
	while (len / 2 > 1) {
		len /= 2;
		answ = len;
	}
	return answ;
}
vector <bool> read_from_file(string file_name) {
	ifstream file;
	vector <bool> output;
	char buff[16];
	file.open(file_name);
	file >> buff;
	output.push_back(buff);
	file.close();
	return output;
}
bool write_to_file(std::string file_name, vector <bool> f) {
	ofstream file;
	file.open(file_name);
	if (!file.is_open) {
		return false;
	}
	for (auto data : f) {
		file << data << ' ';
	}
	file.close();
	return true;
}
