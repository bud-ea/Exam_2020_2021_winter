#pragma once
#include <iostream>
#include <string>
#include <vector>


using std::vector;
using std::string;


/*
int num_of_args(vector<bool> f,int n)//возврат количество аргументов n функции f
{
	n = f.size();
	return n;
}


bool write_to_file(string file_name,vector<bool> f)
{
	if (true)
		return true;
	else
		return false;
}

string table(bool *arr)
{

}
*/

//Часть 2
int roman_to_arab(char roman_number,int n)
{
	int I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000;

		if (roman_number == I)
			roman_number = I;
		if (roman_number == V)
			roman_number = V;
		if (roman_number == X)
			roman_number = X;
		if (roman_number == L)
			roman_number = L;
		if (roman_number == C)
			roman_number = C;
		if (roman_number == D)
			roman_number = D;
		if (roman_number == M)
			roman_number = M;
		
		return roman_number;
}


int fun_paskal(int k)
{
	if (k > 0 && k <= 33) {
		int arr[1000]{};
		for (int i = 1; i < k; i++) {
			arr[0] = 1;
			for (int j = 1; j < k; j++) {
				for (i = j; i >= 1; i--) {
					arr[i] = arr[i - 1] + arr[i];
				}
			}
		}
	}
	return 0;
}