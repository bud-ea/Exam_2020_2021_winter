#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "table.h"
using namespace std;
string nameout = "base.txt";
ifstream input;
ofstream out;




bool in(string user)
{
    string line;
    //cin >> line;
    out.open(user);
    cout << ">";
    cin.ignore();
    getline(cin,line);
    out << line;
    out.close();
    return true;
}

int kol(bool check)
{
    vector <bool> F;
    bool a;
    input.open(nameout);
    while(!input.eof())
    {

        input >> a;
        F.push_back(a);
    }
    input.close();
    if(check)
        {cout << ">" << log2(F.size()) << "\n";return 0;}
    else
    return log2(F.size());
}
void outer(string user)
{
    string line;
    input.open(user);
    getline(input,line);
    cout << ">" << line << "\n";
    input.close();
}
void table()
{

    int kk=kol(0);
    for(int i=0; i<kk; ++i)
    {
        cout << "x" << i+1 << " ";
    }
    cout << "f\n";
    vector <bool> F;
    bool a;
    input.open(nameout);
    while(!input.eof())
    {

        input >> a;
        F.push_back(a);
    }
    for(int i=0; i<F.size(); ++i)
    {
        int j=F.size()-i;
        for(int k=0; k < kk; ++k)
        {
            cout << j%2 << "  ";
            j/=2;
        }
        cout << F[i] << "\n";
    }
}

int main()
{
    setlocale(0," ");
    cout << "Чтобы выйти нажмите 0\nЧтобы ввести функцию введите 1;\nЧтобы вывести кол-во аргументов функции введите 2\nЧтобы вывести значения функции введите 3\nЧтобы вывести таблицу истинности введите4\nЧтобы вывести СДНФ введите 5\nЧтобы вывести СКНФ введите 6\nЧтобы вывести СКНФ по полиному Жегалкина введите 7\n";
    short input;
    for(;;)
    {
        cout << ">";
        cin >> input;
        switch (input)
        {
        case 1:
        {
            cout << "Введите путь до файла (файл по умолчанию base.txt)\n>";
            cin >> nameout;
            cout  << in(nameout) << "\n";
            break;
        }
        case 2:
            kol(true);
            break;
        case 3:
        {
            cout << "Введите путь до файла (файл по умолчанию base.txt)\n>";
            cin >> nameout;
            outer(nameout);
            break;
        }
        case 4:
            table();
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 0:
            return 0;
        }
    }
    /*input >> a;
    input.close();
    out.open("base.txt");
    out << a/4;
    out.close();
    input.open("base.txt");
    input >> a;
    cout << a;*/
    return 0;
}
