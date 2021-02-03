#pragma once
#include <iostream> //Ѕиблиотека ввода-вывода
#include <vector> //Ѕиблиотека векторов

using namespace std;
int num_of_args(std::vector<bool> f); //ќбъ€вление функции к заданию 1
vector<bool> read_from_file(std::string file_name); //ќбъ€вление функции к заданию 2
bool write_to_file(std::string file_name, vector<bool> f); //ќбъ€вление функции к заданию 3
std::string table(std::vector<bool> f); //ќбъ€вление функции к заданию 4
std::string func_sdnf(std::vector<bool> f); //ќбъ€вление функции к заданию 5
std::string func_sknf(std::vector<bool> f); //ќбъ€вление функции к заданию 6
int* dec2bin(int num, int size); //‘ункци€ перевода из дес€тичных чисел в двоичные дл€ заданий 5 и 6
std::vector<int> func_Pascal(int k); //ќбъ€вление функции к заданию 9
double fact(double num); //‘ункци€ вычислени€ факториала дл€ задани€ 9
int func_substr_len(std::string input_str); //ќбъ€вление функции к заданию 10
int roman_to_arab(std::string roman_number); //ќбъ€вление функции к заданию 8


