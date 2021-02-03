#include <iostream> //Библиотека ввода-вывода
#include <vector> //Подкелючение библиотеки векторов
#include "Class1.h" //Связывание main-файла с .h файла

using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian"); //Подключение русского языка
    std::vector<bool> f; //Объявление вектора
    std::string file_name;
    num_of_args(f); //Функция к заданию 1
    cout << endl;
    read_from_file(file_name); //Функция к заданию 2
    cout << endl;
    write_to_file(file_name, f);
    cout << endl;
    table(f);
    cout << endl;
    func_sdnf(f); //Функция к заданию 5
    cout << endl;
    func_sknf(f); //Функция к заданию 6
    cout << endl;
}

