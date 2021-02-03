
#include <iostream>//стандартная библиотека ввода - вывода
#include <vector>//добавление библиотеки вектора
#include "Funcions.h"//добавление функций h файла в программу
#include <string>// добавление библиотеки string
#include <iterator>//библиотека управления значениями для вектора

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	/*
	//возврат количество аргументов n функции f (task 1)
	
	vector<bool>f={0};
	bool fun;
	int n;
	while (true) {
		cin >> fun;
		f.push_back(fun);
	}
	num_of_args(f, n);
	cout <<"Length of vector ="<< pow(2, n);
	

	//записать вектор значений в файл(task 3)
	
	vector<bool> f = { 0,1,0,1,0 };
	string file_names;
	vector<bool>::iterator it;
	for (*it = f.begin();; it++) {

	}
	



	//по вектору вывести таблицу истиности (task 4)
	int n = 4;
	bool *arr = new bool[n];
	string file_name=("0 1 0 1");
	string x1, x2, x3, x4;
	
	for (int i = 0; i < n; i++){
		
	}

	delete[] arr;
	*/

	
	//Часть 2
	
	//перевести римские цифры в арабские
	char roman_number[100]{};
	int number=0;
	int n;

	cout << "Enter lot of number: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter I,V,X,L,C,D or M";
		cin >> roman_number[i];
		roman_to_arab(roman_number[i], n);//смена числа
		number = number+roman_number[i];
	}
	cout << number;

	//треугольник Паскаля
	int k;
	cout << "Enter number: ";
	cin >> k;
	fun_paskal(k);//вывод k строки
	
}