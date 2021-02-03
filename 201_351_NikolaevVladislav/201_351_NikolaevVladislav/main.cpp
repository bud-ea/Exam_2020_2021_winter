#include "Header.h"

int main() {
	

	string file_name = "example.txt";
	vector<bool> f = read_from_file(file_name);

	for (int i = 0; i < f.size(); i++) {
		cout << f[i];
	}
	cout << endl;
	cout << num_of_args(f);
	cout << endl << table(f);
	vector<int> result;
	result = func_Pascal(33);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	string ex = ("MCMXCIV");
	
	cout << endl << roman_to_arab(ex);
	string input_str = "pwwkew";
	cout << endl << func_substr_len(input_str);


	return 0;
}
