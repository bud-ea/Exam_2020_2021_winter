#include <iostream>
#include <vector>
#include "Class1.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<bool> f;
    std::string file_name;
    read_from_file(file_name);
    cout << endl;
    num_of_args(f);
}

