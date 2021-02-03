#include <iostream>//базовая библиотека
#include <vector>//для вектора
#include "Logacheva_Anna_201-331.h"
#include <fstream>//работа с файлами
using namespace std;

int num_of_args(vector<bool> f)
{
    //кол-во аргументов в функции
    int n = 1;
    vector <int> f = { 0,0,0,1,0,0,0,1, };
    while (n != f.size())
        n = n * 2;
    return n / 2;
}

vector<bool> read_from_file(string file_name)
{
    char buff[50];
    ifstream in;
    in.open("C:\\Users\\Анна\source\repos\Exam_2020_2021_winter\in.txt");
    in.getline(buff, 50); // считали строку из файла
    in.close(); // закрываем файл
    cout << buff << endl; // напечатали эту строку
    return 0;
}

bool write_to_file(std::string file_name, vector<bool> f)
{
    ofstream file("in.txt"); // создаём объект класса ofstream для записи и связываем его с файлом in.txt
    file << "001001"; // запись значений в файл
    file.close(); // закрываем файл
    system("pause");
    return file;
}

string table(vector<bool> f)
{
    int n;
    char* a = nullptr;
    if (a != nullptr)
    {
        delete[]a;
    }
    ifstream file;
    file.open("C:\\Users\\Анна\source\repos\Exam_2020_2021_winter\in.txt");
    file.getline(a, 100);
    n = sizeof a;
    a = new char[n];
    for (int i = 0; i < n / 4; i + 4)
    {
        cout << ("%d\t%d\t%d\t%d\t", a[i], a[i + 1], a[i + 2], a[i + 3]);
    }
}
