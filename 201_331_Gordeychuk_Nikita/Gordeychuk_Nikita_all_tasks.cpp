#include <iostream>
#include <vector>
#include <string>
#include "Gordeychuk_Nikita_all_func.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	cout << "____________________ÇÀÄÀÍÈÅ 1_________________________" << endl;
	int answ_task_1;
	vector <bool> task_1 = { 0, 0, 1, 1 };
	answ_task_1 = num_of_arguments(task_1);
	cout << answ_task_1 << endl;
	cout << "____________________ÇÀÄÀÍÈÅ 2_________________________" << endl;
	string read_file_name = "read_bool_vector.txt";
	vector <bool> answ_task_2 = read_from_file(read_file_name);
	for (auto data : answ_task_2) {
		cout << data << ' ';
	}
	cout << endl;
	cout << "____________________ÇÀÄÀÍÈÅ 3_________________________" << endl;
	string write_file_name = "write_bool_vector.txt";
	vector <bool> f = { 0, 0, 0, 0, 1, 1, 1, 1 };
	cout << write_to_file(write_file_name, f);
	cout << endl;
	cout << "____________________ÇÀÄÀÍÈÅ 4_________________________" << endl;
	/*vector <bool> task_4 = { 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1 };
	string answ_task_4 = table(task_4);
	cout << answ_task_4 << endl;*/
	cout << "____________________ÇÀÄÀÍÈÅ 5_________________________" << endl;
	vector <bool> f_sdnf = { 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1 };
	string str_task_5 = func_sdnf(f_sdnf);
	cout << str_task_5 << endl;
	cout << "____________________ÇÀÄÀÍÈÅ 6_________________________" << endl;
	vector <bool> f_sknf = { 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1 };
	string str_task_6 = func_sknf(f_sknf);
	cout << str_task_6 << endl;
	cout << "____________________ÇÀÄÀÍÈÅ 8_________________________" << endl;
	string roman_arab_str = "MCMXCIV";
	cout << roman_to_arab(roman_arab_str) << endl;
	cout << "____________________ÇÀÄÀÍÈÅ 9_________________________" << endl;
	int k = 4;
	vector <int> task_9 = func_Pascal(k);
	for (auto i : task_9) {
		cout << i << ' ';
	}
	cout << endl;
	cout << "____________________ÇÀÄÀÍÈÅ 10_________________________" << endl;
	string task_10_str = "abcabcbb";
	cout << func_substr_len(task_10_str) << endl;
	return 0;
}