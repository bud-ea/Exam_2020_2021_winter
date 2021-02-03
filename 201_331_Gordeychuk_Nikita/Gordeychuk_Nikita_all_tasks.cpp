#include <iostream>
#include <vector>
#include <string>
#include "Gordeychuk_Nikita_all_func.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	//____________________ÇÀÄÀÍÈÅ 1_________________________
	int answ_task_1;
	vector <bool> task_1 = { 0, 0, 1, 1 };
	answ_task_1 = num_of_arguments(task_1);
	cout << answ_task_1 << endl;
	//____________________ÇÀÄÀÍÈÅ 2_________________________
	string read_file_name = "read_bool_vector.txt";
	vector <bool> answ_task_2 = read_from_file(read_file_name);
	for (auto data : answ_task_2) {
		cout << data << ' ';
	}
	//____________________ÇÀÄÀÍÈÅ 3_________________________
	string write_file_name = "write_bool_vector.txt";
	vector <bool> f = { 0, 0, 0, 0, 1, 1, 1, 1 };
	cout << write_to_file(write_file_name, f);
	cout << endl;
	//____________________ÇÀÄÀÍÈÅ 4_________________________
	vector <bool> task_4 = { 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1 };
	string answ_task_4 = table(task_4);
	cout << answ_task_4 << endl;
	//____________________ÇÀÄÀÍÈÅ 5_________________________
	vector <bool> f_sdnf = { 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1 };
	string str_task_5 = func_sdnf(f_sdnf);
	cout << str_task_5 << endl;
	//____________________ÇÀÄÀÍÈÅ 6_________________________
	vector <bool> f_sknf = { 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1 };
	string str_task_6 = func_sknf(f_sknf);
	cout << str_task_6 << endl;
	return 0;
}