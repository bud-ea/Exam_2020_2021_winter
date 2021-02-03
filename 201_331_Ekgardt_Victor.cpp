#include <iostream>//Ввод-вывод
#include <vector>		// библиотека для работы с vector
#include "Header1.h"		// заголовочный файл с написанным функциями 
#include <cstdlib> // Библиотека для систем


int main() {
	cout <<"Converter "<< roman_to_arab("MCMLXVII") << endl;
	int control = 5;
	cout << "Paskal  ";
	func_Pascal(control);
	cout << endl;
	cout << "Str "<<func("pwwkew") << endl;
	system("pause");
	return 0;
}