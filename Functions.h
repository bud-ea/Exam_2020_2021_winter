#pragma once
#include <iostream>
#include<vector>
using namespace std;


int num_of_args(vector<bool> f);
vector<bool> read_from_file(string file_name);
bool write_to_file(string file_name, vector<bool> f);
string table(vector<bool> f);

vector<int> func_Pascal(int k);
int func_substr_len(string input_str);
int roman_to_arab(string roman_number);