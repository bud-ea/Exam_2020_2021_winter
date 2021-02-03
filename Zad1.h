#pragma once
#include <vector> 
#include <string> 


using namespace std;

int num_of_args(vector<bool> f);

vector<bool> read_from_file(std::string file_name);

bool write_to_file(std::string file_name, vector<bool> f);