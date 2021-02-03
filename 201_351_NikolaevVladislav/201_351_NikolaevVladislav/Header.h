#pragma once
#include <iostream>
#include <vector>//подключаем векторы для работы с ними
#include <string>//подключаем строки для работы с ними
#include <fstream>//подключаем библиотеку файлового ввода и вывода
#include <bitset>//подключал для работы с переводом в двоичное представление чисел, пока нигде не используется, но мб в будущем
//по итогу битсет не нужен, но удалять не стал, так как мало ли вам важно состояние моего кода на момент конца первой части экзамена
//юзинги для простоты написания
using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::endl;
using std::ifstream;
using std::ofstream;
///part 1
int num_of_args(std::vector<bool> f);
std::vector<bool> read_from_file(std::string file_name);
bool write_to_file(std::string file_name, std::vector<bool> f);
std::string table(std::vector<bool> f);

//////part 2
std::vector<int> func_Pascal(int n);
int roman_to_arab(std::string roman_number);
int func_substr_len(std::string input_str);
void update_status(bool* mas);