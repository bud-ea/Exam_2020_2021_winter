#include <iostream> // потоковый вывод в консоль	
#include <locale.h> // для кириллицы
#include <vector> // библиотека векторов 
#include <fstream> // для файлового ввода/вывода
#include <string> // для строк
#include <ctime> // для рандома
using namespace std;

int get_power2(int n)
{
	int power = 0;
	while (n % 2 == 0)
	{
		n /= 2;
		power++;
	}

	return power;
}// определение степени двойки
string to_binary(int num, int signCount)
{
	string binaryNum = "";

	for (int x = 0; x < signCount; x++)
	{
		binaryNum += to_string(num % 2 > 0);
		num /= 2;
	}

	reverse(binaryNum.begin(), binaryNum.end());

	return binaryNum;
}// посимвольно перевод в бинарный вид
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
string func_sknf(vector<bool> f)
{
	string func = "";

	int tableSize = f.size(); // размер таблицы
	int numBitLength = get_power2(tableSize); // кратность к 2ке

	bool hasAnyFunc = false;

	for (int i = 0; i < tableSize; i++)
	{
		if (!f[i]) // если 0
		{
			if (i > 0 && hasAnyFunc) func += " & ";

			hasAnyFunc = true;

			func += "(";

			string bin = to_binary(i, numBitLength);

			for (int x = 0; x < numBitLength; x++) // отрисовка
			{
				string inverse = "\0";

				if (bin[x] == '1') inverse = "\'";

				func += inverse + "x" + to_string(x + 1);

				if (x + 1 < numBitLength) func += " & ";
			}


			func += ")";
		}
	}

	return func;
}
string func_table(vector<bool> f)
{
	string func = "";

	int tableSize = f.size(); // размер таблицы
	int numBitLength = get_power2(tableSize); // кратность двойки

	for (int i = 1; i <= numBitLength; i++)
	{
		func += "x" + to_string(i) + "\t"; // отрисовка
	}
	func += "f\n";

	for (int i = 0; i < tableSize; i++)
	{
		string bin = to_binary(i, numBitLength); // перевод в бинарный тип
		for (int j = 0; j < numBitLength; j++)
		{
			func += bin[j];
			func += '\t';
		}
		func += to_string(f[i]);
		func += "\n";
	}

	return func;
}
//рекурсивное высчитывание сумм
double Cnk(int N, int K)
{
	double Sum = 1;
	for (int i = 1; i <= K; i++)
		Sum *= (N - i + 1) / float(i);
	return Sum;
}
vector<int> func_Pascal(int k)
{
	vector<int> pascal_raw; // для return
	for (int j = 0; j <= k; j++)
	{
		for (int i = 0; i <= j; i++)
		{

			if (j == k)
			{
				pascal_raw.push_back(Cnk(j, i));
			}
		}
	}

	return pascal_raw;
}
int to_arab(char roman)
{
	int arab = 0;

	switch (roman)
	{
	case 'I': arab = 1;
		break;

	case 'V': arab = 5;
		break;

	case 'X': arab = 10;
		break;

	case 'L': arab = 50;
		break;

	case 'C': arab = 100;
		break;

	case 'D': arab = 500;
		break;

	case 'M': arab = 1000;
		break;

	default:
		cout << "Неизвестный символ";
		break;
	}

	return arab;
} //соответствия чисел и символов
int roman_to_arab(string roman)
{
	int romanLength = roman.length();

	int arabNum = 0;

	for (int i = 0; i < romanLength - 1; ++i)
	{
		// посимвольное преобразование
		int num = to_arab(roman[i]);
		int nextNum = to_arab(roman[i + 1]);

		if (num < nextNum) arabNum -= num;
		else arabNum += num;
	}

	arabNum += to_arab(roman[romanLength - 1]);

	return arabNum;
}


int func_substr_len(string input_str)
{
	int str_length = input_str.length();

	int max_length = 0; // макс. длина подстроки

	// цикл для всей строки
	for (int i = 0; i < str_length; i++)
	{
		string substr(1, input_str[i]); // берем i-ый символ как начало новой подстроки

		// цикл для куска строки с i+1 символа
		for (int j = i + 1; j < str_length; j++) // j = i+1 - проверяем не всю строку, а только кусок, начинающийся с позиции i+1 символа
		{
			int substr_length = substr.length();

			bool found_duplicate = false;

			// цикл для текущей подстроки
			for (int k = 0; k < substr_length; k++)
			{
				if (substr[k] == input_str[j]) // проверяем j-ый символ исходной строки на наличие его в подстроке
				{
					found_duplicate = true;

					break;
				}
			}

			if (!found_duplicate) substr += input_str[j]; // добавляем к подстроке новый символ
			else break; // останавливаем цикл для выбора следующего символа как начало подстроки
		}

		// сравниваем длину подстроки с макс. длиной
		if (substr.length() > max_length) max_length = substr.length();
	}


	return max_length;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	bool k = 0;
	int switcher; // для меню
	int vector_lengh = 0;
	string table;
	string file_path; // для фала
	vector<bool> my_vector;
	vector<int> my_vector_integer;
	int n; // для паскаля

	while (true)
	{
		cout << "Дествия:" << endl;
		cout << "1 По заданному вектору значений f булевой функции возвращает количество аргументов n этой функции." << endl;
		cout << "2 По заданному расположению и имени файла file_name вернуть вектор значений булевой функции." << endl;
		cout << "3 Записать заданный вектор значений f булевой функции в файл, заданноый расположением и имененем файла file_name. Вернуть true при успешной записи." << endl;
		cout << "4 По заданному вектору значений f булевой функции вернуть строку, в которой записана таблица истинности этой булевой функции. " << endl;
		cout << "5 По заданному вектору значений f булевой функции вернуть строку, в которой записана СДНФ этой булевой функии." << endl;
		cout << "6 По заданному вектору значений f булевой функции вернуть строку, в которой записана СКНФ этой булевой функии." << endl;
		cout << "7 Римские цифры представляются 7 различными символами: I, V, X, L, C, D и M......." << endl;
		cout << "8 На вход подается неотрицательное число k от 0 до 33 включительно." << endl;
		cout << "9 По заданной строке input_str вернуть число, равное размеру самой длинной подстроки, которая не содержит повторяющихся символов." << endl;
		cout << "10 Выход" << endl;
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
			table = func_table(my_vector);
			cout << table << endl;

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

		case 6:
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

				string s = func_sknf(my_vector);

				cout << s << "\n-------------------------------------\n";
			}
			break;
		case 7:
			cout << roman_to_arab("XXVI");
			cout << endl;
			break;

		case 8:
			cout << "Какую строку из теругольника поскаля вы ходите вывести? ";
			cin >> n;
			my_vector_integer = func_Pascal(n);

			cout << n << " Строка: ";
			for (int i : my_vector_integer) // выполнять пока не закончится вектор
			{
				cout << i << " ";
			}
			cout << endl;
			break;

		case 9:
			cout << "abcabcbb " << func_substr_len("abcabcbb") << endl;
			cout << "bbbbb " << func_substr_len("bbbbb") << endl;
			cout << "pwwkew " << func_substr_len("pwwkew") << endl;
			break;

		case 10:
			cout << "Выход из программы......" << endl;
			return 0;


		default:
			return 0;
		}
	}
}