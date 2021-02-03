#include <iostream>
#include <vector>//вектор
#include <string>//строчки
#include <iostream>//работа с файлами
#include <fstream>//работа с файлами
using namespace std;

int num_of_args(vector<bool> f)
{
    int size = f.size();
    int n = 0; //количество аргументов

    while (size > 1)
    {
        size = size / 2;
        n++;
    }

    cout << n<< endl;
    cout << endl;

    return n;
}

vector<bool>read_from_file(string file_name) {
    string line;
    vector<bool> mn;
    
    ifstream in(file_name); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }
    else {
        cout << "Файл не открылся" << endl;
    }
    in.close();     // закрываем файл
    for (int i = 0; i < mn.size(); i++) {
        bool a;
        a = line[i];
        mn.push_back(a);
    }
    cout << "End of program" << endl;
    return mn;
}

bool write_to_file(std::string file_name, vector<bool> f) {
    ofstream out;          // поток для записи
    out.open(file_name); // окрываем файл для записи
    if (out.is_open())
    {
        for (int i = 0; i < f.size(); i++) {
            out << f[i];
        }
    }

    cout << "End of program" << endl;
    return 0;
}


string table(vector<bool> f) {
    string Tabl = {"x1 x2 x3 f"};

    for (int i = 0; i < 32; i++) {

     int bin = 0, k = 1; //в двоичную систему
     int t = i;
     if (i == 0) {
         Tabl.push_back(' 0');
         Tabl.push_back(' 0');
         Tabl.push_back(' 0');
         continue;
     }
        while (t)
        {
            bin += (t % 2) * k;
            k *= 10;
            t /= 2;
        }
        
        if (bin / 100 == 0 && bin / 10 != 0) //двух
        {
            Tabl.push_back(' 0');
            if (bin % 10 == 0) {
                Tabl.push_back(' 1');
                Tabl.push_back(' 0');
            }
            else if((bin % 10 == 1)) {
                Tabl.push_back(' 1');
                Tabl.push_back(' 1');

            }
        }
        if (bin / 100 == 0 && bin / 10 == 0) //если одно
        {
            Tabl.push_back(' 0');
            Tabl.push_back(' 0');
            Tabl.push_back(' 1');
        }

        if (bin % 10 == 1 &&  )
        Tabl.push_back(f[i]);
    }
    return Tabl;
}

std::string func_sdnf(vector<bool> f) {
    string sdnf;
    int num=0, t = 0;
    for (int i = 0; i < f.size(); i++) {
        if (f[i] = 1) {
            t = i;
            int bin = 0, k = 1; //в двоичную систему
           
            while (t)
            {
                bin += (t % 2) * k;
                k *= 10;
                t /= 2;
            }
            while (bin != 0) {
                if (bin % 10 == 0) {
                    sdnf.push_back('!x3&');
                }
                else if (bin % 10 == 1) {
                    sdnf.push_back('x3&');
                }
                bin = bin / 10;
            }
        }
    }
    return sdnf;
}


int main()
{
    
    setlocale(LC_ALL, "rus");
    vector<bool>Task1{ 1, 0, 0, 0, 1, 0, 1, 0 }; //задание 1
    num_of_args(Task1);//Задание 1
   


    string file_task_2;// Задание 2
    cin >> file_task_2;// файл
    read_from_file(file_task_2);


    cout << "Name file" << endl; // Задание 3
    string file;//файл
    cin >> file;
    int n;
    vector<bool> Task_3{ 1,0,0,0 };
    write_to_file(file, Task_3);
    

    vector<bool> Tabl{ 1,0,0,0,1,0 };
    string m;

    m = table(Tabl);

    for (int i = 0; i < m.size(); i++) {
        cout << m[i] << endl;
    }
}
