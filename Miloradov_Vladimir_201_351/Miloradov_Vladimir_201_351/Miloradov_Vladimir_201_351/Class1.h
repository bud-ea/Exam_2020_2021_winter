#pragma once
#include <iostream> //Ѕиблиотека ввода-вывода
#include <vector> //Ѕиблиотека векторов

using namespace std;
int num_of_args(std::vector<bool> f); //ќбъ€вление функции к заданию 1
vector<bool> read_from_file(std::string file_name);
bool write_to_file(std::string file_name, vector<bool> f);
string table(std::vector<bool> f);
string func_sdnf(std::vector<bool> f);
string func_sknf(std::vector<bool> f);
int* dec2bin(int num, int size);


