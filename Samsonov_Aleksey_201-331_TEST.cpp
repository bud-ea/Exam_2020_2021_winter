#include <iostream>// библиотека ввода/вывода
#include "Samsonov_Aleksey_201-331_TEST.h"// подключаем h.file
using namespace std;// чтобы не писать std:: 
int main() {
	std::vector<bool> vec = { true, false, true, false };
	printf_s("num_of_args: %d\n", num_of_args(vec));
	return 0;
}