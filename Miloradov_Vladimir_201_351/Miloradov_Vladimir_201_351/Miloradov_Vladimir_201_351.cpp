#include <iostream> //Библиотека ввода-вывода
#include <vector> //Подкелючение библиотеки векторов
#include "Class1.h" //Связывание main-файла с .h файла


using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian"); //Подключение русского языка
    std::vector<bool> f; 
    std::string file_name;
    num_of_args(f); //Функция к заданию 1
    cout << endl;
    string file_name;
    cout << "Введите расположение файла";
    cin >> file_name;
    read_from_file(file_name); //Функция к заданию 2
    cout << endl;
    string file_name;
    cout << "Введите расположение файла";
    cin >> file_name;
    write_to_file(file_name, f); //Функция к заданию 3
    cout << endl;
    table(f); //Функция к заданию 4
    cout << endl;
    func_sdnf(f); //Функция к заданию 5
    cout << endl;
    func_sknf(f); //Функция к заданию 6
    cout << endl;
    int k;
    cout << "Введите число k: ";
    cin >> k;
    func_Pascal(k); //Функция к заданию 9
    cout << endl;
    string input_str;
    cout << "Введите подстроку: ";
    cin >> input_str;
    func_substr_len(input_str); //Функция к заданию 10
    cout << endl;
    string roman_number;
    cout << "Введите число римскими цифрами: ";
    cin >> roman_number;
    roman_to_arab(roman_number); //Функция к заданию 8
}



