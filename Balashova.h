#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//×ÀÑÒÜ 1
int num_of_args(vector<bool> f);
vector<bool> read_from_file(string file_name);
bool write_to_file(string file_name, vector<bool> f);
string table(vector<bool> f);
string func_sdnf(vector<bool> f);
string func_sknf(vector<bool> f);
string func_Zhegalkin(vector<bool> f);

//×ÀÑÒÜ 2
int roman_to_arab(string roman_number);
unsigned long long make_C(int k, int n);
vector<int>func_Pascal(int k);
int func_substr_len(string input_str);