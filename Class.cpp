#include "Class.h"//подключение файла заголовков
#include <fstream> //библиотека работы с файлами
#include <iostream>//библио вводы и вывода
#include <bitset>//битовая библиотека
#include <unordered_set>//библиотека неупорядоченного множества

int num_of_args(std::vector<bool> f)//По заданному вектору значений f булевой функции возвращает количество аргументов n этой функции. Длина вектора f есть pow(2,n).
{
	return (int)log2(f.size());;
}

vector<bool> read_from_file(std::string file_name)// По заданному расположению и имени файла file_name вернуть вектор значений булевой функции vector<bool>
{
	vector <bool> f;
	fstream fs; 
	string str;
	fs.open(file_name, std::fstream::in);  //открытие файла на чтение 
	getline(fs, str); // считывание строки

	for (int i = 0; i < str.length(); i += 2) {
		if (str[i] == '1') f.push_back(1);
		else f.push_back(0);
	}

	fs.close();
	return f;
}
bool write_to_file(std::string file_name, vector<bool> f) { //Записать заданный вектор значений f булевой функции в файл, заданноый расположением и имененем файла file_name. Вернуть true при успешной записи.
	fstream fs;  
	fs.open(file_name, std::fstream::out);  //открытие файла на запись
	if (fs.fail()) return false;
	for (int i = 0; i < f.size(); i++) fs << f[i] << " ";
	fs.close();
	return true;

}


int roman_to_arab(std::string roman_number)//Во входной строке записано римское число, не превышающее трех тысяч. Необходимо вернуть записать его в арабской.
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
int calc(int y, int x)//доп. функц. к паскалю
{
    int fact_x = 1;
    int fact_y = 1;
    int fact_x_y = 1;
    for (int i = 1; i <= x; i++)
    {
        fact_x *= i;
    }
    for (int i = 1; i <= y; i++)
    {
        fact_y *= i;
    }
    for (int i = 1; i <= (x - y); i++)
    {
        fact_x_y *= i;
    }
    return fact_x / (fact_y * fact_x_y);
}

std::vector <int> func_Pascal(int k)//В треугольнике Паскаля каждое число есть сумма 2 чисел над ним:
{
    std::vector <int> res;
    for (int i = 0; i < k + 1; i++)
    {
        res.push_back(calc(i, k));
    }
    for (int i = 0; i < res.size(); i++) 
    {
        std::cout << res[i]<<' ';
    }
    return res;
}
int func_substr_len(string input_string) {//По заданной строке input_str вернуть число, равное размеру самой длинной подстроки, которая не содержит повторяющихся символов.
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