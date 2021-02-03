#include <iostream>
#include "Class.h"
#include <vector>
#include <string>


using namespace std;

int main()
{
	vector <bool> f;
	string file_name("D:\\vec.txt");
	int n;
	cin >> n;
	f.resize(pow(2, n));
	for (int i = 0; i < pow(2, n); i++)
	{
		f[i] = i * 37 % 2;
	}
	for (int i = 0; i < pow(2, n); i++)
	{
		cout << f[i];
	}
	cout << endl << num_of_args(f) << endl;
	cout << table(f) << endl;
	
}