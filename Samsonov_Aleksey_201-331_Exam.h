#pragma once
#include <iostream>// библиотека ввода\вывода
#include <string>// библиотека для работы с с++ строками
#include <fstream>// библиотека для работы с файлами
#include <vector>// библиотека для подключения контейнера вектор
#include <unordered_set>// библиотека для подключения неупорядоченного множества


using namespace std;// чтобы не писать std::


int func_substr_len(string input_string);
int roman_to_arab(std::string roman_number);
int C(int m, int n);
std::vector <int> func_Pascal(int k);
//vector<bool> read_from_file(string file_name);
//bool write_to_file(string file_name, vector<bool> f);
///int num_of_args(std::vector<bool> f);

