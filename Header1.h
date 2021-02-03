#pragma once
#include <vector> //векторы
#include <string> //с строки
using namespace std;
int num_of_args(vector<bool> f);
vector<bool> read_from_file(std::string file_name);
bool write_to_file(std::string file_name, vector<bool> f);
int roman_to_arab(std::string roman_number);
int func(string input_string);
vector<int> func_Pascal(int k);