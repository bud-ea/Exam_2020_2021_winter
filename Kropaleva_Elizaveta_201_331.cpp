#include <iostream>
#include <vector> // библиотека для работы с vector
#include "Bool_functions.h" // заголовочный файл с написанным функциями 

using namespace std;

int main()
{
	vector<bool> f = { 0, 1, 0 , 0, 1, 1, 0, 0 };
	cout << num_of_args(f) << endl;
	vector <bool> f1 = read_from_file("D:\\vector.txt");
	int size = read_from_file("D:\\vector.txt").size();
	for (int i = 0; i < size; i++) cout << f1[i] << endl;
}
