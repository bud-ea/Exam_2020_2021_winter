#pragma once
#include <iostream>
#include <vector>// для решения задач
#include <math.h>// для нахождения логорифма
#include <fstream>// для доступа к файлам
#include <string> // для записи элементов вектора в строку
#include <bitset> // для составления таблицы
#include <map> // словарь 
#include <set> // Для хранения символов в контейнере + повторочные символы не записываются

using namespace std;


int num_of_args(vector<bool> f);
vector<bool> read_from_file(string file_name);
bool write_to_file(std::string file_name, vector<bool> f);
std::string table(vector<bool> f);


int roman_to_arab(std::string roman_number);
std::vector<int> func_Pascal(int k);
double fact(double num);
int func_substr_len(std::string input_str);
