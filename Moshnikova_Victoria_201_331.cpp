#include <iostream>                    // ввод и вывод
#include <vector>                     // работа с векторами
#include <math.h>                    // мат. операции
using namespace std;
vector<bool> f = { 0, 0, 0, 1, 1, 0, 1, 1 };  //то, что было дано 
int num_of_args(vector<bool> f)           
{
	int n = log2(f.size());                  //степень двойки опред   
	return n;
}
int main() 
{
	int n = num_of_args(f);
	cout << n;                          //должен вывести 3 
}