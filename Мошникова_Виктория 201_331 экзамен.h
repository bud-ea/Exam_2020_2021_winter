#include <iostream> // ввод вывод
#include <vector>    // работа с векторами
#include <math.h>    // мат операции
#include <fstream>   //чтение и запись данных из файла и в него
#include <string>     //работа с С-строками
using namespace std;

int num_of_args(vector<bool> f) {
	int n = log2(f.size());                //степень 2ки
	return n;
}

vector <bool> read_from_file(string file_name) {   // чтение значений из файла
	vector<bool> vec;                          // вектор возвращ
	string str;
	ifstream out(file_name);
	if (!out.is_open()) {
		cout << "Ошибка открытия файла!\n";
	}
	else {
		while (!out.eof()) {                  // цикл для счит значений
			str = "";
			out >> str;
			if (str == "") continue;
			vec.push_back(stoi(str));        // значение в вектор
		}
	}
	out.close(); // закрываем файл
	return vec;
}

bool write_to_file(std::string file_name, vector <bool> f) {
	ofstream in;
	bool v;
	in.open(file_name, ios::app);
	int i;
	for (i = 0; i < f.size() - 1; i++) {
		in << f[i] << " ";
	}
	in << f[i];
	in.close();
	vector <bool> vec;
	vec = read_from_file(file_name);
	if (vec == f) {
		v = true;
	}

	return v;
}


