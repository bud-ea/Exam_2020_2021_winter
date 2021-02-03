#pragma once
#include <iostream>//ждя ввода вывода
#include <bitset> //описывает тип объекта, который хранит последовательность, состоящую из фиксированного числа битов
#include <fstream> // для работы с файлами
#include <vector> // для создания вектора
#include <cmath> // для функции pow
#include <string> // для работы со строками
#include <map> // отсортированный ассоциативный контейнер    
#include <set> //для хранения символов в контейнере

using namespace std;


int num_of_args(vector<bool> f);
vector<bool> read_from_file(string file_name);
bool write_to_file(string file_name, vector<bool> f);
string table(vector<bool> f);
string func_sdnf(vector<bool> f);
int roman_to_arab(std::string roman_number);
vector<int> func_Pascal(int k);
double fact(double num);
int func_substr_len(std::string input_str);