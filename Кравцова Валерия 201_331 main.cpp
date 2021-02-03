#include <iostream> // библеотека для ввода/вывода
#include "func.h"

using namespace std;


int main() {
    vector<bool> vec = read_from_file("test.txt");
    for (auto i : vec) {
        cout << i;
    }
    cout << endl;
    cout << num_of_args(vec) << endl;
    write_to_file("testO.txt", vec);
    cout << table(vec) << endl;
    cout << func_sdnf(vec) << endl;
    cout << func_sknf(vec) << endl;
    system("pause");
}