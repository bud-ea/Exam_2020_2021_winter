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

    cout << n << endl;
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



bool func_proverka(string mas, char m)//Проверка на одинаковость элементов масива и отдельного символа
{
    for (int i = 0; i < mas.size(); i++) {
        if (m == mas[i]) {
            return 0;
        }
    }
    return 1;
}

int func_substr_len(std::string input_str) {
    int chet = 0;
    int chet_2 = 0;//Создание общего счетчика
    string mas;
    for (int i = 0; i < input_str.size(); i++) {
        for (int j = i + 1; j < input_str.size(); j++) {

            if (input_str[i] != input_str[j] && func_proverka(mas, input_str[j])) // Равен ли следующий элемент и нет ли равных с предыдущими
            {
                chet = chet + 1;
                mas.push_back(input_str[j]);//Добовлем в проверочный массив

            }
            else {
                if (chet > chet_2) {
                    chet_2 = chet;
                }
                break;
            }
            if (j + 1 == input_str.size()) //Если последний элемент
            {
                if (chet > chet_2) {
                    chet_2 = chet - 1;
                }
            }
        }
    }
    if (chet_2 == 0) {
        chet_2++;
    }
    return chet_2;
}



long fact(long n)//Фактариал для паскаля
{
    long i;
    long res;
    res = 1;
    for (i = 1; i <= n; i++) {
        res = res * i;
    }
    return res;
}

vector<long>func_Pascal(long k) //Паскаль
{
    vector<int> res_1;

    for (int i = 0; i <= k; i++) {
        long int res;
        res = fact(k) / (fact(k - i) * fact(i));//Формула
        res_1.push_back(res);
    }
    return res_1;
}

int roman_to_arab(std::string roman_number) {
    int res = 0;
    for (int i = roman_number.size() - 1; i >= 0; i--) {
        if (i == 0)//Во время последнего круга
        {
            if (roman_number[i] == 'I') {
                res = res + 1;
            }
            else if (roman_number[i] == 'V') {
                res = res + 5;
            }
            else if (roman_number[i] == 'X') {
                res = res + 10;
            }
            else if (roman_number[i] == 'L') {
                res = res + 50;
            }
            else if (roman_number[i] == 'C') {
                res = res + 100;
            }
            else if (roman_number[i] == 'D') {
                res = res + 500;
            }
            else if (roman_number[i] == 'M') {
                res = res + 1000;
            };
            break;
        }
        if (roman_number[i] == 'V' && roman_number[i - 1] == 'I')//Далее сравниваем на наличие исключений
        {
            res = res + 4;
            i--;
            if (i <= 0) break;
            continue;
        }
        if (roman_number[i] == 'X' && roman_number[i - 1] == 'I') // Проверка на 4
        {
            res = res + 9;
            i--;
            if (i <= 0) break;
            continue;
        }
        if (roman_number[i] == 'C' && roman_number[i - 1] == 'X')// Проверка на 90
        {
            res = res + 90;
            i--;
            if (i <= 0) break;
            continue;
        }
        if (roman_number[i] == 'L' && roman_number[i - 1] == 'X') // Проверка на 40
        {
            res = res + 40;
            i--;
            if (i <= 0) break;
            continue;
        }
        if (roman_number[i] == 'M' && roman_number[i - 1] == 'C') // Проверка на 900
        {
            res = res + 900;
            i--;
            if (i <= 0) break;
            continue;
        }
        if (roman_number[i] == 'D' && roman_number[i - 1] == 'C') //  Проверка на 400
        {
            res = res + 400;
            i--;
            if (i <= 0) break;
            continue;
        }

        else if (roman_number[i] == 'I') {
            res = res + 1;
        }
        else if (roman_number[i] == 'V') {
            res = res + 5;
        }
        else if (roman_number[i] == 'X') {
            res = res + 10;
        }
        else if (roman_number[i] == 'L') {
            res = res + 50;
        }
        else if (roman_number[i] == 'C') {
            res = res + 100;
        }
        else if (roman_number[i] == 'D') {
            res = res + 500;
        }
        else if (roman_number[i] == 'M') {
            res = res + 1000;
        };
    }
    return res;
}

int main()
{


    setlocale(LC_ALL, "rus");
    vector<bool>Task1{ 1, 0, 0, 0, 1, 0, 1, 0 }; //задание 1
    num_of_args(Task1);//Задание 1



    string file_task_2;// Задание 2
    cout << "Введите имя файла файл" << endl;
    cin >> file_task_2;// файл
    read_from_file(file_task_2);


    cout << "Name file" << endl; // Задание 3
    string file;//файл
    cin >> file;
    int n;
    vector<bool> Task_3{ 1,0,0,0 };
    write_to_file(file, Task_3);



    string substr_len;//Задание 10
    cout << "Введите строчку" << endl;
    cin >> substr_len;
    cout << func_substr_len(substr_len) << endl;



    cout << "Enter num for Paskal" << endl;//Задание 9
    long Num_for_Paskal;
    cin >> Num_for_Paskal;
    vector<long> Paskal = func_Pascal(Num_for_Paskal);
    for (int i = 0; i < Paskal.size(); i++) {
        cout << Paskal[i] << " ";
    }
    cout << endl;


    string roman_arab;
    cout << "Введите римские цифры" << endl;
    cin >> roman_arab;
    cout << roman_to_arab(roman_arab) << endl;

}