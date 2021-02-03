#include <iostream>
#include <vector>
#include <math.h>
#include "Func.h"

using namespace std;

int main()
{
    string a = "E:\Лабы\kerel";
    vector<bool>  r;
    r = read_from_file(a);

    vector<bool> ar = { 1,0,1,1 };
    cout << table(ar);

    setlocale(LC_ALL, "Russian"); // добавляем русскую раскладку
    int N = 3;-
    int length = 0;
    length = pow(2, N);
    vector<bool> vb(length);
     func_sdnf(vb);

}