#include "Samsonov_Aleksey_201-331_Exam.h"// подключили ш файл
#include <iostream>

int num_of_args(std::vector<bool> f)
{
	double fLog = log2(f.size());
	return (int)fLog;
}
vector<bool> read_from_file(string file_name)
{
	char buff[50];
	ifstream in;
	in.open("C:\\Пользователи\\source\\repos\Exam_2020_2021_winter\File.txt");
	in.getline(buff, 50); // считали строку из файла
	in.close(); // закрываем файл
	cout << buff << endl; // напечатали эту строку
	return 0;
}

bool write_to_file(std::string file_name, vector<bool> f)
{
	ofstream file("in.txt"); // создаём объект класса ofstream для записи и связываем его с файлом in.txt
	file << "111001"; // запись значений в файл
	file.close(); // закрываем файл
	system("pause");
	return file;
}