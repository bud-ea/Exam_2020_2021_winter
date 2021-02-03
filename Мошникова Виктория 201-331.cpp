#include <iostream>              // cввод и вывод
#include <vector>               // работа с векторами
#include <string>              // работа с С-строками    
#include "func.h"              // описание наших функций из h файла
using namespace std;

const string file = { "D:\\file.txt" };   // расположение файла1
const string file2 = { "D:\\file2.txt" }; // расположение файла2
vector<bool> f;                          // вектор по умолчанию
int main()
{
	setlocale(0, " ");
	f = read_from_file(file);
	bool tr = write_to_file(file2, f);
	int a = num_of_args(f);
	cout << "1 задание: " << a << endl;
	cout << "2 Задание: " tr;
}
