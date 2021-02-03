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

    system("pause");
}
 


