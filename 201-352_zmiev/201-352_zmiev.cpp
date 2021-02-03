#include <iostream>
#include <vector>
#include <cmath>
#include "BolleanFunc.h"

using namespace std;

int main()
{
    vector<bool> f = { 0, 1, 0, 1, 0, 0, 1, 1, 0};
    //int n = num_of_args(f);
    //cout << n;

    /*vector<bool> b = read_from_file("C:\\Users\\alexz\\Desktop\\111.txt");
    int n = num_of_args(b);
    cout << n;

    for (auto i : b)
    {
        cout << i;
    }*/

    write_to_file("C:\\Users\\alexz\\Desktop\\111.txt", f);
}