#include "Func.h"

using namespace std;

int main()
{
    string q = "D:\qwe.txt";
    string e = "D:\eqw.txt";
    vector<bool> w;
    w = read_from_file(q);
    
    string ewq = "XXV";
    cout<<roman_to_arab(ewq)<<endl;


    vector<int> VV= func_Pascal(14);
    for (int i = 0; i < VV.size(); i++)
        cout << VV[i] << ' ';


    //cout << func_substr_len("abcd");

    

    //cout <<write_to_file(e, w);



    
}

