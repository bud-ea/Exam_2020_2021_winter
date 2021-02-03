#include "Class.h"//подключение h-файла
#include <iostream>//библиотека ввода и вывода
#include <vector> // библиотека работы с vector
using namespace std;//стандартное пространство имен
int main()
{
	vector<bool> vec = { 0, 1, 0 , 0, 1, 1, 0, 0 };
	vector<bool> f3 = { 0, 1, 0 , 0 };
	cout << num_of_args(vec) << endl << endl;

	vector <bool> f1 = read_from_file("C:\\vector.txt");
	for (int i = 0; i < f1.size(); i++) cout << f1[i] << endl;
	cout << endl << endl;

	if (write_to_file("C:\\vector_w.txt", vec));

	cout << table(vec) << endl;
	return 0;
}