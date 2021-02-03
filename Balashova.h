#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int num_of_args(vector<bool> f);
vector<bool> read_from_file(string file_name);
bool write_to_file(string file_name, vector<bool> f);
string table(vector<bool> f);
string func_sdnf(vector<bool> f);
string func_sknf(vector<bool> f);
string func_Zhegalkin(vector<bool> f);
