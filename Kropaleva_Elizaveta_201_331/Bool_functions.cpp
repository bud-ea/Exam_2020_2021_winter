#include "Bool_functions.h"
#include <fstream> //библиотека для работы с fstream
#include <bitset> //библиотека для работы с двоичным представлением

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
		if (str[i] == '1') f.push_back(1);
		else f.push_back(0);
	}

	fs.close();
	return f;
}

/*Записать заданный вектор значений f булевой функции в файл, заданноый расположением и имененем файла file_name. Вернуть true при успешной записи.*/
bool write_to_file(std::string file_name, vector<bool> f) {
	fstream fs;  //создание объекта при работе в С++
	fs.open(file_name, std::fstream::out);  //открытие файла, режим: на запись
	if (fs.fail()) return false;

	for (int i = 0; i < f.size(); i++) fs << f[i] << " ";

	fs.close();

	return true;
}

/* По заданному вектору значений f булевой функции вернуть строку, в которой записана таблица истинности этой булевой функции. */
std::string table(vector<bool> f) {
	string table = "", str, str_1;
	int num_args = num_of_args(f);
	for (int i = 0; i < num_args; i++) table = table + "x" + char(i + 49) + "\t"; // шапка таблицы
	table += "f \n";
	if (num_args == 2) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <2> b(i); // значения переменных
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // добавление промежутков между значениями
			table = table + str + char(f[i] + 48) + "\n"; // формирование строки таблицы с учетом значения функции на данном наборе
		}
	} 
	else if (num_args == 3) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <3> b(i); // значения переменных
			str_1 = b.to_string(); 
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // добавление промежутков между значениями
			table = table + str + char(f[i] + 48) + "\n"; // формирование строки таблицы с учетом значения функции на данном наборе
		}
	}
	else if (num_args == 4) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <4> b(i); // значения переменных
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // добавление промежутков между значениями
			table = table + str + char(f[i] + 48) + "\n"; // формирование строки таблицы с учетом значения функции на данном наборе
		}
	}
	else if (num_args == 5) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <5> b(i); // значения переменных
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // добавление промежутков между значениями
			table = table + str + char(f[i] + 48) + "\n"; // формирование строки таблицы с учетом значения функции на данном наборе
		}
	}
	else if (num_args == 6) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <6> b(i); // значения переменных
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // добавление промежутков между значениями
			table = table + str + char(f[i] + 48) + "\n"; // формирование строки таблицы с учетом значения функции на данном наборе
		}
	}
	else if (num_args == 7) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <7> b(i); // значения переменных
			str_1 = b.to_string(); 
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // добавление промежутков между значениями
			table = table + str + char(f[i] + 48) + "\n"; // формирование строки таблицы с учетом значения функции на данном наборе
		}
	}
	else if (num_args == 9) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <8> b(i); // значения переменных
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // добавление промежутков между значениями
			table = table + str + char(f[i] + 48) + "\n"; // формирование строки таблицы с учетом значения функции на данном наборе
		}
	}
	else if (num_args == 10) {
		for (int i = 0; i < f.size(); i++) {
			str = ""; 
			bitset <9> b(i); // значения переменных
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // добавление промежутков между значениями
			table = table + str + char(f[i] + 48) + "\n"; // формирование строки таблицы с учетом значения функции на данном наборе
		}
	}
	return table;
}