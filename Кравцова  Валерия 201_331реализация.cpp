#include <vector> // библеотека векторов
#include <string> // строки, getline
#include <fstream> // библеотека для чтения файлов
#include "func.h"

using namespace std;


int num_of_args(vector<bool> f) {
	int amount_args = 0;
	amount_args = log(f.size()) / log(2);
	return amount_args;
}

bool write_to_file(string file_name, vector<bool> f)
{
	ofstream file(file_name);
	if (file.is_open()) {
		for (auto i : f) {
			file << i << " ";
		}
		return true;
	}
	else
	{
		return false;
	}
}

string table(vector<bool> f)
{
	string table = "";
	int amount_args = num_of_args(f);

	for (int i = 0; i < f.size();)
	{
		for (int j =0; j < amount_args)
	}
	return table;
}

vector<bool> read_from_file(string file name) {
	vector <bool> vec;
	ifstream file(file_name);
	if (file.is_open())
	{
		string temp;
		getline(file, temp);
		for (int i = 0; i < temp.length(); i += 2) {
			vec.push_back((int)temp[i] - 48);
		}
	}
	file.close();
	return vec;
}