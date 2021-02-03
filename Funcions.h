#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;


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


