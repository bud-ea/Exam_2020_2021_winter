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
	string text;
	int var, k;
	vector<bool> f;
	string name;
	while (true) {
		cout << "Первая часть" << endl;
		cout << "Вторая часть" << endl;
		cin >> var;
		int j = 0;
		switch (var) {
		case 1:
			cout << "Введите вектор значений: " << std::endl;
			cin >> znach;
			while (j != znach.size()) {
				f.push_back(znach[j]);
				j++;
			}
			a.num_of_args(f);
			cout << "Введите путь до файла" << endl; //C:\Users\DELL Inspiron\Desktop\file_name.txt
			cin >> name;
			a.read_from_file(name);
			a.write_to_file(name, f);
			a.table(f);
			a.func_sdnf(f);
			a.func_sknf(f);
			a.func_Zhegalkin(f);
			break;
		case 2:
			cout << "Введите текст: " << endl;
			cin >> text;
			cout << "roman_to_arab" 
				<< "func_Pascal" 
				<< "func_substr_len" 
				<< "Выход" << endl;
			cin >> var;
			switch (var){
			case 1:
				a.roman_to_arab(text);
				break;
			case 2:
				cout << "Введите число: " << endl;
				cin >> k;
				a.func_Pascal(k);
				break;
			case 3:
				a.func_substr_len(text);
				break;
			case 4:
				return 0;
			}
			break;
		case 3:
			return 0;
		}
	}
	return 0;
}
