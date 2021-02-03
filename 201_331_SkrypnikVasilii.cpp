#include "Class.h"//подключение h-файла
#include <iostream>//библиотека ввода и вывода
using namespace std;//стандартное пространство имен
int main()
{
    vector<bool> vec = { false, false, true, false };
    printf_s("num_of_args: %d\n", num_of_args(vec));

    return 0;
}