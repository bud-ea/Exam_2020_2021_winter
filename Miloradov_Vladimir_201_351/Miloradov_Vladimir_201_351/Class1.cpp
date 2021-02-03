#include "Class1.h"
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int num_of_args(std::vector<bool> f)
{
	int num;
	cout << "Введите вектор значений функции с точкой на конце: ";
	while (cin >> num)
		f.push_back(num);
	int answer1;
	answer1 = log(f.size()) / log(2);
	cout << "Ответ: " << answer1;
	return answer1;
}

vector<bool> read_from_file(std::string file_name)
{
    std::string buf;
    std::vector<bool> read;
    std::ifstream src(file_name);
    if (src.is_open())
    {
        while (std::getline(src, buf))
        {
            for (int i = 0; i < buf.size(); i++)
            {
                read.push_back(buf[i]);
            }
        }
    }
    return read;
}