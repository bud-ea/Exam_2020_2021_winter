#pragma once
#include <vector> //по заданию
#include <cmath> // математика для логарифма
#include <string> //строки
#include <fstream> //запись-чтение в файл
#include <bitset> //работа с битами для таблици истиности

int num_of_args(std::vector<bool> f);

std::vector<bool> read_from_file(std::string file_name);

bool write_to_file(std::string file_name, std::vector<bool> f);

std::string table(std::vector<bool> f);