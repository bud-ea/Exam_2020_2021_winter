#include "Class1.h" //Связь с файлом .h
#include <string> //Библиотека строк
#include <fstream> //Библиотека работы с файлами
#include <sstream>
#include <bitset> 

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int num_of_args(std::vector<bool> f)
{
	int num;
	cout << "Введите вектор значений функции с точкой на конце: ";
	while (cin >> num)
		f.push_back(num);
	int answer1;
	answer1 = log(f.size()) / log(2);
	cout << "Ответ: " << answer1;
	return answer1;
}

vector<bool> read_from_file(std::string file_name)
{
	cout << "Введите расположение файла";
	cin >> file_name;
	std::vector < bool > answer2; //Создаём вектор
	std::ifstream file(file_name);
	std::copy(std::istream_iterator<bool>(file), std::istream_iterator<bool>(), std::back_inserter(answer2)); //Записываем значения в вектор
	return answer2;
}

bool write_to_file(std::string file_name, vector<bool> f)
{
	std::ofstream file(file_name);
	std::copy(f.begin(), f.end(), std::ostream_iterator<bool>(file)); //Записываем значения в вектор
	return true;
}

std::string table(std::vector<bool> f) {
	std::string buf;
	for (int i = 0; i < f.size(); i++)
	{
		std::bitset<4> bit(i);
		buf = buf + bit.to_string() + "\t" + std::to_string(f[i]) + "\n";
	}

	return buf;
}

std::string func_sdnf(std::vector<bool> f) {
	std::ostringstream out;
	int y = num_of_args(f) + 1;
	int n = f.size();
	for (int i = 0; i < n; i++) {
		int r = f.back();
		f.pop_back();
		if (r == 1) {
			int* t = dec2bin(i, y);
			out << "(";
			for (int j = 0; j < y; j++) {
				if (t[j] == 0) {
					if (j + 1 == y) {
						out << "x" << j  << '\'';
					}
					else {
						out << "x" << j <<'\'' << '&';
					}
				}
				if (t[j] == 1) {
					if (j + 1 == y) {
						out << "x" << j;
					}
					else {
						out << "x" << j << '&';
					}
				}
			}
			if (i + 1 == n) {
				out << ")";
			}
			else {
				out << ")v";
			}
		}
	}
	return out.str();
}

std::string func_sknf(std::vector<bool> f) {
	std::ostringstream out;
	int y = num_of_args(f) + 1;
	int n = f.size();
	for (int i = 0; i < n; i++) {
		int r = f.back();// берем значение функции
		f.pop_back();
		if (r == 0) {
			int* t = dec2bin(i, y);// число в двоичной записи
			out << "(";
			for (int j = 0; j < y; j++) {
				if (t[j] == 0) {
					if (j + 1 == y) {
						out << "x" << j << '\'';
					}
					else {
						out << "x" << j << '\'' << 'v';
					}
				}
				if (t[j] == 1) {
					if (j + 1 == y) {
						out << "x";
						out << j;
					}
					else {
						out << "x" << j << 'v';
					}
				}
			}
			if (i == n) {
				out << ")";
			}
			else {
				out << ")&";
			}
		}
	}
	return out.str();
}

int* dec2bin(int num, int size) {
	int* bin = new int[size] {0};
	int* bin_r = new int[size];
	int j = 0;
	while (num)
	{
		bin[j] = (num % 2);
		num /= 2;
		j++;
	}
	for (int i = 0; i < size; i++) {
		bin_r[size - i - 1] = bin[i];
	}
	return bin_r;
}