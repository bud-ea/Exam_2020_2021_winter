#include <vector>
#include <iostream>
#include <string>
using namespace std;
#pragma once
int num_of_args (vector<bool> f);
vector<bool> read_from_file(string file_name); 
bool write_to_file(string file_name, vector<bool> f);
std::string table(vector<bool> f);
// вторая часть экзамена 
int roman_to_arab(std::string roman_number);
vector<int>func_Pascal(int k);
