#include <iostream>
#include <vector>
#include <string>
#include "Funcs.h"

int main()
{
    std::vector<bool> a = read_from_file("test.txt");

    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';

    std::cout << num_of_args(a) << '\n';


    
    std::cout << table(a);
}

