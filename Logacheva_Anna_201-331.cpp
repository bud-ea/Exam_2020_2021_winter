#include <iostream>
#include <vector>//для вектора
#include "Logacheva_Anna_201-331.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int num_of_args(vector<bool> f);



    //int num_of_args(vector<bool> f) done
	//vector<bool> read_from_file (std::string file_name)
	//bool write_to_file (std::string file_name, vector<bool> f)
	//std::string table (vector<bool> f)
	//std::string func_sdnf (vector<bool> f)
	//std::string func_sknf (vector<bool> f)
	//std::string func_Zhegalkin (vector<bool> f)
}

int num_of_args(vector<bool> f)
{
    //кол-во аргументов в функции
    int n = 1;
    vector <int> f = { 0,0,0,1,0,0,0,1, };
    while (n != f.size())
        n = n * 2;
    return n / 2;
}
