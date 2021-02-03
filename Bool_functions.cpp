#include "Bool_functions.h"
#include <fstream> //библиотека для работы с fstream
#include <iostream>

/* По заданному вектору значений f булевой функции возвращает количество аргументов n этой функции. Длина вектора f есть pow(2,n). */
int num_of_args(vector<bool> f) {
	int size = f.size(), n = 0; // size - длина вектора функции, n - количество аргументов функции
	while (size > 1) { //цикл, определяющий степень 2 числа
		size /= 2;
		n++;
	}
	return n;
}

/* По заданному расположению и имени файла file_name вернуть вектор значений булевой функции vector<bool>*/
vector<bool> read_from_file(std::string file_name)
{
	vector <bool> f;
	fstream fs;  //создание объекта при работе в С++
	string str;
	fs.open(file_name, std::fstream::in);  //открытие файла, режим: на чтение 
	getline(fs, str); // считывание строки с вектором

	for (int i = 0; i < str.length(); i += 2) {
		f.push_back((bool)str[i]);
		//cout << str[i] << endl;
	}

	fs.close();
	return f;
}