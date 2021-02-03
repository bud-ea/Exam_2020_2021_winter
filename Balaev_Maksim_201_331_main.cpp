#include "Balaev_Maksim_201_331.h" //подключение h.file

#include <iostream> //библиотека ввода/вывода

using namespace std; //стандартное пространство имен (чтобы не писать каждый раз std)

int main()
{
    vector<bool> vec = { false, false, true, false, false, false, true, false };
    printf_s("num_of_args: %d\n", num_of_args(vec));

    return 0;
}
