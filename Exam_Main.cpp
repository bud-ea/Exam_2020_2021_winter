#include <iostream>
#include "function.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL,"Russian"); //добавляем русский язык в консоль
	string znach;
	function a;
	cout << "Введите вектор значений: " << std::endl;
	cin >> znach;
	vector<bool> f;
	int j = 0;
	while (j != znach.size()) {
		f.push_back(znach[j]);
		j++;
	}
	a.num_of_args(f);
	string name;
	cout << "Введите путь до файла" << endl; //C:\Users\DELL Inspiron\Desktop\file_name.txt
	cin >> name;
	a.read_from_file(name);
	a.write_to_file(name, f);
	a.table(f);
	a.func_sdnf(f);
	a.func_sknf(f);
	a.func_Zhegalkin(f);
	return 0;
}