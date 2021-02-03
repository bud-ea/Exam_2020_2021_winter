#include <vector> // библеотека векторов
#include <string> // строки, getline
#include <fstream> // библеотека для чтения файлов
#include <iostream>
#include "func.h"

using namespace std;


int num_of_args(vector<bool> f) {
    int amount_args = 0;
    amount_args = log(f.size()) / log(2);
    return amount_args;
}

bool write_to_file(string file_name, vector<bool> f)
{
    ofstream file(file_name);
    if (file.is_open()) {
        for (auto i : f) {
            file << i << " ";
        }
        return true;
    }
    else
    {
        return false;
    }
}

string table(vector<bool> f)
{
    string table = "";
    int amount_args = num_of_args(f);
    for (int i = 0; i < amount_args; i++) {
        table += "x" + to_string(i + 1) + "\t";
    }
    table += "f\n";

    int j = 0;
    for (int i = 0; i < f.size(); i++)
    {
        if (j == amount_args) {
            table += to_string(f[i]) + "\n";
            j = 0;
        }
        else {
            table += to_string(f[i]) + "\t";
            j++;
        }

    }
    return table;
}

string s_nf(vector<bool> f, bool nf) {
    string line = "";
    int amount_args = num_of_args(f);
    for (int i = amount_args; i < f.size(); i += amount_args + 1) {
        if (f[i] == nf) {
            if (line != "")
                line += " V ";
            line += "(";
            int k = 1;
            for (int j = i - amount_args; j < i; j++) {

                if (f[j] == 0) {
                    line += "'x" + to_string(k);
                }
                else
                {
                    line += "x" + to_string(k);
                }
                if (j != i - 1) {
                    line += " & ";
                }
                k++;

            }
            line += ")";

        }

    }
    return line;
}

string func_sdnf(vector<bool> f)
{
    string sdnf = s_nf(f, 1);
    return sdnf;
}

string func_sknf(vector<bool> f)
{
    string sknf = s_nf(f, 0);
    return sknf;
}

vector<bool> read_from_file(string file_name) {
    vector <bool> vec;
    ifstream file(file_name);
    if (file.is_open())
    {
        string temp;
        getline(file, temp);
        for (int i = 0; i < temp.length(); i += 2) {
            vec.push_back((int)temp[i] - 48);
        }
    }
    file.close();
    return vec;
}
