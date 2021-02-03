// Egel_Nikita_201-331_Ekz.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Zad1.h"


int main()
{
    std::vector<bool> vec = { false, false, true, false };
    printf_s("num_of_args: %d\n", num_of_args(vec));
}
