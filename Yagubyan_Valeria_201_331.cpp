// Yagubyan_Valeria_201_331.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> //библиотека для ввода-вывода
#include <string> //библиотека для работы с с++ строками
#include<set> //библиотека set
#include <vector> //библиотека для работы с векторами
#include <fstream> //методы и функции для чтения/записи файла
using namespace std;

int num_of_args(vector<bool> f)
{
    return (int) log2(f.size());
}

bool write_to_file(string file_name, vector<bool> f)
{
    ofstream file;          // поток для записи
    file.open(file_name); // окрываем файл для записи
    if (!file.is_open())
        return false;
    for (bool line:f)
    {
        file << line << " ";
    }
    return true;
}

vector<bool> read_from_file(string file_name)
{
    vector<bool> bool_vec;

    ifstream file; //открытие существующего файла
    file.open(file_name);
    if (!file.is_open()) // проверка на возможность открытия

        return bool_vec;

    file.close(); //закрытие файла
}


string table(vector<bool> f)
{
    string table;
    int number = num_of_args(f);
    string x1, x2;
    for (int i = 1; i <= number; i++) 
    {
        table += "x" + to_string(i) + "\t";
    }
        table += "f\n";
        for (int i = 0; i < f.size(); i++)
        {
            for (int j = 0; j <= number; j++) //для каждой строки
            {
                if (j == number)
                    table += to_string(f.at(i));
                else
                    table += to_string((bool)(i & (int)(pow(2, (number - j - 1))))) + "\t";
            }
            table += "\n";
        }

    return table;
}

// имя файла C:\Users\Персик\Desktop\Test.txt


vector<int> func_Pascal(int k)
{
        vector<int> vector;
        int i, j;
        vector.push_back(1);
        for (i = 1; i <= k; i++) 
            vector.push_back(0);
        for (j = 1; j <= k; j++)
            for (i = j; i >= 1; i--)
                vector[i] = vector[i - 1] + vector[i];
            return vector;
}


int func_substr_len(string input_str)
{
    set<char> symbol; // хранение уникальных букв
    int normal_size = 0, max_size = 0;
    for (int i = 0; i < input_str.length(); i++) {
        symbol.insert(input_str[i]);
        if (symbol.size() > normal_size) // проверка на повторение
            normal_size = symbol.size();
        else {
            if (normal_size > max_size) max_size = normal_size;
            symbol.clear();
            normal_size = symbol.size();
        }
    }
    if (normal_size > max_size) max_size = normal_size; // если введенная строка заканчивается на подстроку, 
    // которая содержит неповторяющиеся символы - проверка данной ситуации

    return max_size;
}
int roman_to_arab(string roman_number)
{
        int res = 0;
        for (int i = 0; i < roman_number.length(); i++)
        {
            if (roman_number[i] == 'M')
                res += 1000;
            if (roman_number[i] == 'C' && roman_number[i + 1] == 'M')
            {
                res += 900;
                i++;
            }
            if (roman_number[i] == '‎D')
                res += 500;
            if (roman_number[i] == 'C' && roman_number[i + 1] == 'D')
            {
                res += 400;
                i++;
            }
            if (roman_number[i] == 'C')
                res += 100;
            if (roman_number[i] == 'X' && roman_number[i + 1] == 'C')
            {
                res += 90;
                i++;
            }
            if (roman_number[i] == 'L')
                res += 50;
            if (roman_number[i] == 'X' && roman_number[i + 1] == 'L')
            {
                res += 40;
                i++;
            }
            if (roman_number[i] == 'X')
                res += 10;
            if (roman_number[i] == 'I' && roman_number[i + 1] == 'X')
            {
                res += 9;
                i++;
            }
            if (roman_number[i] == 'V')
                res += 5;
            if (roman_number[i] == 'I' && roman_number[i + 1] == 'V')
            {
                res += 4;
                i++;
            }
            if (roman_number[i] == 'I')
                res += 1;
        }
        return res;
}


int main()
{
    int number, n, i;
    vector<bool> f;
    string file_name, string, rim_number;
    system("chcp 1251 > nul"); //кодировка
    vector<bool> bool_vec = {false, true, false, true};
    cout << "Введите полный путь к файлу" << endl;
    getline(cin, file_name);

    while (true)
    {
        cout << "Введите номер задания:" << endl;
        cout << "1. возвращает количество аргументов n этой функции" << endl;
        cout << "2. вернуть вектор значений булевой функции" << endl;
        cout << "3. записать заданный вектор значений f булевой функции в файл, заданный расположением и имененем" << endl;
        cout << "4. Таблица истинности" << endl;
        cout << "5. Треугольник Паскаля" << endl;
        cout << "6. Вернуть число, равное размеру самой длинной подстроки, которая не содержит повторяющихся символов" << endl;
        cout << "7. Римские в арабские" << endl;
        cout << "8. Выход" << endl;
        cin >> number;
        switch (number)
        {
        case 1: //количество аргументов функции
        {
            printf_s("num_of_args: %d\n", num_of_args(bool_vec));
            break;
        }
        case 2: //вектор значений
        {
            read_from_file(file_name);
            break;
        }
        case 3: //запись вектора
        {
            write_to_file(file_name, bool_vec);
            break;
        }
        case 4:
        {
            cout << table(bool_vec) << endl;
            break;
        }
        case 5:
        {
            cout << "Введите k" << endl;
            cin >> n;
            vector<int> vector = func_Pascal(n);
            for (i = 0; i < n+1; i++)
                cout << vector[i] << " ";
            break;
        }
        case 6:
        {
            cout << "Введите строку" << endl;
            cin >> string;
            cout << func_substr_len(string);
            break;
        }
        case 7:
        {
            cout << "Введите римское число" << endl;
            cin >> rim_number;
            cout << roman_to_arab(rim_number) << endl;
            break;
        }
        case 8:
        {
            return 0;
        }
        default:
            cout << "Нет такой команды" << endl;
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
