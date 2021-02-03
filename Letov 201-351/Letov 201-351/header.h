#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::getline;
using std::fstream;
using std::ifstream;
using std::ofstream;

int num_of_args(vector<bool> f);

std::vector<bool> read_from_file(std::string file_name);

bool write_to_file(std::string file_name, vector<bool> f);

std::string table(vector<bool> f);

std::string func_sdnf(vector<bool> f);

std::string func_sknf(vector<bool> f);

std::string func_Zhegalkin(vector<bool> f);