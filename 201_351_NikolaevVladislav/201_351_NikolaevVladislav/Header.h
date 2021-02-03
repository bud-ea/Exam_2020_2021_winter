#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::endl;
using std::ifstream;
using std::ofstream;

int num_of_args(std::vector<bool> f);
std::vector<bool> read_from_file(std::string file_name);
bool write_to_file(std::string file_name, std::vector<bool> f);
std::string table(std::vector<bool> f);