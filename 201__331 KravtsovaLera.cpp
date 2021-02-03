#include <iostream> // библеотека для ввода/вывода
#include "func.h" // подключаем заголовочный файл

using namespace std;  

template <class type> // шаблон для элементов вектора
void print_vector(vector<type> v) 
{
    cout << "[ ";  
    for (auto i : v)  // пробегаем элементы вектора
        cout << i << " ";

    cout << "]" << "\n";
}



int main() { 
    vector<bool> vec = read_from_file("test.txt"); // создаем вектор с элементами bool
    print_vector(vec); 
    cout << endl;
    cout << num_of_args(vec) << endl; // выводим количество аргументов булевой функции
    write_to_file("testO.txt", vec);  // записываем в файл наш вектор
    cout << table(vec) << endl;   
    cout << func_sdnf(vec) << endl;
    cout << func_sknf(vec) << endl;

    print_vector(func_Pascal(5));  // в качестве вектора строчка треугольника паскаля
    cout << endl;
    cout << func_substr_len("abcabcbb") << endl; 
    system("pause");
}