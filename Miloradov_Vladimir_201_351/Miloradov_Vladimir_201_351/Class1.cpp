#include "Class1.h" //Связь с файлом .h
#include <string> //Библиотека строк для заданий первой части
#include <fstream> //Библиотека работы с файлами для заданий 2-3
#include <sstream> //Библиотека StringStream для работы со строкой 
#include <bitset> //Подключение библиотеки bitset для построения таблицы истинности в задании 4
#include <map> //Подключение библиотеки map для задания 8 про римские цифры (для хранения алфавита)
#include <set> //Подключение библиотеки set для задания 10 про подстроки (для хранения строки)

using std::cout; 
using std::cin;
using std::endl;
using std::vector;

int num_of_args(std::vector<bool> f) //Функция для задания 1. 
{
	int num; 
	cout << "Введите вектор значений функции с точкой на конце: ";
	while (cin >> num) //ввод векторной формы значений булевой функции
		f.push_back(num);
	int answer1; //Переменная ответа
	answer1 = log(f.size()) / log(2); //Вычисление количества переменных в наборе функции
	cout << "Ответ: " << answer1; //Вывод
	return answer1;
}

vector<bool> read_from_file(std::string file_name) //Функция для задания 2. чтение из файла
{
	std::vector < bool > answer2; //Создаём вектор
	std::ifstream file(file_name); //Включаем файл на чтение
	std::copy(std::istream_iterator<bool>(file), std::istream_iterator<bool>(), std::back_inserter(answer2)); //Записываем значения в вектор
	return answer2;
}

bool write_to_file(std::string file_name, vector<bool> f) //Функция для задания 3. запись в файл
{
	std::ofstream file(file_name); //Включаем файл на запись
	std::copy(f.begin(), f.end(), std::ostream_iterator<bool>(file)); //Записываем значения в вектор
	return true;
}

std::string table(std::vector<bool> f) { //Функция для задания 4. Построение таблицы истинности
	std::string buf;
	for (int i = 0; i < f.size(); i++)
	{
		std::bitset<4> bit(i);
		buf = buf + bit.to_string() + "\t" + std::to_string(f[i]) + "\n";
	}
	return buf;
}

std::string func_sdnf(std::vector<bool> f) { //Функция для задания 5. Построение СДНФ
	std::ostringstream out;
	int y = num_of_args(f) + 1;
	int n = f.size();
	for (int i = 0; i < n; i++) {
		int r = f.back();
		f.pop_back();
		if (r == 1) {
			int* t = dec2bin(i, y);
			out << "(";
			for (int j = 0; j < y; j++) {
				if (t[j] == 0) {
					if (j + 1 == y) {
						out << "x" << j  << '\'';
					}
					else {
						out << "x" << j <<'\'' << '&';
					}
				}
				if (t[j] == 1) {
					if (j + 1 == y) {
						out << "x" << j;
					}
					else {
						out << "x" << j << '&';
					}
				}
			}
			if (i + 1 == n) {
				out << ")";
			}
			else {
				out << ")v";
			}
		}
	}
	return out.str();
}

std::string func_sknf(std::vector<bool> f) { //Функция для задания 6. Построение СКНФ
	std::ostringstream out;
	int y = num_of_args(f) + 1;
	int n = f.size();
	for (int i = 0; i < n; i++) {
		int r = f.back();// берем значение функции
		f.pop_back();
		if (r == 0) {
			int* t = dec2bin(i, y);// число в двоичной записи
			out << "(";
			for (int j = 0; j < y; j++) {
				if (t[j] == 0) {
					if (j + 1 == y) {
						out << "x" << j << '\'';
					}
					else {
						out << "x" << j << '\'' << 'v';
					}
				}
				if (t[j] == 1) {
					if (j + 1 == y) {
						out << "x";
						out << j;
					}
					else {
						out << "x" << j << 'v';
					}
				}
			}
			if (i == n) {
				out << ")";
			}
			else {
				out << ")&";
			}
		}
	}
	return out.str();
}

int* dec2bin(int num, int size) { //Функция перевода из десятичной системы в двоичную
	int* bin = new int[size] {0};
	int* bin_r = new int[size];
	int j = 0;
	while (num)
	{
		bin[j] = (num % 2);
		num /= 2;
		j++;
	}
	for (int i = 0; i < size; i++) {
		bin_r[size - i - 1] = bin[i];
	}
	return bin_r;
}



//Часть 2

double fact(double num) //Определение факториала
{
	if (num == 0) return 1;
	else return num * fact(num - 1);
}

std::vector<int> func_Pascal(int k) //Функция нахождения строки из треугольника Паскаля. Задача 9
{
	std::vector<int> answer8; //Создание вектора
	for (int i = 0; i <= k; i++) //Вычисление коэфициентов в строке с помощью формулы сочетаний, основанной на использовании факториалов
	{
		answer8.push_back(fact(k) / (fact(k - i) * fact(i)));
	}
	for (int i = 0; i <= k; i++) //Вывод ответа
	{
		cout << answer8[i] << " ";
	}
	return answer8;
}

int func_substr_len(std::string input_str) //Функция нахождения максимальной длины подстроки с уникальными символами. Задание 10
{
	int firstChar = 0;
	int result = 0;
	std::set<char> answer10; //Объявление set для хранения строки
	for (int i = 0; i < input_str.size(); i++) //цикл перебора символов строки
	{
		if (answer10.find(input_str[i]) == answer10.end()) //если символа нет, значит добавляем в answer10
		{
			answer10.insert(input_str[i]);
		}
		else 
		{
			if (answer10.size() > result) //если размер подстроки больше размера result
			{
				result = answer10.size(); //присваеваем результату новую строку
			}
			answer10.clear(); //очистка answer10
			firstChar++;
			i = firstChar;
		}
	}
	if (result == 0) result = answer10.size(); //Проверка на случай, если вся строка является уникальной
	cout << result; //Вывод
	return result;
}

int roman_to_arab(std::string roman_number)  //Функция перевода из римского числа в десятичное. Задание 8
{
	std::map<char, int> romanMap; //Создание контейнера map
	romanMap['I'] = 1; //Присваивание римским цифрам соответствующее десятичное число
	romanMap['V'] = 5; 
	romanMap['X'] = 10;
	romanMap['L'] = 50;
	romanMap['C'] = 100;
	romanMap['D'] = 500;
	romanMap['M'] = 1000;
	int last_num = 0; //Предыдущая цифра
	int result = 0; //Результат
	for (char c : roman_number) //Перебор строки с римским числом автоматическим циклом
	{
		int now_num = romanMap[c]; //Выделяем под текущую цифру переменную
		if (now_num < last_num) //если текущий символ меньше предыдущего, значит мы идём в меньшую сторону и просто плюсуем
		{
			result += last_num;
			last_num = now_num;
		}
		else if (now_num > last_num) //если текущий символ больше предыдущего
		{
			if (last_num == 0) //если предыдущая цифра равна 0, значит перебор только начат
				last_num = now_num;
			else //если нет, значит у нас ситуация мы идём в большую сторону и вычитаем из текущего числа предыдущее
			{
				result += now_num - last_num;
				last_num = 0;
			}
		}
		else if (now_num == last_num) //если текущая и предыдущая цифры равны, значит просто прибавляем в итог
		{
			result += last_num + now_num;
			last_num = 0;
		}
	}
	cout << result + last_num; //вывод
	return result + last_num;
}
