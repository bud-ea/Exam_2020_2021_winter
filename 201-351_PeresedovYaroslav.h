#pragma once
#include <vector>
#include <iostream>
#include <cmath> //вычисление логарифма
#include <string>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int num_of_args(vector <bool> f);
vector <bool> read_from_file(string file_name, vector <bool> f);
string advance(string arguments);
string table(vector <bool> f);
string func_sdnf(vector <bool> f);
string func_sknf(vector <bool> f);
