#include <iostream> // cout cin
#include <vector> // для работы с векторами
#include <math.h> // для математических операций
#include <fstream> // для чтения/записи данных из/в файл
#include <string> // для работы с Си-строками

using namespace std;

int num_of_args(vector<bool> f) {
    int n = log2(f.size());
    return n;
}

vector<bool> read_from_file(string file_name) { // чтение значений из файла
    vector<bool> vec; // вектор который возвращаем
    string str;
    ifstream out(file_name);
    if (!out.is_open()) {
        cout << "Ошибка открытия файла!\n";
    } else {
        while (!out.eof()) { // цикл считывания значений
            str = "";
            out >> str;
            if (str == "") continue;
            vec.push_back(stoi(str)); // передача значений в вектор
        }
    }
    out.close(); // закрываем файл
    return vec;
}

bool write_to_file(std::string file_name, vector<bool> f) {
    ofstream in;
    bool v;
    in.open(file_name, ios::app);
    int i;
    for (i = 0; i < f.size() - 1; i++) {
        in << f[i] << " ";
    }
    in << f[i];
    in.close();
    vector<bool> vec;
    vec = read_from_file(file_name);
    if (vec == f) {
        v = true;
    }

    return v;
}

string table(vector<bool> f) {
    string table;
    int num = num_of_args(f);

    for (int i = 1; i <= num; i++) {
        table += "x" + to_string(i) + "\t"; // Вывод шапки
    }
    table += "f\n";

    for (int i = 0; i < f.size(); i++) {
        for (int j = 0; j <= num; j++) {
            if (j == num)
                table += to_string(f.at(i));
            else
                table += to_string((bool) (i & (int) (pow(2, (num - j - 1))))) + "\t";
        }
        table += "\n";
    }
    return table;
}

std::string func_sdnf(std::vector<bool> f) {
    string func("f_sdnf(");
    int num = num_of_args(f); // получаем количество аргументов
    bool has_s_func = false; // используется для обработки, если функция имеет SDNF

    for (int i = 1; i <= num; i++) {
        func += "x" + std::to_string(i);
        if (i != num)
            func += ", ";
    }
    func += ") = ";

    for (int i = 0; i < f.size(); i++) {// перебираем все значения функции
        // SDNF строится только для истинных значений функции!
        if (f.at(i)) { // сообщаем, что функция действительно имеет sdnf
            has_s_func = true;
            func += "(";
            for (int j = 0; j < num; j++) { // пройти по таблице истинности
                // тот же метод получения значения для аргумента, который использовался выше
                bool arguments = (bool) (i & (int) (pow(2, (num - j - 1))));
                // обрабатываем, если значение аргумента ложно
                if (!arguments)
                    func += "'";

                func += "x" + std::to_string(j + 1); //выводим элемент формулы
                if (j != num - 1)
                    func += " & ";
            }
            func += ") v ";
        }
    }
}
