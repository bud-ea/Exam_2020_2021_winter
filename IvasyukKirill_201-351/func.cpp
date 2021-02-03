#include "func.h"

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

std::string table(std::vector<bool> f)//таблица
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
string func_sdnf(vector<bool> f)//считает сднф
{
    string str;
    // str += (char)&#x26;
    vector<Sdnf> sdnf = { Sdnf(0,0,0,f[0]),//вводит параметры для подсчета сднф
    Sdnf(0,0,1,f[1]),
    Sdnf(0,1,0,f[2]),
    Sdnf(0,1,1,f[3]),
    Sdnf(1,0,0,f[4]),
    Sdnf(1,0,1,f[5]),
    Sdnf(1,1,0,f[6]),
    Sdnf(1,1,1,f[7])
    };
    string result = "";
    vector<Sdnfl> sdnf_result(8);//записывает полученные значения сднф
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

int roman_to_arab(std::string roman_number)//Римские 
{
    map<char, int> romanMap;//map для создания словаря
    //значения римских и арабских цифр
    romanMap['I'] = 1;
    romanMap['V'] = 5;
    romanMap['X'] = 10;
    romanMap['L'] = 50;
    romanMap['C'] = 100;
    romanMap['D'] = 500;
    romanMap['M'] = 1000;

    int tmp = 0;//инициализация временного значения
    int res = 0;//результат
    for (char c : roman_number)//перебор символов римской строки
    {
        int n = romanMap[c];//запись текущей цифры из словаря
        if (n < tmp)//если символ меньше пред.,то идем в меньшую сторону и прибавляем
        {
            res += tmp;
            tmp = n;
        }
        else if (n > tmp)//если символ больше
        {
            if (tmp == 0)// и если предыдущая равна 0=> только начали перебор
                tmp = n;
            else//если нет,значит перед большим римским значением стоит меньшее,а значит вычитаем
            {
                res += n - tmp;
                tmp = 0;
            }
        }
        else if (n == tmp)//если равны,складываем
        {
            res += tmp + n;
            tmp = 0;
        }
    }
    return res + tmp;

}

std::vector<int> func_Pascal(int k)//треугольник Паскаля
{
    std::vector<int> result;

    for (int i = 0; i <= k; i++)
    {
        result.push_back(fact(k) / (fact(k - i) * fact(i)));//запись в вектор бинальное значение
    }
    return result;
}

double fact(double num)//факториал
{
    if (num == 0) return 1;
    else return num * fact(num - 1);
}

int func_substr_len(std::string input_str)// нахождение самой длинной подстроки без повторяющихся символов
{

    int result = 0,
        firstChar = 0;
    std::set<char> Set;//хранение символов подстроки

    for (int i = 0; i < input_str.size(); i++)//перебор
    {
        if (Set.find(input_str[i]) == Set.end())//если пусто,добавляем
        {
            Set.insert(input_str[i]);
        }
        else
        {
            if (Set.size() > result)
            {
                result = Set.size();//замена значения на макс
            }
            Set.clear();//очистка
            firstChar++;
            i = firstChar;//заново,кроме первый символов
        }
    }
    if (result == 0)
        result = Set.size();
    return result;
}