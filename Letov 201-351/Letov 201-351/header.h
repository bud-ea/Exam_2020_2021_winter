#pragma once
#include <vector> // вместо массива, для хранения значений
#include <string>	// строки, используется почти во всех заданиях
#include <iostream> // потоки, ввод-ввыод в-из консоль(и)
#include <fstream> // работа с файлами
#include <map> // чтобы перевести римсие в арабские

using std::map; 
using std::reverse; 
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::getline;
using std::fstream;
using std::ifstream;
using std::ofstream;

int num_of_args(vector<bool> f);

std::vector<bool> read_from_file(std::string file_name);

bool write_to_file(std::string file_name, vector<bool> f);

std::string table(vector<bool> f);

std::string func_sdnf(vector<bool> f);

std::string func_sknf(vector<bool> f);

std::string func_Zhegalkin(vector<bool> f);

std::vector<int> func_Pascal(int k);

int func_substr_len(std::string input_str);

int roman_to_arab(std::string roman_number);