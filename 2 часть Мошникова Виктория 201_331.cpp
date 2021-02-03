#include "ekz.h"      // заголовочный файл h с функци€ми 
#include <fstream>    // используем дл€ работы с fstream
#include <iostream>   // ввод вывод
#include <map>        // используем дл€ работы с map
#include <unordered_set>

int roman_to_arab(std::string roman_number)          //дл€ перевода римских
{
	int result = 0;
	for (int i = 0; i < roman_number.length(); i++)
	{
		if (roman_number[i] == 'M')                     //работа с тыс€чами
			result += 1000;
		if (roman_number[i] == 'C' && roman_number[i + 1] == 'M')       //если после с идет м
		{
			result += 900;
			i++;
		}
		if (roman_number[i] == 'D')                                   //работа с сотн€ми 500
			result += 500;
		if (roman_number[i] == 'C' && roman_number[i + 1] == 'D')           //работа с сотн€ми от 400 и до 200
		{
			result += 400;
			i++;
		}
		if (roman_number[i] == 'C')                                     //работа с сотн€ми 100
			result += 100;
		if (roman_number[i] == 'X' && roman_number[i + 1] == 'C')         //работа с 90 и до 60
		{
			result += 90;
			i++;
		}
		if (roman_number[i] == 'L')                                         //работа с 50
			result += 50;
		if (roman_number[i] == 'X' && roman_number[i + 1] == 'L')         //работа с 40 до 20
		{
			result += 40;
			i++;
		}
		if (roman_number[i] == 'X')                                       //работа с дес€тками
			result += 10;
		if (roman_number[i] == 'I' && roman_number[i + 1] == 'X')
		{
			result += 9;
			i++;
		}
		if (roman_number[i] == 'V')                                       //п€терки
			result += 5;
		if (roman_number[i] == 'I' && roman_number[i + 1] == 'V')
		{
			result += 4;
			i++;
		}
		if (roman_number[i] == 'I')                                        //единички
			result += 1;
	}
	return result;
}
int func(string input_string) {         //задание 3 
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
int C(int m, int n)           //треугольник паскал€ (ниже реализована формула n!/(k!(n-k)!) ) (не помню название)
{
	int fact_n = 1;
	int fact_m = 1;
	int fact_n_m = 1;
	for (int i = 1; i <= n; i++){
		fact_n *= i;
	}
	for (int i = 1; i <= m; i++){
		fact_m *= i;
	}
	for (int i = 1; i <= (n - m); i++){
		fact_n_m *= i;
	}
	return fact_n / (fact_m * fact_n_m);
}

std::vector <int> func_Pascal(int k)       //задание 2 “реугольник паскал€
{
	std::vector <int> result;
	for (int i = 0; i < k + 1; i++)
	{
		result.push_back(C(i, k));         //c конца
	}
	for (int i = 0; i < result.size(); i++) 
	{
		std::cout << result[i];
	}
	return result;
}