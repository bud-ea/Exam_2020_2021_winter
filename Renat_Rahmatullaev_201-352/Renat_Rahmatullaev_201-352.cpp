// Rahmatullaev_Renat_201-352.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <math.h>
#include "Func.h"

using namespace std;

int main()
{
    string q = "D:\qwe.txt";
    string e = "D:\eqw.txt";
    vector<bool> w;
    w = read_from_file(q);
    
    cout <<write_to_file(e, w);

}

