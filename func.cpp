#include <iostream> // cout cin
#include <vector> // для работы с векторами
#include <math.h> // для математических операций
#include <fstream>
#include <string>

using namespace std;

const string file = {"F:\\file.txt"}; // расположение файла1
const string file2 = {"F:\\file2.txt"}; // расположение файла2

vector<bool> f; // вектор по умолчанию

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

int num_of_args(vector<bool> f) {
    int n = log2(f.size());
    return n;
}

int main() {
    f = read_from_file(file);
    bool tr = write_to_file(file2, f);
    cout << tr;
}
