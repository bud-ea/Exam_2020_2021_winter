#pragma once
#include <iostream>
#include <vector> //nyzshen vector po zadaniu
#include <string> //rabota so strokami
#include <fstream> //tak kak rabota s failami
using namespace std;


int num_of_args(vector<bool> f);
vector<bool> read_from_file(string file_name);
bool write_to_file(string file_name, vector<bool> f);
string table(vector<bool> f);
