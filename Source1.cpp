#include <fstream> //библиотека для работы с fstream
#include <iostream>//библиотека ввода-вывода
#include "Header1.h"//загружаем h файл
#include <string>//работа с с-строками
#include<vector>//работа с векторами
#include<unordered_set>//неупорядоченное множество
#include <map>//для работы с map

/* По заданному вектору значений f булевой функции возвращает количество аргументов n этой функции. Длина вектора f есть pow(2,n). */
int num_of_args(vector<bool> f) {
	int size = f.size(), n = 0; // size - длина вектора функции, n - количество аргументов функции
	while (size > 1) {          //цикл для определения степени 2 числа
		size /= 2;
		n++;
	}
	return n;
}

/* По заданному расположению и имени файла file_name вернуть вектор значений булевой функции vector<bool>*/
vector<bool> read_from_file(std::string file)
{
	vector <bool> f;
	fstream fs;//создание объекта при работе в С++
	string str;
	fs.open(file, std::fstream::in);  //открытие файла, на чтение 
	getline(fs, str);// считывание строки с вектором
	for (int i = 0; i < str.length(); i += 2) {
		f.push_back((bool)str[i]);
	}
	fs.close();
	return f;
}

/*Записать заданный вектор значений f булевой функции в файл, заданной расположением и имененем файла file_name. Вернуть true при успешной записи.*/
bool write_to_file(string file_name, vector<bool> f) {
	fstream fs;								//создание объекта при работе в С++
	fs.open(file_name, fstream::out);  //открытие файла, режим: на запись
	if (fs.fail()) return false;
	for (int i = 0; i < f.size(); i++) fs << f[i] << " ";
	fs.close();
	return true;
}
/*Во входной строке записано римское число, не превышающее трех тысяч. Необходимо вернуть записать его в арабской.*/
int roman_to_arab(std::string roman_number)
{
    int arab_number = 0;
    for (int i = 0; i < roman_number.length(); i++)
    {
        //Идём от большего числа к меньшему: M,D,C..
        if (roman_number[i] == 'M')
            arab_number += 1000;
        //Если из следующего числа можно вычесть текущее, то делаем это
        if (roman_number[i] == 'C' && roman_number[i + 1] == 'M')
        {
            arab_number += 900;
            i++;//Пропускаем следующую итерацию
        }
        if (roman_number[i] == '‎D')
            arab_number += 500;
        if (roman_number[i] == 'C' && roman_number[i + 1] == 'D')
        {
            arab_number += 400;
            i++;//Пропускаем следующую итерацию
        }
        if (roman_number[i] == 'C')
            arab_number += 100;
        if (roman_number[i] == 'X' && roman_number[i + 1] == 'C')
        {
            arab_number += 90;
            i++;//Пропускаем следующую итерацию
        }
        if (roman_number[i] == 'L')
            arab_number += 50;
        if (roman_number[i] == 'X' && roman_number[i + 1] == 'L')
        {
            arab_number += 40;
            i++;//Пропускаем следующую итерацию
        }
        if (roman_number[i] == 'X')
            arab_number += 10;
        if (roman_number[i] == 'I' && roman_number[i + 1] == 'X')
        {
            arab_number += 9;
            i++;//Пропускаем следующую итерацию
        }
        if (roman_number[i] == 'V')
            arab_number += 5;
        if (roman_number[i] == 'I' && roman_number[i + 1] == 'V')
        {
            arab_number += 4;
            i++;//Пропускаем следующую итерацию
        }
        if (roman_number[i] == 'I')
            arab_number += 1;
    }
    return arab_number;
}
/*По заданной строке input_str вернуть число, равное размеру самой длинной подстроки, которая не содержит повторяющихся символов.*/
int func(string input_string) {
    unordered_set<int> str;
    int counter;
    int max = 0;
    for (size_t i = 0; i < input_string.length(); i++) {
        counter = 0;
        size_t j = i + 1;
        str.clear();
        while (true) {
            if (j < input_string.length() and str.find(input_string[j]) == str.end()) {
                str.insert(input_string[j]);
                counter++;
                j++;
            }
            else {
                if (counter > max) {
                    max = counter;
                }
                break;
            }
        }
    }
    return max;
}
int bio_k(int m, int n)
{
    int fact_n = 1;
    int fact_m = 1;
    int fact_n_m = 1;
    for (int i = 1; i <= n; i++)
    {
        fact_n *= i;
    }
    for (int i = 1; i <= m; i++)
    {
        fact_m *= i;
    }
    for (int i = 1; i <= (n - m); i++)
    {
        fact_n_m *= i;
    }
    return fact_n / (fact_m * fact_n_m);
}
vector <int> func_Pascal(int k)
{
    vector <int> result;
    for (int i = 0; i < k + 1; i++)
    {
        result.push_back(bio_k(i, k));
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i]<<" ";
    }
    return result;
}