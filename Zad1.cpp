#include <fstream> //библиотека для работы с fstream
#include <iostream>
#include "Zad1.h"

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
vector<bool> read_from_file(std::string file_name){
	vector <bool> f;
	fstream fs;								//создание объекта при работе в С++
	string str;
	fs.open(file_name, std::fstream::in);  //открытие файла, на чтение 
	getline(fs, str);					   // считывание строки с вектором

	for (int i = 0; i < str.length(); i += 2) {
		f.push_back((bool)str[i]);
		
	}

	fs.close();
	return f;
}

/*Записать заданный вектор значений f булевой функции в файл, заданноый расположением и имененем файла file_name. Вернуть true при успешной записи.*/
bool write_to_file(std::string file_name, vector<bool> f) {
	fstream fs;								//создание объекта при работе в С++
	fs.open(file_name, std::fstream::out);  //открытие файла, режим: на запись
	if (fs.fail()) return false;

	for (int i = 0; i < f.size(); i++) fs << f[i] << " ";

	fs.close();

	return true;
}

/*Во входной строке записано римское число, не превышающее трех тысяч. Необходимо вернуть записать его в арабской.*/
int roman_to_arab(std::string roman_number)
{
    int result = 0;
    for (int i = 0; i < roman_number.length(); i++)
    {
        if (roman_number[i] == 'M')
            result += 1000;
        if (roman_number[i] == 'C' && roman_number[i + 1] == 'M')
        {
            result += 900;
            i++;
        }
        if (roman_number[i] == '‎D')
            result += 500;
        if (roman_number[i] == 'C' && roman_number[i + 1] == 'D')
        {
            result += 400;
            i++;
        }
        if (roman_number[i] == 'C')
            result += 100;
        if (roman_number[i] == 'X' && roman_number[i + 1] == 'C')
        {
            result += 90;
            i++;
        }
        if (roman_number[i] == 'L')
            result += 50;
        if (roman_number[i] == 'X' && roman_number[i + 1] == 'L')
        {
            result += 40;
            i++;
        }
        if (roman_number[i] == 'X')
            result += 10;
        if (roman_number[i] == 'I' && roman_number[i + 1] == 'X')
        {
            result += 9;
            i++;
        }
        if (roman_number[i] == 'V')
            result += 5;
        if (roman_number[i] == 'I' && roman_number[i + 1] == 'V')
        {
            result += 4;
            i++;
        }
        if (roman_number[i] == 'I')
            result += 1;
    }
    return result;
}

/* На вход подается неотрицательное число k от 0 до 33 включительно.В треугольнике Паскаля каждое число есть сумма 2 чисел над ним:*/
int C(int m, int n) //вспомогательная функция для func_Pascal (считает число в строке слева направо)
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

std::vector <int> func_Pascal(int k) 
{
    std::vector <int> result;
    for (int i = 0; i < k + 1; i++) 
    {
        result.push_back(C(i, k));
    }
    for (int i = 0; i < result.size(); i++) //- какой-то гребаный костыль, но работает вроде
    {
        std::cout << result[i]; 
    }
    return result;
}

/* По заданной строке input_str вернуть число, равное размеру самой длинной подстроки, которая не содержит повторяющихся символов.*/
int func_substr_len(string input_string) {
    unordered_set<int> u;
    int counter;
    int max = 0;
    for (size_t i = 0; i < input_string.length(); i++) {
        counter = 0;
        size_t j = i + 1;
        u.clear();
        while (true) {
            if (j < input_string.length() and u.find(input_string[j]) == u.end()) {
                u.insert(input_string[j]);
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
