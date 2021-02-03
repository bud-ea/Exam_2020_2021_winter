#pragma once
#include <vector> //по заданию
#include <cmath> //математика для логарифма
#include <string> //строки
#include <fstream> //запись-чтение в файл
#include <bitset> //работа с битами для таблицы истиности
#include <map> //для хранения риских цифр и их аналогов в арабских
#include <set> //для задания на поиск подстроки

int num_of_args(std::vector<bool> f);

std::vector<bool> read_from_file(std::string file_name);

bool write_to_file(std::string file_name, std::vector<bool> f);

std::string table(std::vector<bool> f);

//вторая часть

int roman_to_arab(std::string roman_number);

std::vector<int> func_Pascal(int k);
double fact(double num);

int func_substr_len(std::string input_str);