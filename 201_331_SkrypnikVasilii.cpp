#include "Class.h"//подключение файла заголовков
#include <iostream>//библиотека ввода и вывода
#include <vector> // библиотека работы с vector
using namespace std;//стандартное пространство имен
int main()
{	/*
	vector<bool> vec = { 0, 1, 0, 0, 1, 1, 0, 0 };
	vector<bool> f3 = { 0, 1, 0, 0 };
	cout << num_of_args(vec) << endl << endl;
	vector <bool> f1 = read_from_file("C:\\vector.txt");
	for (int i = 0; i < f1.size(); i++) cout << f1[i] << "\t";
	*/
    //Часть 2
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	while (true) {
		cout << endl << "1. Римские числа" << endl << "2. Треугольник Паскаля" << endl << "3. Подстрока" << endl << "4. Выход" << endl << "Введите номер задания: ";
		cin >> choice;

		switch (choice) {
		case 1://римские
		{
			string roman_number;
			cin.ignore();
			getline(cin, roman_number);
			cout << roman_to_arab(roman_number) << endl;
			break;
		}
		case 2://треугольник
		{
			int k;
			cout << "введите число k для треугольника Паскаля: k = ";
			cin >> k;
			func_Pascal(k);
			break;
		}
		case 3://подстроки
		{
			string str_pas;
			cout << "введите строку" << endl;
			cin >> str_pas;
			cout << func_substr_len(str_pas);
			break;
		}
		case 4://выход
		{
			return 0;
		}
		}
	}
	return 0;
}
