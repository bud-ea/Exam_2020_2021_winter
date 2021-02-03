#include "Bool_functions.h"
#include <fstream> //библиотека для работы с fstream
#include <bitset> //библиотека для работы с двоичным представлением
#include <set> //библиотека для работы с set

struct num {
	char roman;
	int arab;
};

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

/*индекс в векторе database для текущего значения*/
int index_database(char roman_number) {
	vector <num> database = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
	for (int j = 0; j < 7; j++) 
		if (roman_number == database[j].roman) return j;
}

/*Во входной строке записано римское число, не превышающее трех тысяч. Необходимо вернуть записать его в арабской.*/
int roman_to_arab(std::string roman_number) {
	int arab_number = 0;
	vector <num> database = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} }; // вектор со значениями для перевода 
	for (int i = 0; i < roman_number.length(); i++) {
			int cur_index = index_database(roman_number[i]); // индекс в векторе database для текущего значения
			if (i < roman_number.length() - 1 && database[cur_index].arab < database[index_database(roman_number[i + 1])].arab) arab_number -= database[cur_index].arab; 
			else arab_number += database[cur_index].arab;
	}

	return arab_number;
}

/*Треугольник Паскаля*/
std::vector<int> func_Pascal(int k) {
	vector <int> rez(k + 1, 0); //вектор длины k, заполненный 0
	rez[0] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = i; j >= 1; j--)
			rez[j] = rez[j - 1] + rez[j]; // сумма 2 чисел над текущим числом
	
	return rez;
};

/* По заданной строке input_str вернуть число, равное размеру самой длинной подстроки, которая не содержит повторяющихся символов.*/
int func_substr_len(std::string input_str) {
	set<char> letter; // множество, которое хранит уникальные буквы
	int size_set = 0, max = 0; 
	for (int i = 0; i < input_str.length(); i++) {
		letter.insert(input_str[i]);
		if (letter.size() > size_set)  // проверка является ли буква повторяющейся
			size_set = letter.size();
		else { 
			if (size_set > max) max = size_set;
			size_set = 0;
			letter.clear();
		}
	}
	if (size_set > max) max = size_set; // обрабатывается случай, когда нужная подстрока в конце

	return max;
}