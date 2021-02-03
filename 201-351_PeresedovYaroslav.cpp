#include "201-351_PeresedovYaroslav.h"



int num_of_args(vector<bool> f)
{
    return(
        int(
            log(double(f.size())) / log(2.0) //логарифм длины вектора по основанию 2 
            )
        );
}

vector<bool> read_from_file(string file_name, vector<bool> f)
{
    return vector<bool> {true};
}

string advance(string arguments) // дополнительная функция для удобного вывода аргументов в задании с table
{                                // 000 -> 001 -> 010
    for (int i = arguments.length() - 1; i >= 0; i--)
    {
        if (arguments[i] == '0') 
        {
            //cout << "found a zero at " << i << "\n";
            arguments[i] = '1';
            for (int x = i + 1; x < arguments.length(); x++)
            {
                arguments[x] = '0';
                //cout << "clearing pos " << x << "\n";
            }
            break;
        }
    }
    //cout << "Arguments changed. New: " << arguments << "\n";
    return arguments;
}
string table(vector<bool> f)
{
    string output;
    string arguments;
    for(int i = 0; i < num_of_args(f); i++)
    {
        arguments.append(std::to_string(0)); //таблицу истинности начинаем с набора аргументов 000
    }
    for (int i = 1; i < num_of_args(f) + 1; i++)
    {
        output.append("x");
        output.append(std::to_string(i));
        output.append(" "); //перечисляем аргументы в заголовке таблицы истинности
    }
    output.append("f\n");
    for (int i = 0; i < f.size(); i++) 
    {

        for (int x = 0; x < arguments.size(); x++)
        {
            output = output + arguments[x];
            output.append("  ");
        }
        arguments = advance(arguments); 
        output = output + to_string(f[i]) + "\n"; //в конец таблицы добавляем значение f
        //получилось так аккуратно, мне нравится
    }
    return output;
}

string func_sdnf(vector <bool> f)
{
    string output;
    string arguments;
    for (int i = 0; i < num_of_args(f); i++)
    {
        arguments.append(std::to_string(0)); //таблицу истинности начинаем с набора аргументов 000
    }
    for (int i = 0; i < f.size(); i++)
    {
        if (f[i] == 0)
        {
            output.append("(");
            for (int x = 0; x < num_of_args(f); x++) //здесь, счётчики: i - номер рассматриваемой строки ТИ,
                                                    //x - номер рассматриваемого аргумента (записать его самого или отрицание)
            {
                if (arguments[x] == '1')
                {
                    output.append("x");
                    output.append(std::to_string(x + 1)); 
                }
                if(arguments[x] == '0')
                {
                    output.append("x");
                    output.append(std::to_string(x + 1));
                    output.append("\'");
                }
                
                output.append("&"); //перечисляем аргументы в заголовке таблицы истинности
            }
            output.pop_back(); //стираю последний знак & который ничего не значит
            output.append(")");
            output.append("V");
        } 
        arguments = advance(arguments);
        
    }
    output.pop_back(); //стираю последний знак V который ничего не значит
    return output;
}

string func_sknf(vector <bool> f)
{
    string output;
    string arguments;
    for (int i = 0; i < num_of_args(f); i++)
    {
        arguments.append(std::to_string(0)); //таблицу истинности начинаем с набора аргументов 000
    }
    for (int i = 0; i < f.size(); i++)
    {
        if (f[i] == 1)
        {
            output.append("(");
            for (int x = 0; x < num_of_args(f); x++) //здесь, счётчики: i - номер рассматриваемой строки ТИ,
                                                    //x - номер рассматриваемого аргумента (записать его самого или отрицание)
            {
                if (arguments[x] == '0')
                {
                    output.append("x");
                    output.append(std::to_string(x + 1));
                }
                if (arguments[x] == '1')
                {
                    output.append("x");
                    output.append(std::to_string(x + 1));
                    output.append("\'");
                }

                output.append("V"); //перечисляем аргументы в заголовке таблицы истинности
            }
            output.pop_back(); //стираю последний знак & который ничего не значит
            output.append(")");
            output.append("&");
        }
        arguments = advance(arguments);
    }
    output.pop_back(); //стираю последний знак V который ничего не значит
    return output;

    //я скопировал функцию sdnf, поменяв числа
}

vector<int> func_Pascal(int k)
{
    vector<int> x1 = { 1 };
    if (k == 0)
    {
        return x1;
    }
    vector<int> x2(x1.size()); //x2 - вектор, размером на 1 больше чем x1. Туда идут суммы соседних чисел из x1
    for (int x = 0; x < k + 1; x++) 
    {
        for (int i = 1; i < x2.size() - 1; i++)
        {
            x2[i] = x1[i - 1] + x1[i];
        }
        x2[0] = 1;
        x2[x2.size() - 1] = 1;
        x1 = x2;
        x2.push_back(1); //x1 и x2 постоянно растут, пока мы не получим вектор с нужной строчкой
    }

    return x2;
}
int symbol_val(char x)
{
    switch(x)
    {
    case 'I': return 1; break;
    case 'V': return 5; break;
    case 'X': return 10; break;
    case 'L': return 50; break;
    case 'C': return 100; break;
    case 'D': return 500; break;
    case 'M': return 1000; break;
    }
}

int roman_to_arab(string roman_number)
{
    int tier = 0;
    int value = 0;
    for (int i = roman_number.size() - 1; i >= 0; i--) //исследуем число сзади, чтобы проще было считать разряды
    {
        if (symbol_val(roman_number[i]) >= tier) {
            tier = symbol_val(roman_number[i]);
            value += symbol_val(roman_number[i]); //сравнение с максимальной записанной цифрой (tier) позволяет понять, 
                                                 //вычесть цифру или прибавить
        }
        else
        {
            value -= symbol_val(roman_number[i]);
        }
    }
    return value;
}

int func_substr_len(string input_str)
{
    int score = 1;
    int highscore = 1;
    bool fail = false;
    for (int i = 0; i < input_str.length() - 1; i++)//решено просто за O(n^3)
    {
        score = 1;
        for (int x = i + 1; x < input_str.length(); i++)
        {
            if (fail)
                fail = false;
                break;
            for (int j = i; j < x; j++)
            {
                if (input_str[j] != input_str[x])
                    score++;
                else
                {
                    fail = true;
                    break;
                }
            }
        }
        highscore = std::max(score, highscore);
    }
    return highscore;
}
int main()
{
    vector <bool> test1{ 1, 0, 0, 1, 1, 1, 1, 1 };
    int k = 5;
    cout << func_substr_len("abrrr");

}