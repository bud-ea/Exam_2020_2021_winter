#include "function.h"
#include <iostream>
#include <vector> //для векторов
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
	//ofstream file(file_name);  //открываем файл
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
	string text;
	return text;
}

std::string function::func_sdnf(vector<bool> f) {
	string text;
	return text;
}

std::string function::func_sknf(vector<bool> f) {
	string text;
	return text;
}

std::string function::func_Zhegalkin(vector<bool> f) {
	string text;
	return text;
}

//ВТОРАЯ ЧАСТЬ ЭКЗАМЕНА

std::string roman_to_arab(std::string roman_number){
	int num = 0; //записываем итоговое арабское число
	for (int i = 0; i < roman_number.size(); i++) {
		if (roman_number[i] == 'I') {
			if ((roman_number[i + 1] == 'I') || (i == (roman_number.size() - 1))) //проверка есть ли после 1 число кроме 1, чтобы добавить именно 1
				num++;
		}
		if (roman_number[i] == 'V') {
			if (roman_number[i - 1] == 'I') //проверка 5
				num = num + 4;
			else
				num = num + 5;
		}
		if (roman_number[i] == 'X') {
			if (roman_number[i - 1] == 'I') //проверка 10
				num = num + 9;
			if ((roman_number[i + 1] != 'L') && (roman_number[i + 1] != 'C')) //подстраховка чтобы не словить лишнего
				num = num + 10;
		}
		if (roman_number[i] == 'L') {
			if ((i != 0) && (roman_number[i - 1] == 'X')) //проверка 50
				num = num + 40;
			else
				num = num + 50;
		}
		if (roman_number[i] == 'C') {
			if ((i != 0) && (roman_number[i - 1] == 'X'))//проверка 100
				num = num + 90;
			if ((roman_number[i + 1] != 'D') && (roman_number[i + 1] != 'M')) //подстраховка чтобы не словить лишнего
				num = num + 100;
		}
		if (roman_number[i] == 'D') {
			if ((i != 0) && (roman_number[i - 1] == 'C'))//проверка 500 
				num = num + 400;
			else
				num = num + 500;
		}
		if (roman_number[i] == 'M') {
			if ((i != 0) && (roman_number[i - 1] == 'C'))//проверка 1000
				num = num + 900;
			else
				num = num + 1000;
		}
	}
	cout << num;
	string text;
	return text;
}

int pasc(int n, int k) {//доп функция чтобы посчитать треугольник паскаля
	return ((n < k) ? 0 : ((k == 0) ? 1 : ((n - k + 1) / int(k) * pasc(n, k - 1)))); // вычисление строки треугольника паскаля
}

std::vector<int> func_Pascal(int k) {
	vector<int> f;
	for (int i = 0; i <= k; i++){
		if (i == k){
			for (int j = 0; j <= i; j++){
				cout << pasc(i, j) << " "; //вывод части треугольника паскаля
			}
		}
	}
	return f;
}

int func_substr_len(std::string input_str) {
	bool p = 1; //для проверки совпадений
	int k = 0; //счетчик совпадений
	int max = k; //максимальная длина без повторений
	vector<char> f; //вектор для 
	for (int i = 0; i < input_str.size(); i++) {
		if (input_str[i] != input_str[i + 1]) {
			k++;
			for (int j = 0; j < f.size(); j++) { //проверка совпадение уже учтенных букв
				if (f[j] == input_str[i])
					p = 0;
			}
			f.push_back(input_str[i]); //добавление новых букв
		}
		else {
			k = 0;
			f.clear(); //очитстить вектор
		}

		if ((k >= max) && (p == 1)) { //замена большего числа
			max = k;
		}
	}
	cout << max;
	return max;
}