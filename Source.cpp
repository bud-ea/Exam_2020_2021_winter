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
int roman_to_arab(string chislo)
{
    int n = sizeof chislo;//смотрим количество цифр в числе
    int arab = 0;
    for (int i = 0; i < n; i++)
    {
        if (chislo[i] == 'I')
        {
            if (chislo[i + 1] == 'V')// проверяем особый случай
            {
                arab += 4;
                i++;
            }
            else if (chislo[i + 1] == 'X')// проверяем особый случай
            {
                arab += 9;
                i++;
            }
            else
            {
                arab += 1;
            }
        }
        else if (chislo[i] == 'V')
        {
            arab += 5;

        }
        else if (chislo[i] == 'X')
        {

            if (chislo[i + 1] == 'L')// проверяем особый случай
            {
                arab += 40;
                i++;
            }
            else if (chislo[i + 1] == 'C')// проверяем особый случай
            {
                arab += 90;
                i++;
            }
            else {
                arab += 10;

            }
        }
        else if (chislo[i] == 'C')
        {

            if (chislo[i + 1] == 'D')// проверяем особый случай
            {
                arab += 400;
                i++;
            }
            else if (chislo[i + 1] == 'M') // проверяем особый случай
            {
                arab += 900;
                i++;
            }
            else {
                arab += 100;

            }

        }
        else if (chislo[i] == 'D')
        {
            arab += 500;

        }
        else if (chislo[i] == 'M')
        {
            arab += 1000;

        }


    };
    cout << arab << endl;
    return arab;

}
vector<int> func_Pascal(int k)
{
    vector<int> line = { 1, 1 };//вторая строка треугольника
    switch (k)
    {
    case 0:
        return vector<int> { 1 };// первая строка треугольника 

    case 1:
        return line;
    }

    for (int i = 2; i <= k; i++)
    {
        vector<int> currentLine = { 1 };
        for (int j = 0; j < i - 1; j++)
        {
            currentLine.push_back(line.at(j) + line.at(j + 1));// выстраиваем треугольник Паскаля
        }
        currentLine.push_back(1);
        line = currentLine;//присваеваем переменной последнюю строку
    }

    return line;
}
