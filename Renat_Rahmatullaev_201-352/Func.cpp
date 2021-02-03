#include "Func.h"


int num_of_args(std::vector<bool> f)
{
    return ceil(log2(f.size())); //Берём логарифм от кол-ва наборов
}

vector<bool> read_from_file(string file_name)
{
    std::vector < bool > result; // Создаём вектор для записи текста с файла
    std::ifstream file(file_name);
    std::copy(std::istream_iterator<bool>(file), std::istream_iterator<bool>(), std::back_inserter(result)); //Оператором copy мы из файла записываем значения в вектор
    return result;
}

bool write_to_file(std::string file_name, vector<bool> f)
{
    std::ofstream file(file_name);
    if (file.is_open())
    {
        std::copy(f.begin(), f.end(), std::ostream_iterator<bool>(file)); //Оператором copy мы файла записываем значения в вектор
        return true;
    }
    else
    {
        return false;
    }
}

std::string table(std::vector<bool> f)
{
    std::string STR; //Создаём строку для записи в неё таблицу истинности 

    for (int i = 0; i < f.size(); i++)
    {
        std::bitset<6> bit(i);
        STR = STR + bit.to_string() + "\t" + std::to_string(f[i]) + "\n"; // составление таблицы 
    }

    return STR;
}




int roman_to_arab(std::string roman_number)
{
    std::map<char, int> romanMap; // Наш алфавит
    romanMap['I'] = 1;
    romanMap['V'] = 5;
    romanMap['X'] = 10;
    romanMap['L'] = 50;
    romanMap['C'] = 100;
    romanMap['D'] = 500;
    romanMap['M'] = 1000;

    int early = 0; // Предыдущее 
    int result = 0; // Результат
    for (char c : roman_number)//Проходимся по всем цифрам
    {
        int ReadNum = romanMap[c];
        if (ReadNum < early) //Если символ меньше предыдущего, значит мы прибавляем
        {
            result += early;
            early = ReadNum;
        }
        else if (ReadNum > early) // Если символ больше предыдущего, значит мы отнимаем
        {
            if (early == 0) // Если предыдущая цифра равна нулю, значит её нужно чем то заполнить 
                early = ReadNum;
            else //Если нет то мы отнимаем 
            {
                result += ReadNum - early;
                early = 0;
            }
        }
        else if (ReadNum == early) // Если символ равен предыдущему, то тоже складываем
        {
            result += early + ReadNum;
            early = 0;
        }
    }
    return result + early;
}


std::vector<int> func_Pascal(int k)
{
    std::vector<int> result;

    for (int i = 0; i <= k; i++)
    {
        result.push_back(fact(k) / (fact(k - i) * fact(i))); //Записываем в вектор бинаминальные коэффициенты 
    }
    return result;
}

double fact(double num)//Нахождение факториала числа
{
    if (num == 0) 
        return 1;
    else 
        return num * fact(num - 1);
}

int func_substr_len(std::string input_str)
{

    int firstChar = 0;
    int result = 0;
    std::set<char> SetSym; // Set в котором будут храниться все символы подстроки 

    for (int i = 0; i < input_str.size(); i++) 
    {
        if (SetSym.find(input_str[i]) == SetSym.end()) // Если такого символа в контейнере нет, мы его добавляем 
        {
            SetSym.insert(input_str[i]); // Добавляем символ в set
        }
        else 
        {
            if (SetSym.size() > result) // Если размер подстроки больше размера предыдущей
            {
                result = SetSym.size(); //Заменяем значение на максимальное
            }
            SetSym.clear(); // Очищаем set
            firstChar++; // Исключаем первые символы из проверки
            i = firstChar; // Начинаем снова, за исключением первого(ых) символов
        }
    }
    if (result == 0)
        result = SetSym.size();
    return result;
}



