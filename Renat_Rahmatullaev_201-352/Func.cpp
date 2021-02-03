#include "Func.h"
#include <string>

int num_of_args(vector<bool> f)
{
    return ceil(log2(f.size())); //Берём логарифм от кол-ва наборов
}

vector<bool> read_from_file(string file_name)
{
    std::vector < bool > result; // Создаём вектор для записи текста с файла
    std::ifstream file(file_name);
    std::copy(std::istream_iterator<bool>(file), std::istream_iterator<bool>(), std::back_inserter(result)); //Оператором copy мы файла записываем значения в вектор
    return result;
}

bool write_to_file(std::string file_name, vector<bool> f)
