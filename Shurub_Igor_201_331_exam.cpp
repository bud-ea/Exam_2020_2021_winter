// Shurub_Igor_201_331_exam.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Header.h"
#include <iostream>// для ввода выода и простейших операций
#include <string>// использование строк
#include <fstream>// для работы с файлом
#include <vector> // для работы с вектором
#include<ctime>// для автоматического заполнения
using namespace std;

/*int main()
{
	setlocale(LC_ALL, "RUS");

	vector <bool> read_from_file;
	bool n;

	ifstream in;
	in.open("D://file_name.txt");

	while (in >> n) {
		read_from_file.push_back(n);
	}

	for (int i = 0; i < read_from_file.size(); i++) {
		cout << read_from_file[i];
	}
	return 0;
}
*/
/*
int main()
{
	using namespace std;

	setlocale(LC_ALL, "RUS");

	vector <bool> tt;

	int n;
	int p;
	cout << "Введите размер вектора: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p;
		tt.push_back(p);
	}

		cout << "Количество аргументов: " << pow(2, tt.size()) << endl;

		return 0;
}
*/


/*int main()
{
	setlocale(LC_ALL, "RUS");
	f();
	return 0;
}
*/
/*
int main()
{
	std::ofstream out;          // поток для записи
	out.open("D:\\file_name.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		out << "1 0 1 0 1 1" << std::endl;
		cout << "true";
	}
	return 0;
}
*/
//По заданному вектору 
//значений f булевой функции 
//вернуть строку, в 
//которой записана СДНФ этой булевой функии.
/*
int main() 
{
	setlocale(LC_ALL, "RUS");
	vector <bool> f;
	int size = 3;
	bool el;
	cout << "Функция ";
	for (int i = 0; i < size; i++) {
		cin >> el;
		f.push_back(el);
	}
	bool x0 = f.at(0), x1 = f.at(1), x2 = f.at(2);//Возвращает ссылку на элемент в указанном месте с проверкой границ.
	int m = pow(2, size);
	cout << " x0 " << "x1 " << " x2 " << " СKНФ " << endl;
	cout << " " << x0 << "  " << x1 << "  " << x2 << " " << " --- " << (!x0 || x1 || !x2) && (!x0 || x1 || x2) && (x0 || !x1 || x2) && (x0 || x1 || x2);
}
*/
// По заданному вектору значений f булевой функции вернуть строку,	
//в которой записана СКНФ этой булевой функии. 
//Считать, что имена аргументов это х1, х2, х3, х4 и 
//Конъюнкция обозначается&, дизъюнкция V, отрицание '
/*
int main()
{
setlocale(LC_ALL, "RUS");
vector <bool> f;
int size = 3;
bool el;
cout << "Функция ";
for (int i = 0; i < size; i++) {
	cin >> el;
	f.push_back(el);
}
bool x0 = f.at(0), x1 = f.at(1), x2 = f.at(2);//Возвращает ссылку на элемент в указанном месте с проверкой границ.
int m = pow(2, size); //Вычисляет значение, возведенное в степень
cout << " x0 " << "x1 " << " x2 " << " СКНФ " << endl;
cout << " " << x0 << "  " << x1 << "  " << x2 << " " << " --- " <<  (!x0 && !x1 && !x2) || (!x0 && x1 && !x2) || (x0 && x1 && x2) || (x0 && x1 && !x2);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////2 часть/////////////////////////////////////////////////////////////////////////
*/
// 3 задание 
//размер самой длинной подстроки, которая не содержит повторяющихся символов

void func_substr_len()
{
	srand(time(0));
	const int n = 40;
	int i, j, start = 0, max = 0, a[26], y;
	string s;
	for (i = 0; i < n; i++)
		s += "A"[0] + rand() % 26;
	cout << s << endl;
	for (i = 0; i < n; i++)
	{
		for (y = 0; y < 26; a[y] = 0, y++);
		for (j = i; j < n; j++)
		{
			if (a[s[j] - 65])
			{
				if (j - i > max)
				{
					start = i;
					max = j - i;
				}
				break;
			}
			a[s[j] - 65]++;
		}
	}
	i = 0;
	while (i++ < max)
		cout << s[start++];
	cout << endl << max << endl;
}

