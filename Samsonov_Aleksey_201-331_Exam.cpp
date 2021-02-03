#include "Samsonov_Aleksey_201-331_Exam.h"//для подключения h.file

int main() {
//Zadanie 2.1	
	string roman_number;
	getline(cin, roman_number);
	cout << roman_to_arab(roman_number) << endl;
//Zadanie 2.2
cout << "Paskal, k = 4"<<endl;
	func_Pascal(4);
	cout << endl;
//Zadanie 2.3
	cout << func_substr_len("ffahfkksadpe");
////	vector<bool> read_from_file(string file_name);
	//std::vector<bool> vec = { true, false, true, false };
	//printf_s("num_of_args: %d\n", num_of_args(vec));
	return 0;
}