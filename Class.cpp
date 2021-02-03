#include "Class.h"
#include <fstream> 
#include <iostream>
#include <bitset>
int num_of_args(std::vector<bool> f)//По заданному вектору значений f булевой функции возвращает количество аргументов n этой функции. Длина вектора f есть pow(2,n).
{
	return (int)log2(f.size());;
}

vector<bool> read_from_file(std::string file_name)// По заданному расположению и имени файла file_name вернуть вектор значений булевой функции vector<bool>
{
	vector <bool> f;
	fstream fs; 
	string str;
	fs.open(file_name, std::fstream::in);  //открытие файла на чтение 
	getline(fs, str); // считывание строки

	for (int i = 0; i < str.length(); i += 2) {
		if (str[i] == '1') f.push_back(1);
		else f.push_back(0);
	}

	fs.close();
	return f;
}
bool write_to_file(std::string file_name, vector<bool> f) { //Записать заданный вектор значений f булевой функции в файл, заданноый расположением и имененем файла file_name. Вернуть true при успешной записи.
	fstream fs;  
	fs.open(file_name, std::fstream::out);  //открытие файла на запись
	if (fs.fail()) return false;
	for (int i = 0; i < f.size(); i++) fs << f[i] << " ";
	fs.close();
	return true;

}