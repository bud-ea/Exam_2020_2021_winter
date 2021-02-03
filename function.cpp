#include "function.h"
#include <iostream>
#include <vector>
#include <string> //для ввода строк
#include <fstream> //для чтения и записи файлов

using namespace std;

int function::num_of_args(vector<bool> f) {
	int n = 0;
	int t = f.size(); //нужен для подсчета n
	for (int i = 0; i < f.size(); i++) {
		while (t != 1) {
			t = t / 2;
			n++;
		}
	}
	cout << "В функции " << n << " элементов" << endl;
	return n;
}

vector<bool> function::read_from_file(std::string file_name) { //C:\Users\DELL Inspiron\Desktop\file_name.txt
	bool p = 0;
	ifstream file(file_name);  //открываем файл по данному нам адресу
	if (!file) { //проверяем, смог открыться файл иль нет
		p = 0;
	}
	else {
		p = 1;
	}
	ofstream file(file_name);  //открываем файл
	string s;
	vector<bool> f;
	while (!file.eof()) { //проверяем, кончился ли файл
		getline(file, s);  //построчно считываем текст
	}
	for (int i = 0; i < s.size(); i++) {
		f.push_back(s[i]); //впихиваем строки в конец вектора
	}
	file.close();  //закрываем файл
	if (p == 0) {
		std::cout << "Ошибка" << std::endl;
	}
	if (p == 1) {
		std::cout << "Вектор значений булевой функции: " << std::endl;
	}
	return f;
}

bool function::write_to_file(std::string file_name, vector<bool> f) {
	bool p = 0;
	ifstream file(file_name);  //открываем файл по данному нам адресу
	if (!file) { //проверяем, смог открыться файл иль нет
		p = 0;
	}
	else {
		p = 1;
	}
	ofstream filecopy(file_name);  //открываем файл
	string s;
	int i = 0;
	while (i != f.size()) { //проверяем, кончился ли вектор
		filecopy << f[i]; //впихиваем вектор в файл
		i++;
	}
	file.close();  //закрываем файл
	if (p == 0) {
		std::cout << "Ошибка" << std::endl;
	}
	if (p == 1) {
		std::cout << "Значение перенесено" << std::endl;
	}
	return 0;
}

std::string function::table(vector<bool> f) {

	return 0;
}

std::string function::func_sdnf(vector<bool> f) {

	return 0;
}

std::string function::func_sknf(vector<bool> f) {
	
	return 0;
}

std::string function::func_Zhegalkin(vector<bool> f) {

	return 0;
}