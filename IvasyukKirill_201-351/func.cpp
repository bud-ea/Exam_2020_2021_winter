#include "Func.h"
#include <string>
#include <bitset>

int num_of_args(vector<bool> f)
{
    return ceil(log2(f.size())); // логарифм от количества наборов
}

vector<bool> read_from_file(string file_name)
{
    std::vector < bool > result;
    std::ifstream file(file_name);
    std::copy(std::istream_iterator<bool>(file),istream_iterator<bool>(), back_inserter(result)); //copy используется для записывания значения в вектор
    return result;
}

bool write_to_file(std::string file_name, vector<bool> f)
{

    std::ofstream file(file_name);
    std::copy(f.begin(), f.end(), std::ostream_iterator<bool>(file)); // copy используется для записывания значения в вектор
    return true;
}

std::string table(std::vector<bool> f)
{
    std::string bufStr;
    for (int i = 0; i < f.size(); i++)
    {
        std::bitset<4> bit(i);
        bufStr = bufStr + bit.to_string() + "\t" + std::to_string(f[i]) + "\n";
    }

    return bufStr;
}

struct Sdnf
{
public:
    int func;
    int x1, x2, x3;
    Sdnf(int x1, int x2, int x3, int f) :x1(x1), x2(x2), x3(x3), func(f) {};
};

struct Sdnfl
{
public:
    string x1, x2, x3;
    Sdnfl(string x1, string x2, string x3) :x1(x1), x2(x2), x3(x3) {};
    Sdnfl() :x1(x1), x2(x2), x3(x3) {};
};
string func_sdnf(vector<bool> f)
{
    string str;
    // str += (char)&#x26;
    vector<Sdnf> sdnf = { Sdnf(0,0,0,f[0]),
    Sdnf(0,0,1,f[1]),
    Sdnf(0,1,0,f[2]),
    Sdnf(0,1,1,f[3]),
    Sdnf(1,0,0,f[4]),
    Sdnf(1,0,1,f[5]),
    Sdnf(1,1,0,f[6]),
    Sdnf(1,1,1,f[7])
    };
    string result = "";
    vector<Sdnfl> sdnf_result(8);
    vector<string> func_res(8);
    for (int i = 0; i < 8; i++)
    {
        if (f[i] == 1)
        {

            if (sdnf[i].x1 == 1)
                sdnf_result[i].x1 = "x1";
            else
                sdnf_result[i].x1 = "x1\'";
            if (sdnf[i].x2 == 1)
                sdnf_result[i].x2 = "x2";
            else
                sdnf_result[i].x2 = "x2\'";
            if (sdnf[i].x3 == 1)
                sdnf_result[i].x3 = "x3";
            else
                sdnf_result[i].x3 = "x3\'";

            if (result == "")
            {
                result = sdnf_result[i].x1 + "&" + sdnf_result[i].x2 + "&" + sdnf_result[i].x3;
            }
            else
            {
                result = result + "V" + sdnf_result[i].x1 + "&" + sdnf_result[i].x2 + "&" + sdnf_result[i].x3;
            }
        }
    }
    return result;
}