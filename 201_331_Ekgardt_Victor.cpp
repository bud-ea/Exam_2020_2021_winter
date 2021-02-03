#include <iostream> //ввод вывод
#include <vector> // библиотека для работы с vector
#include "Header1.h" // заголовочный файл с написанным функциями 

using namespace std;

int main()
{
	vector<bool> f = { 0, 1, 0 , 0, 1, 1, 0, 0 };
	vector<bool> f3 = { 0, 1, 0 , 0 };
	cout << num_of_args(f) << endl << endl;

	vector <bool> f1 = read_from_file("D:\\vector.txt");
	for (int i = 0; i < f1.size(); i++) cout << f1[i] << "\t";
	cout << endl << endl;

	if (write_to_file("D:\\vector_w.txt", f));

	cout << table(f) << endl;
}