#include <iostream> // cout cin
#include <vector> // для работы с векторами
#include <math.h> // для математических операций
#include <fstream>
#include <string>
using namespace std;

int num_of_args(vector<bool> f) {
    int n = log2(f.size());
    return n;
}

vector <bool> read_from_file(string file_name) { // чтение значений из файла
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

bool write_to_file(std::string file_name, vector <bool> f) {
    ofstream in;
    bool v;
    in.open(file_name, ios::app);
    int i;
    for (i = 0; i < f.size() - 1; i++) {
        in << f[i] << " ";
    }
    in << f[i];
    in.close();
    vector <bool> vec;
    vec = read_from_file(file_name);
    if (vec == f) {
        v = true;
    }

    return v;
}

std::string table (vector<bool> f){

}

std::string func_sdnf (vector<bool> f){

}

std::string func_sknf (vector<bool> f){

}

std::string func_Zhegalkin (vector<bool> f){

}