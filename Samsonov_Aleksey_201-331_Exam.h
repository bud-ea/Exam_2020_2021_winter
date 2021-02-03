#pragma once
#pragma once
#include <iostream>//библиотека ввода вывода
#include <string>// для подключения функций со строками
#include <fstream>// работа с файлами
#include <vector>// добавляем контейнер вектор

using namespace std;// чтобы не писать std::
int num_of_args(std::vector<bool> f);
vector<bool> read_from_file(string file_name);
bool write_to_file(string file_name, vector<bool> f);

