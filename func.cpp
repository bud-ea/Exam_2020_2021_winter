#include <iostream> // cout cin
#include <vector> // для работы с векторами
#include "func.h" // с функциями
#include <string> // для работы со строками

using namespace std;

const string file = {"D:\\file.txt"}; // расположение файла1
const string file2 = {"D:\\file2.txt"}; // расположение файла2

vector<bool> f; // вектор по умолчанию

int main() {
    setlocale(0, " ");
    f = read_from_file(file);
    bool tr = write_to_file(file2, f);
    int a = num_of_args(f);
    cout << "1 Задание: " << a << endl;
    cout << "2 Задание: ";
    for (int i = 0; i < f.size(); i++) {
        cout << f[i];
    }
    cout << endl;
    cout << "3 Задание:";
    if (tr == 1) {
        cout << "True";
    } else {
        cout << "False";
    }
    cout << endl;
    cout << "4 задание: " << endl;
    string string1 = table(f);
    cout << string1;
    cout << endl;
    cout << "\n------------2 часть------------" << endl;
    cout << "1 Задание: " << endl << "Введите римское число:";
    string Roman;
    cin >> Roman;
    cout << Roman << " = " << roman_to_arab(Roman) << endl;
    cout << "2 Задание: " << endl;
    cout << "Введите k:";
    int k;
    cin >> k;
    cout << "Func_Pascal(" << k << ") = ";
    vector<int> vector;
    vector = func_Pascal(k);
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
    cout << "3 задание: ";
    string str;
    cout << "Введите строку:";
    cin >> str;
    int result = func_substr_len(str);
    cout << result;

}