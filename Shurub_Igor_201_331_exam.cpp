﻿// Shurub_Igor_201_331_exam.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Header.h"
#include <iostream>// для ввода выода и простейших операций
#include <string>// использование строк
#include <fstream>// для работы с файлом
#include <vector> // для работы с вектором
using namespace std;
/*int main()
{
	setlocale(LC_ALL, "RUS");

	vector <bool> read_from_file;
	bool bool1;

	ifstream in;
	in.open("D://file_name.txt");

	while (in >> bool1) {
		read_from_file.push_back(bool1);
	}

	for (int i = 0; i < read_from_file.size(); i++) {
		cout << read_from_file[i];
	}
	return 0;
}
*/
/*
int main()
{
	using namespace std;

	setlocale(LC_ALL, "RUS");

	vector <bool> tt;

	int n;
	int p;
	cout << "Введите размер вектора: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p;
		tt.push_back(p);
	}

		cout << "Количество аргументов: " << pow(2, tt.size()) << endl;

		return 0;
}
*/


/*int main()
{
	setlocale(LC_ALL, "RUS");
	f();
	return 0;
}
*/
/*
int main()
{
	std::ofstream out;          // поток для записи
	out.open("D:\\file_name.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		out << "1 0 1 0 1" << std::endl;
		cout << "true";
	}
	return 0;
}
*/
//По заданному вектору 
//значений f булевой функции 
//вернуть строку, в 
//которой записана СДНФ этой булевой функии.
/*
int main() 
{
	setlocale(LC_ALL, "RUS");
	vector <bool> f;
	int size = 3;
	bool el;
	cout << "Функция ";
	for (int i = 0; i < size; i++) {
		cin >> el;
		f.push_back(el);
	}
	bool x0 = f.at(0), x1 = f.at(1), x2 = f.at(2);//Возвращает ссылку на элемент в указанном месте с проверкой границ.
	unsigned int m = pow(2, size);
	cout << " x0 " << "x1 " << " x2 " << " СДНФ " << endl;
	cout << " " << x0 << "  " << x1 << "  " << x2 << " " << " --- " << (!x0 || x1 || !x2) && (!x0 || x1 || x2) && (x0 || !x1 || x2) && (x0 || x1 || x2);
}
*/
// По заданному вектору значений f булевой функции вернуть строку,	
//в которой записана СКНФ этой булевой функии. 
//Считать, что имена аргументов это х1, х2, х3, х4 и 
//Конъюнкция обозначается&, дизъюнкция V, отрицание '
/*
int main()
{
setlocale(LC_ALL, "RUS");
vector <bool> f;
int size = 3;
bool el;
cout << "Функция ";
for (int i = 0; i < size; i++) {
	cin >> el;
	f.push_back(el);
}
bool x0 = f.at(0), x1 = f.at(1), x2 = f.at(2);//Возвращает ссылку на элемент в указанном месте с проверкой границ.
int m = pow(2, size);
cout << " x0 " << "x1 " << " x2 " << " СKНФ " << endl;
cout << " " << x0 << "  " << x1 << "  " << x2 << " " << " --- " <<  (!x0 && !x1 && !x2) || (!x0 && x1 && !x2) || (x0 && x1 && x2) || (x0 && x1 && !x2);
}
*/
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
