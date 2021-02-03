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
	return 0;
}
