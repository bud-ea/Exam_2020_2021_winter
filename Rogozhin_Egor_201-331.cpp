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

int roman_to_arab(string roman_number) //перевод римских цифр в арабские
{
    int res = 0;
    int arabic_num = 0;
    for (int i = roman_number.size() - 1; i >= 0; i--) 
    {
        if (i == 0) //особая обработка цифры, при i = 0
        {
            if (roman_number[i] == 'I') 
            {
                arabic_num = arabic_num + 1;
            }
            else if (roman_number[i] == 'V') 
            {
                arabic_num = arabic_num + 5;
            }
            else if (roman_number[i] == 'X')
            {
                arabic_num = arabic_num + 10;
            }
            else if (roman_number[i] == 'L') 
            {
                arabic_num = arabic_num + 50;
            }
            else if (roman_number[i] == 'C') 
            {
                arabic_num = arabic_num + 100;
            }
            else if (roman_number[i] == 'D') 
            {
                arabic_num = arabic_num + 500;
            }
            else if (roman_number[i] == 'M') 
            {
                arabic_num = arabic_num + 1000;
            }

            break;
        }

        if (roman_number[i] == 'V' && roman_number[i - 1] == 'I') //поиск и обработка особых цифр
        {
            arabic_num = arabic_num + 4;
            i--;
            if (i <= 0) break;
            continue;
        }
        if (roman_number[i] == 'X' && roman_number[i - 1] == 'I') 
        {
            arabic_num = arabic_num + 9;
            i--;
            if (i <= 0) break;
            continue;
        }
        if (roman_number[i] == 'C' && roman_number[i - 1] == 'X')
        {
            arabic_num = arabic_num + 90;
            i--;
            if (i <= 0) break;
            continue;
        }
        if (roman_number[i] == 'L' && roman_number[i - 1] == 'X') 
        {
            arabic_num = arabic_num + 40;
            i--;
            if (i <= 0) break;
            continue;
        }
        if (roman_number[i] == 'D' && roman_number[i - 1] == 'C')
        {
            arabic_num = arabic_num + 400;
            i--;
            if (i <= 0) break;
            continue;
        }
        if (roman_number[i] == 'M' && roman_number[i - 1] == 'C')
        {
            arabic_num = arabic_num + 900;
            i--;
            if (i <= 0) break;
            continue;
        }
        else if (roman_number[i] == 'I') //обработка остальных римских цифр
        {
            arabic_num = arabic_num + 1;
        }
        else if (roman_number[i] == 'V')
        {
            arabic_num = arabic_num + 5;
        }
        else if (roman_number[i] == 'X') 
        {
            arabic_num = arabic_num + 10;
        }
        else if (roman_number[i] == 'L') 
        {
            arabic_num = arabic_num + 50;
        }
        else if (roman_number[i] == 'C') 
        {
            arabic_num = arabic_num + 100;
        }
        else if (roman_number[i] == 'D') 
        {
            arabic_num = arabic_num + 500;
        }
        else if (roman_number[i] == 'M')
        {
            arabic_num = arabic_num + 1000;
        }
    }

    cout << arabic_num << endl; //вывод арабского числа
    cout << endl;
    return arabic_num;
}


long double fact(int n) //нахождение факториала от числа
{
    if (n < 0) //завершение при отрицательном числе
    {
        return 0;
    }
    if (n == 0) //вывод 1 при 0
    {
        return 1;
    }
    else //вычисление факториала положительного числа
    {
        return n * fact(n - 1);
    }
}

vector<int> func_Pascal(int k) //вывод строки из треугольника
{
    vector<int>mass_Pascal;

    for (int i = 0; i <= k; i++)
    {
        mass_Pascal.push_back(fact(k) / (fact(k - i) * fact(i)));
        cout << mass_Pascal[i]<< " "; //вывод последней строки треугольника
    }
    cout << endl;
    return mass_Pascal;
}

bool func_check(string mas, char m) //проверка на одинаковость текущего элемента масива и последующих символов
{
    for (int i = 0; i < mas.size(); i++) 
    {
        if (m == mas[i]) 
        {
            return 0;
        }
    }
    return 1;
}

int func_substr_len(string input_str) //функция поиска уникальной подстроки
{
    int local_chet = 0; //локальный счетчик
    int general_chet = 0; //общий счетчик
    string mas;

    for (int i = 0; i < input_str.size(); i++)
    {
        for (int j = i + 1; j < input_str.size(); j++) 
        {

            if (input_str[i] != input_str[j] && func_check(mas, input_str[j])) //проверка на уникальность 
            {
                local_chet = local_chet + 1;
                mas.push_back(input_str[j]); //добавлем на проверку

            }
            else {
                if (local_chet > general_chet) {
                    general_chet = local_chet;
                }
                break;
            }

            if (j + 1 == input_str.size()) //отдельная обработка последнего элемента
            {
                if (local_chet > general_chet) 
                {
                    general_chet = local_chet - 1;
                }
            }
        }
    }

    if (general_chet == 0) //если все символы были одинаковые
    {
        general_chet++;
    }

    cout << general_chet << endl; //вывод
    return general_chet;
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

    vector<bool>table_mass{ 1, 0, 1 }; //задание 4
    table(table_mass); 

    string roman; //задание 2.1
    cout << "Input roman numbers" << endl; 
    cin >> roman;
    roman_to_arab(roman);
    
    int k; //задание 2.2
    cout << "Input k" << endl;
    cin >> k;
    func_Pascal(k);

    string substr_len; //задание 2.3
    cout << endl;
    cout << "Input string" << endl;
    cin >> substr_len;
    func_substr_len(substr_len);
}