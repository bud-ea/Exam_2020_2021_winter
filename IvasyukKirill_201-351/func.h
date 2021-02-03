#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;


int num_of_args(vector<bool> f);
vector<bool> read_from_file(string file_name);
bool write_to_file(string file_name, vector<bool> f);
string table(vector<bool> f);
string func_sdnf(vector<bool> f);