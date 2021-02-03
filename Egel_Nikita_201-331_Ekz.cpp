#include <iostream>
#include <vector>		// библиотека для работы с vector
#include <string>		// библиотека для работы с с++ строками
#include "Zad1.h"	// заголовочный файл с написанным функциями; 

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");


				// Первое задание
	vector<bool> f = { 0, 1, 0 , 0, 1, 1, 0, 0 };
	cout << num_of_args(f) << endl;
	vector <bool> f1 = read_from_file("D:\\tester.txt");
	int size = read_from_file("D:\\tester.txt").size();
	cout << endl;



				// Второе задание
	// Римские числа
	string roman_number;
	getline(cin, roman_number);
	cout << "Введено: MCMXCIV" << endl;
	cout << roman_to_arab("MCMXCIV") << endl;

	// Треугольник Паскаля
	cout << "введите число k для треугольника Паскаля: k = 4" << endl;
	int k = 4;
	func_Pascal(k);
	cout << endl;

	// Строки
	cout << func_substr_len("ffffff");


	return 0;
}
