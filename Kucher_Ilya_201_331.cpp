#include <iostream>
#include "Kucher_Ilya_201_331_hal1.h"
#include <vector>
#include <string>


using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	vector <bool> f;
	string file_name("D:\\vec.txt");
	string roman_number;
	string input_str;
	int n = 3, k = 3;
	f.resize(pow(2, n));
	for (int i = 0; i < pow(2, n); i++)
	{
		f[i] = i * 37 % 2;
	}
	for (int i = 0; i < pow(2, n); i++)
	{
		cout << f[i];
	}
	cout << endl << num_of_args(f) << endl;
	cout << table(f) << endl;
	cout << "Введено: MCMXCIV" << endl;
	cout << roman_to_arab("MCMXCIV") << endl;
	cout << "введите число k для треугольника Паскаля: k = 4" << endl;
	func_Pascal(k);
	cout << endl << func_substr_len("pwwkew");
}