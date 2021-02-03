#include "Header.h"
vector <bool> tt()
{
	int k;
	int p;
	cout << "Введитe вектор: ";
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> p;
		tt().push_back(p);
	}
	cout << "Количество аргументов: " << pow(2, tt().size()) << endl;
	return vector<bool>();
}
vector<bool> read_from_file(std::string file_name)
{
	setlocale(LC_ALL, "RUS");

	vector <bool> read_from_file;
	bool bool1;

	ifstream in;
	in.open("D://file_name.txt");

	while (in >> bool1) {
		read_from_file.push_back(bool1);
	}

	for (int i = 0; i < read_from_file.size(); i++) {
		cout << read_from_file[i];
		return vector<bool>();
	}
}
