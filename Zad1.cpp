#include <fstream> //библиотека для работы с fstream
#include <iostream>
#include "Zad1.h"

/* По заданному вектору значений f булевой функции возвращает количество аргументов n этой функции. Длина вектора f есть pow(2,n). */
int num_of_args(vector<bool> f) {
	int size = f.size(), n = 0; // size - длина вектора функции, n - количество аргументов функции
	while (size > 1) {          //цикл для определения степени 2 числа
		size /= 2;
		n++;
	}
	return n;
}

/* По заданному расположению и имени файла file_name вернуть вектор значений булевой функции vector<bool>*/
vector<bool> read_from_file(std::string file_name)
{
	vector <bool> f;
	fstream fs;								//создание объекта при работе в С++
	string str;
	fs.open(file_name, std::fstream::in);  //открытие файла, на чтение 
	getline(fs, str);					   // считывание строки с вектором

	for (int i = 0; i < str.length(); i += 2) {
		f.push_back((bool)str[i]);
		
	}

	fs.close();
	return f;
}

/*Записать заданный вектор значений f булевой функции в файл, заданноый расположением и имененем файла file_name. Вернуть true при успешной записи.*/
bool write_to_file(std::string file_name, vector<bool> f) {
	fstream fs;								//создание объекта при работе в С++
	fs.open(file_name, std::fstream::out);  //открытие файла, режим: на запись
	if (fs.fail()) return false;

	for (int i = 0; i < f.size(); i++) fs << f[i] << " ";

	fs.close();

	return true;
}