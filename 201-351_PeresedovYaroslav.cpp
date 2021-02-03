#include "201-351_Peresedov-Yaroslav.h"



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
int main()
{
    vector <bool> test1{ 1, 0, 0, 1, 1, 1, 1, 1 };
    cout << func_sknf(test1);
}