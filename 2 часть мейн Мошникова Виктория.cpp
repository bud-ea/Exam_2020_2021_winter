#include <iostream>
#include <vector>  // используем для работы с vector
#include "ekz.h"   //заголовочный файл h с функциями 
#include <cstdlib> // используем для систем 

int main() 
{ 
	setlocale(LC_ALL, "Russian");           // можем пвыводить на русском
	int k = 4;                              //строчка для паскаля
	string roman_number;                        //для перевода римских
	getline(cin, roman_number);                    //для перевода римских
	cout << roman_to_arab(roman_number) << endl;       //для перевода римских
	cout << func("hhhhh") << endl;                     //задание 3, строчка, которую смотрят
	cout << "введите число k для треугольника Паскаля: k = 4" << endl;   // строчка паскаля
	func_Pascal(k);   //     ТРЕУГОЛЬНИК ПАСКАЛЯ
	return 0;
}