#include <iostream>
#include <vector> //работа с векторами
#include <string> //работа со строками
#include <fstream> //работа с файлами

using namespace std;

int num_of_args(vector<bool> f)
{
    int size = f.size();
    int n = 0; //количество аргументов

    while (size > 1) //вычисление количества аргументов
    {
        size = size/2;
        n++;
    }

    cout<< "Number of arguments: " << n << endl; //вывод количества аргументов
    cout << endl;

    return n;
}

vector<bool>read_from_file(string file_name) //чтение из файла
{
    string line;
    vector<bool> mn;
    ifstream in(file_name); //окрытие файл для чтения
    if (in.is_open())
    {
        cout << "F:" << endl;
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "Error" << endl; //вывод ошибки при неудачном открытии
    }

    in.close(); //закрытие файла файл
    for (int i = 0; i < mn.size(); i++) 
    {
        bool a;
        a = line[i];
        mn.push_back(a);
    }

    cout << "Success" << endl; //успешное завершение
    cout << endl;
    return mn;
}

bool write_to_file(std::string file_name, vector<bool> f) //запичь в файл
{
    string file;
    ofstream out;
    out.open(file_name); // окрываем файл для записи
    if (out.is_open())
    {
        for (int i = 0; i < f.size(); i++) 
        {
            out << f[i];
        }
    }
    else
    {
        cout << "Error" << endl; //вывод ошибки при неудачном открытии
        return false;
    }
    cout << "Success" << endl; //успешное завершение
    cout << endl;
    return true;
}

string table(vector<bool> f) //построение таблицы истинности
{
    string table;
    string e = "1";
    int num = num_of_args(f);

    for (int i = 1; i <= num; i++) //построение таблицы
    {
        table += "x" + to_string(i) + "\t";
    }

    return e;
}

int main()
{
    vector<bool>mass {1, 0, 0, 0, 1, 0, 1, 0}; //задание 1
    num_of_args(mass);

    string file_task_2; //задание 2
    file_task_2 = "D://file_name.txt";
    read_from_file(file_task_2);


    string file;  //задание 3
    file = "D://file_name.txt";
    vector<bool>Task_3{ 1, 0, 1, 0 };
    write_to_file(file, Task_3);

    vector<bool>table_mass{ 1, 0, 1 };
    table(table_mass); //задание 4
}