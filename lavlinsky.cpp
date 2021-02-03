#include <iostream> // потоковый вывод в консоль	
#include <locale.h> // для кириллицы
#include <vector> // библиотека векторов 
#include <fstream> // для файлового ввода/вывода
#include <string> // для строк
#include <ctime> // для рандома
using namespace std;

// определение степени двойки
int get_power2(int n)
{
	int power = 0;
	while (n % 2 == 0)
	{
		n /= 2;
		power++;
	}

	return power;
}


int num_of_args(vector<bool> v)
{
	int vector_lengh = 0; // длинна вектора
	bool temp = 0; // временная переменная

	cout << "Введите длинну вектора ";
	cin >> vector_lengh;

	for (int i = 0; i < vector_lengh; i++)
	{
		cin >> temp;
		v.push_back(temp); // вносим значение от пользователя в массив
	}

	return pow(2, v.size()); // возвращаем размер массива
}

vector<bool> read_from_file(string file_name)
{
	ifstream read_from_file(file_name); // открываем файл от пользователя
	vector<bool> reading_vector;
	bool buffer;

	while (read_from_file >> buffer)
	{
		reading_vector.push_back(buffer);
	}

	return reading_vector; // вовзращаем вектор с файла
}

bool write_to_file(string file_name, vector<bool> f)
{
	file_name += ".txt"; // формат файла
	ofstream write_to_file;
	write_to_file.open(file_name, ios_base::out); // перезапись

	// обработка ошибки записи
	if (write_to_file.fail())
	{
		cout << "Ошибка при записи файла!" << endl;
		return false;
	}
	else
	{
		for (int i : f)
		{
			write_to_file << f[i] << " "; // запись пр одному элементу
		}
		return true;
	}

}

string func_sdnf(vector<bool> f)
{
	string func = "";

	int tableSize = f.size(); // длинна массива
	int numBitLength = get_power2(tableSize); // проверка степени двойки

	bool hasAnyFunc = false;

	for (int i = 0; i < tableSize; i++)
	{
		if (f[i]) // если 1
		{
			if (i > 0 && hasAnyFunc) func += " v ";

			hasAnyFunc = true;

			func += "(";

			int binary = i;
			string inverse = "\0"; // инвертация

			for (int x = 0; x < numBitLength; x++) // отрисовка
			{
				if (binary % 2 == 0) inverse = "\'";
				binary /= 2;

				func += inverse + "x" + to_string(x + 1);

				if (x + 1 < numBitLength) func += " & ";
			}

			func += ")";
		}
	}

	return func;
}



int main()
{
	setlocale(LC_ALL, "RUS");

	bool k = 0;
	int switcher; // для меню
	int vector_lengh = 0;
	string file_path; // для фала
	vector<bool> my_vector;

	while (true)
	{
		cout << "Дествия:" << endl;
		cout << "1 По заданному вектору значений f булевой функции возвращает количество аргументов n этой функции." << endl;
		cout << "2 По заданному расположению и имени файла file_name вернуть вектор значений булевой функции." << endl;
		cout << "3 Записать заданный вектор значений f булевой функции в файл, заданноый расположением и имененем файла file_name. Вернуть true при успешной записи." << endl;
		cout << "4 По заданному вектору значений f булевой функции вернуть строку, в которой записана таблица истинности этой булевой функции. " << endl;
		cout << "5 По заданному вектору значений f булевой функции вернуть строку, в которой записана СДНФ этой булевой функии." << endl;
		cout << "? Выход" << endl;
		cin >> switcher;

		switch (switcher)
		{

		case 1:
			cout << "Размер вектора " << num_of_args(my_vector) << endl;
			cout << endl;
			break;

		case 2:
			cout << "Введите полный путь до файла ";
			cin >> file_path;
			my_vector = read_from_file(file_path);


			cout << "v = ";
			for (int i : my_vector) // выполнять пока не закончится вектор
			{
				cout << i << " ";
			}
			cout << endl;
			break;

		case 3:
			cout << "Введите название файла ";
			cin >> file_path;

			cout << "Введите длинну вектора ";
			cin >> vector_lengh;

			for (int i = 0; i < vector_lengh; i++)
			{
				cin >> k; // ввод значений по одному
				my_vector.push_back(k);
			}
			write_to_file(file_path, my_vector);
			break;

		case 4:
			cout << "Введите длинну вектора ";
			cin >> vector_lengh;

			for (int i = 0; i < vector_lengh; i++)
			{
				cin >> k; // ввод значений по одному
				my_vector.push_back(k);
			}
			// func_table(my_vector); доделать надо
			break;
		case 5:
			srand(time(0)); // для рандомных значений

			for (int i = 0; i < 5; i++)
			{
				int n = 1 + (i / 4);// вектор должен быть кратен степени 2
				for (int i = 0; i < pow(2, n); i++)
				{
					my_vector.push_back(rand() % 2); // рандомим 1 или 0
					cout << my_vector[i];
				}
				cout << endl;

				string s = func_sdnf(my_vector);

				cout << s << "\n-------------------------------------\n";
			}
			break;

		default:
			return 0;
		}
	}
}