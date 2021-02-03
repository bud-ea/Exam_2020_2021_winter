#pragma once
#include <iostream>
#include <vector>//подключаем векторы для работы с ними
#include <string>//подключаем строки для работы с ними
#include <fstream>//подключаем библиотеку файлового ввода и вывода
#include <bitset>//подключал для работы с переводом в двоичное представление чисел, пока нигде не испольлзуется, но мб в будущем
//юзинги для простоты написания
using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::endl;
using std::ifstream;
using std::ofstream;

int num_of_args(std::vector<bool> f);
std::vector<bool> read_from_file(std::string file_name);
bool write_to_file(std::string file_name, std::vector<bool> f);
std::string table(std::vector<bool> f);