#include <iostream>
#include <vector> // библиотека для работы с vector
#include "Bool_functions.h" // заголовочный файл с написанным функциями 

using namespace std;

int main()
{
	setlocale(0, "");
	vector<bool> f = { 0, 1, 0 , 0, 1, 1, 0, 0 };
	vector<bool> f3 = { 0, 1, 0 , 0};

	cout << "Количество аргументов в функции (вектор:  0, 1, 0, 0, 1, 1, 0, 0): " << num_of_args(f) << endl;
	cout << "Количество аргументов в функции (вектор:  0, 1, 0, 0): " << num_of_args(f3) << endl << endl;

	cout << "Вектор значений булевой функции из файла: ";
	vector <bool> f1 = read_from_file("D:\\vector.txt");
	for (int i = 0; i < f1.size(); i++) cout << f1[i] << "\t";
	cout << endl << endl;

	if (write_to_file("D:\\vector_w.txt", f));

	cout << "Таблица истинности для функции (вектор:  0, 1, 0, 0, 1, 1, 0, 0):" << endl << table(f) << endl;
	cout << "Таблица истинности для функции (вектор:  0, 1, 0, 0):" << endl << table(f3) << endl;

	cout << "Перевод из римской записи числа в арабскую: " << endl;
	cout << "III" << " - " << roman_to_arab("III") << endl;
	cout << "IV" << " - " << roman_to_arab("IV") << endl;
	cout << "IX" << " - " << roman_to_arab("IX") << endl;
	cout << "LVIII" << " - " << roman_to_arab("LVIII") << endl;
	cout << "MCMXCIV" << " - " << roman_to_arab("MCMXCIV") << endl << endl;

	cout << "5 строка треугольника Паскаля: ";
	vector<int> z = func_Pascal(5);
	for (int i = 0; i < 6; i++)
		cout << z[i] << " ";
	cout << endl << endl;

	cout << "Pазмер самой длинной подстроки без повторяющихся символов: " << endl;
	cout << "Строка 'qqqqqwertyuioooooqazwsxedcrfv': " << func_substr_len("qqqqqwertyuioooooqazwsxedcrfv") << endl;
	cout << "Строка 'abcabcbb': " << func_substr_len("abcabcbb") << endl;
	cout << "Строка 'bbbbb': " << func_substr_len("bbbbb") << endl;
	cout << "Строка 'pwwkew': " << func_substr_len("pwwkew") << endl;
}
