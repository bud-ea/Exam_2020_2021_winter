#include <iostream>// библиотека ввода/вывода
#include <fstream>// работа с файлами
#include "Header1.h"// подключаем h.file
#include "Source1.cpp"// подключаем cpp.file
using namespace std;
int main()
{
	vector<bool> vec = { false, true, true, false };
	printf_s("num_of_args: %d\n", num_of_args(vec));
}