//задание 1 Римские Числа
void roman_to_arab()
{
	setlocale(LC_ALL, "RUS");
	int a, i;
	string b;//b-roman_number
	while (1)
	{
		a = 0;
		cout << "Римское число: ";
		cin >> b;
		for (i = 0; i < b.size() - 1; i++)
			switch (b[i])
			{
			case 'I': if (b[i + 1] == 'V')
			{
				a += 4;
				i++;
			}
					else if (b[i + 1] == 'X')
			{
				a += 9;
				i++;
			}
					else a += 1;  break;
			case 'V': a += 5; break;
			case 'X':
				if (b[i + 1] == 'L')
				{
					a += 40;
					i++;
				}
				else if (b[i + 1] == 'C')
				{
					a += 90;
					i++;
				}
				else a += 10;  break;
			case 'L': a += 50; break;
			case 'C':
				if (b[i + 1] == 'D')
				{
					a += 400;
					i++;
				}
				else if (b[i + 1] == 'M')
				{
					a += 900;
					i++;
				}
				else a += 100;  break;
			case 'D': a += 500; break;
			case 'M': a += 1000; break;
			}
		if (i == b.size() - 1)
			switch (b[i])
			{
			case 'I': a += 1; break;
			case 'V': a += 5; break;
			case 'X': a += 10; break;
			case 'L': a += 50; break;
			case 'C': a += 100; break;
			case 'D': a += 500; break;
			case 'M': a += 1000; break;
			default:
				cout << "Введено неверное число\n"; 
				break;
			}
		cout << a << endl;
		break;
	}
} 
//2 задание Треугольник Паскаля
void func_Pascal()
{
	int a, i, b;
	cin >> a;
	vector<vector<int> > v(a);
	v[0].push_back(1);
	for (i = 1; i < a; i++)
	{
		for (int j = 0; j < i * 2; j++)
		{
			b = 0;
			b += (j - 2 >= 0 ? v[i - 1][j - 2] : 0);
			b += (j - 1 >= 0 && j - 1 < v[i - 1].size() ? v[i - 1][j - 1] : 0);
			b += (j < v[i - 1].size() ? v[i - 1][j] : 0);
			v[i].push_back(b);
		}
	}
	for (int j = 0; j < v[a - 1].size(); j++)
		cout << v[a - 1][j] << ' ';
	cout << endl;
}
int main() {
	setlocale(0, "");

	int choice = 0;
	while (true)
	{
		cout << "что вы хотите сделать ?\n";
		cout << "1.Римское число  \n";
		cout << "2.Трегольник Паскаля\n";
		cout << "3.Размер самой длинной подстроки\n";
		cout << "4.Выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			roman_to_arab();
			break;
		}
		case 2:
		{
			func_Pascal();
			break;
		}
		case 3:
		{
			func_substr_len();
			break;
		}
		case 4:
			return 0;
		default:
			break;
			{
				return 0;
			}
		}
	}
}
 
 /*
vector<int> func_Pascal(int a)
{
	int i, b;
	vector<vector<int> > v(a);
	v[0].push_back(1);
	for (i = 1; i < a; i++)
	{
		for (int j = 0; j < i * 2; j++)
		{
			b = 0;
			b += (j - 2 >= 0 ? v[i - 1][j - 2] : 0);
			b += (j - 1 >= 0 && j - 1 < v[i - 1].size() ? v[i - 1][j - 1] : 0);
			b += (j < v[i - 1].size() ? v[i - 1][j] : 0);
			v[i].push_back(b);
		}
	}
	return v[a - 1];
}
int roman_to_arab(string input_string)
{
	int rezult, i;
	rezult = 0;
	cin >> input_string;
	for (i = 0; i < input_string.size() - 1; i++)
		switch (input_string[i])
		{
		case 'I': if (input_string[i + 1] == 'V')
		{
			rezult += 4;
			i++;
		}
				else if (input_string[i + 1] == 'X')
		{
			rezult += 9;
			i++;
		}
				else rezult += 1;  break;
		case 'V': rezult += 5; break;
		case 'X':
			if (input_string[i + 1] == 'L')
			{
				rezult += 40;
				i++;
			}
			else if (input_string[i + 1] == 'C')
			{
				rezult += 90;
				i++;
			}
			else rezult += 10;  break;
		case 'L': rezult += 50; break;
		case 'C':
			if (input_string[i + 1] == 'D')
			{
				rezult += 400;
				i++;
			}
			else if (input_string[i + 1] == 'M')
			{
				rezult += 900;
				i++;
			}
			else rezult += 100;  break;
		case 'D': rezult += 500; break;
		case 'M': rezult += 1000; break;
		}
	if (i == input_string.size() - 1)
		switch (input_string[i])
		{
		case 'I': rezult += 1; break;
		case 'V': rezult += 5; break;
		case 'X': rezult += 10; break;
		case 'L': rezult += 50; break;
		case 'C': rezult += 100; break;
		case 'D': rezult += 500; break;
		case 'M': rezult += 1000; break;
		default:
			cout << "Введено неверное число\n"; break;
		}
	return rezult;
}
int func_substr_len(string s)
{
	srand(time(0));
	const int n = 40;
	int i, j, start = 0, max = 0, a[26], y;
	for (i = 0; i < s.size(); i++)
	{
		for (y = 0; y < 26; a[y] = 0, y++);
		for (j = i; j < s.size(); j++)
		{
			if (a[s[j] - 65])
			{
				if (j - i > max)
				{
					start = i;
					max = j - i;
				}
				break;
			}
			a[s[j] - 65]++;
		}
	}
	return max;
}
int main()
{
	setlocale(0, "");
	cout << "Задание 1\n";
	int a, i, b;
	string input_string;
	srand(time(0));
	const int n = 40;
	int i, j, start = 0, max = 0, a[26], y;
	string input_str;
	while (1)
	{
		cin >> a;
		vector<int> v = func_Pascal(a);
		for (int j = 0; j < v.size(); j++)
			cout << v[j] << ' ';
		cout << endl;
		cout << "Римское число: ";
		cin >> input_string;
		cout << roman_to_arab(input_string) << endl;
		cin >> input_str;
		cout << func_substr_len(input_str) << endl;

	}
}
*/
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
