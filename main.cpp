#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
string nameout = "base.txt";
ifstream input;
ofstream out;
int main()

{
    vector <bool> F;
    string line;
    bool a;
    out.open("base.txt");
    getline(cin, line);
    out << line;
    out.close();
    input.open("base.txt");
    while(!input.eof())
    {
        input >> a;
        F.push_back(a);
    }
    cout << pow(2,F.size());
    /*input >> a;
    input.close();
    out.open("base.txt");
    out << a/4;
    out.close();
    input.open("base.txt");
    input >> a;
    cout << a;*/
    return 0;
}
