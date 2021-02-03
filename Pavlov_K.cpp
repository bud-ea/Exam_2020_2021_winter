#include <iostream>// библиотека вводавывода
#include <vector>// библиотека для подключения контейнера вектор
#include <string>// библиотека для работы с с++ строками
#include "Pavlov_K.h"//подключаем класс
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	//____________________Zadanie1_________________________
	cout << "Zadanie1"<<endl;
	int answ_task_1;
	vector <bool> task_1 = { 0, 0, 1, 1 };
	answ_task_1 = num_of_args(task_1);
	cout << answ_task_1 << endl;
	//____________________Zadanie2_________________________
	cout << "Zadanie2" << endl;
	string read_file_name = "read_bool_vector.txt";
	vector <bool> answ_task_2 = read_from_file(read_file_name);
	for (auto data : answ_task_2) {
		cout << data << ' ';
	}
	//____________________Zadanie3_________________________
	cout << "Zadanie3" << endl;
	string write_file_name = "write_bool_vector.txt";
	vector <bool> f = { 0, 0, 0, 0, 1, 1, 1, 1 };
	cout << write_to_file(write_file_name, f);
	cout << endl;
	//____________________Zadanie5_________________________
	cout << "Zadanie5" << endl;
	vector <bool> f_sdnf = { 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1 };
	string str_task_5 = func_sdnf(f_sdnf);
	cout << str_task_5 << endl;
	//____________________Zadanie6_________________________
	cout << "Zadanie6" << endl;
	vector <bool> f_sknf = { 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1 };
	string str_task_6 = func_sknf(f_sknf);
	cout << str_task_6 << endl;
	//____________________Zadanie7_________________________
	cout << "Zadanie7" << endl;
	string roman_number;
	cout << roman_to_arab("MMDCCCXLIX") << endl;
	//____________________Zadanie8_________________________
	cout << "Zadanie8" << endl;
	cout << "число k для треугольника Паскаля = 4 " << endl;
	int k = 4; 
	func_Pascal(k);
	//____________________Zadanie9_________________________
	cout << endl << "Zadanie9" << endl;
	cout << func("djfhvakgxdrg");
	return 0;
}

