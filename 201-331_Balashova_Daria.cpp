#include <iostream> //ввод вывод
#include <vector> //библиотека работы с векторами
#include <string> //библиотека работы со строками 
#include <fstream> //библиотека рабоы с файлами
#include "Balashova.h"
using namespace std;

int num_of_args(vector<bool> f)
{
	int n=0;// колличество элементов 
	while (pow(2, n) != f.size())
		n++;
	return  n;
}

vector<bool> read_from_file(string file_name)
{
	ifstream inf(file_name);//открываем файл для чтения
	vector <bool> f;
	while (inf)
	{
		bool i;
		inf >> i;//считываем 
		f.push_back(i);//добавляем в вектор
	}
	inf.close();
	return f;
}

bool write_to_file(string file_name, vector<bool> f)
{
	ofstream outf(file_name);//открываем файл для ввода
	int i = 0;
	for (int i = 0; i < f.size(); i++)
		outf << f[i] << ' ';//вводим в файл
	outf.close();
	return true;
}

string table(vector<bool> f)
{
	string tabl;
	int n = num_of_args(f);//находим количкство элементов 
	for (int i = 0; i <= n; i++)
		tabl += "x" + to_string(i) + " ";
	tabl += "f" + '\n';
	
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)//просмативаем когда на 0
		{
			for (int j = 0; j <= n; j++)
			{
				tabl += i;
			}
		}

		int bin;
		for (int j = 0; i > 0; j++)//первод в двоичную систему с 1 по n
		{
			bin += (i % 2) * pow(10.0, j);
			i /= 2;
		}

		int x = 1,k=0;
		while (bin / x != 0) //ищем долинну двоичного эл
		{
			x *= 10;
			k++;
		}

		if (k != n)//заносим в строку когда длинна эл меньше нужный 
		{
			while (k != n)//заносим начальные недостающие нули
			{
				tabl += "0 ";
				k++;
			}
		    tabl += to_string(bin)+" ";//заносим сам эл
		}
		else 
			tabl += to_string(bin)+" ";//если эл нужного размера то просто его заносим
		tabl += to_string(f.at(i))+'\n';
	}

	return tabl;
}
string func_sdnf(vector<bool> f)
{

}
std::string func_sknf(vector<bool> f)
{

}
std::string func_Zhegalkin(vector<bool> f)
{

}