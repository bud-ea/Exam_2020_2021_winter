#include <iostream>
#include <vector>
#include <string>
#include "functions.h"
using namespace std;

int main() {
	//____________________ÇÀÄÀÍÈÅ 1_________________________
	int answ_task_1;
	vector <bool> task_1 = { 0, 0, 1, 1 };
	answ_task_1 = num_of_arguments(task_1);
	cout << answ_task_1;
	//____________________ÇÀÄÀÍÈÅ 2_________________________
	string read_file_name = "read_bool_vector.txt";
	vector <bool> answ_task_2 = read_from_file(read_file_name);
	for (auto data : answ_task_2) {
		cout << data << ' ';
	}
	//____________________ÇÀÄÀÍÈÅ 3_________________________
	string write_file_name = "";
	return 0;
}