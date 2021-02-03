#include <iostream>// для cin и cout
#include <vector> // для работы с векторами
#include <math.h> // для математических операций
#include <fstream> // для записи/чтения из файла
#include <string> // для работы со строками

using namespace std;


int num_of_args(vector<bool> f) { // получение кол-ва переменных
    int n = log2(f.size());
    return n;
}

vector<bool> read_from_file(string file_name) { // чтение значений из файла
    vector<bool> return_vector; // вектор который возвращаем
    string basic_string;
    ifstream out(file_name);
    if (!out.is_open()) {
        cout << "Ошибка открытия файла!\n";
    } else {
        while (!out.eof()) { // цикл считывания значений
            basic_string = "";
            out >> basic_string;
            if (basic_string == "") continue;
            return_vector.push_back(stoi(basic_string)); // передача значений в вектор
        }
    }
    out.close();     // закрываем файл
    return return_vector;
}

bool write_to_file(std::string file_name, vector<bool> f) { // запись в файл
    ofstream in;
    bool record_result; // возвращаемая переменная
    in.open(file_name, ios::app);
    int i;
    for (i = 0; i < f.size() - 1; i++) {
        in << f[i] << " ";
    }
    in << f[i];
    in.close();
    vector<bool> vector; // дополнительный вектор для проверки совпадения результата записи и исходного
    vector = read_from_file(file_name);
    if (vector == f) {
        record_result = true;
    }

    return record_result;
}

string table(vector<bool> f) {
    string table;
    int num = num_of_args(f);

    for (int i = 1; i <= num; i++) {
        table += "x" + to_string(i) + "\t"; // вывод шапки
    }
    table += "f\n";

    for (int i = 0; i < f.size(); i++) {
        for (int j = 0; j <= num; j++) {
            if (j == num)
                table += to_string(f.at(i)); // для последнего столбца пишем определенное значение из вектора
            else
                table += to_string((bool) (i & (int) (pow(2, (num - j - 1))))) + "\t"; // вывод таблицы истинности
        }
        table += "\n";
    }
    return table;
}


vector<int> func_Pascal(int k) {
    vector<int> vector; // создаем вектор
    for (int i = 0; i < k + 1; i++) {
        vector.push_back(0); //обнуляем значение вектора
    }
    vector[0] = 1; // первому элементу присваиваем значение 1
    for (int i = 0; i < k + 1; i++) {
        for (int j = i; j > 0; j--) {
            vector[j] = vector[j - 1] + vector[j];
        }
    }
    return vector; // возвращаем вектор
}

int func_substr_len(string input_string) {
    bool arr[26]; // массив буллевских переменных для контроля повторений символов
    int n = input_string.length(), x = 0, max = 0; // длина строки, счётчик символов без повторений, максимальная длина
    for (int i = 0; i < 26; i++) { // заполняем нулями массив
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { // считаем сами повторения
            char s = input_string[j]; // текущий символ
            if (arr[(int) s - 97] == 0) {
                x += 1;
                if (x > max) {
                    max = x;
                }
                arr[(int) s - 97] = 1; // присваиваем еденицу если данный символ уже есть
            } else {
                break; // вышел из внутреннего цикла во внешний, при нахождении повторяющегося символа
            }
        }
        x = 0; // сброс счётчика
        for (int j = 0; j < 26; j++) { // обнуляем массив
            arr[j] = 0;
        }
    }
    return max; // возвращаем максимальную длину
}

int roman_to_arab(std::string roman_number) {
    int value = 0; // наше число
    for (int i = 0; i < roman_number.length(); i++) { // цикл для подсчёта значения от символа
        if (roman_number[i] == 'M')
            value += 1000;
        if (roman_number[i] == 'C' && roman_number[i + 1] == 'M') {
            value += 900;
            i++;
        }
        if (roman_number[i] == 'D')
            value += 500;
        if (roman_number[i] == 'C' && roman_number[i + 1] == 'D') {
            value += 400;
            i++;
        }
        if (roman_number[i] == 'C')
            value += 100;
        if (roman_number[i] == 'X' && roman_number[i + 1] == 'C') {
            value += 90;
            i++;
        }
        if (roman_number[i] == 'L')
            value += 50;
        if (roman_number[i] == 'X' && roman_number[i + 1] == 'L') {
            value += 40;
            i++;
        }
        if (roman_number[i] == 'X')
            value += 10;
        if (roman_number[i] == 'I' && roman_number[i + 1] == 'X') {
            value += 9;
            i++;
        }
        if (roman_number[i] == 'V')
            value += 5;
        if (roman_number[i] == 'I' && roman_number[i + 1] == 'V') {
            value += 4;
            i++;
        }
        if (roman_number[i] == 'I')
            value += 1;
    }
    return value;
}