#include "Samsonov_Aleksey_201-331_Exam.h"//для подключения h.file


using namespace std;

int num_of_args(std::vector<bool> f)
{
	double fLog = log2(f.size());
	return (int)fLog;
}
int roman_to_arab(std::string roman_number)
{
    int result = 0;// это будет наше число
    for (int i = 0; i < roman_number.length(); i++)// считываем все наши числа
    {
        if (roman_number[i] == 'M')//при встрече добавляем к результату определненное число
            result += 1000;
        if (roman_number[i] == 'C' and roman_number[i + 1] == 'M')// при встрече перед более значащей(большой) буквой
        {
            result += 900;
            i++;
        }
        if (roman_number[i] == '‎D')//при встрече добавляем к результату определненное число
            result += 500;
        if (roman_number[i] == 'C' and roman_number[i + 1] == 'D')// при встрече перед более значащей(большой) буквой
        {
            result += 400;
            i++;
        }
        if (roman_number[i] == 'C')//при встрече добавляем к результату определненное число
            result += 100;
        if (roman_number[i] == 'X' and roman_number[i + 1] == 'C')// при встрече перед более значащей(большой) буквой
        {
            result += 90;
            i++;
        }
        if (roman_number[i] == 'L')//при встрече добавляем к результату определненное число
            result += 50;
        if (roman_number[i] == 'X' and roman_number[i + 1] == 'L')// при встрече перед более значащей(большой) буквой
        {
            result += 40;
            i++;
        }
        if (roman_number[i] == 'X')//при встрече добавляем к результату определненное число
            result += 10;
        if (roman_number[i] == 'I' and roman_number[i + 1] == 'X')// при встрече перед более значащей(большой) буквой
        {
            result += 9;
            i++;
        }
        if (roman_number[i] == 'V')//при встрече добавляем к результату определненное число
            result += 5;
        if (roman_number[i] == 'I' and roman_number[i + 1] == 'V')// при встрече перед более значащей(большой) буквой
        {
            result += 4;
            i++;
        }
        if (roman_number[i] == 'I')//при встрече добавляем к результату определненное число
            result += 1;
    }
    return result;
}

int func_substr_len(string input_string) {
	unordered_set<int> u;// потребуется для подсчета символов которые встречаются
	int counter;// подсчитывают длину строчки 
	int max = 0;
	for (size_t i = 0; i < input_string.length(); i++) {
		counter = 0;
		size_t j = i + 1;
		u.clear();
		while (true) {
			if (j < input_string.length() and u.find(input_string[j]) == u.end()) {//Признак того что элемент отсутствует,значит что он не нашел елемент(Find возвращает указатель на конец множества если не находит элемент.End - указатель на память после последнего элемента)
				u.insert(input_string[j]);// запоминаем так сказать
				counter++;
				j++;
			}
			else {
				if (counter > max) {// сравниваем с максимумом
					max = counter;
				}
				break;
			}
		}
	}
	return max;
}


int C(int m, int n)// n!/m!(n-m)!
{
    int fact_n = 1;
    int fact_m = 1;
    int fact_n_m = 1;
    for (int i = 1; i <= n; i++)//n!
    {
        fact_n *= i;
    }
    for (int i = 1; i <= m; i++)//m!
    {
        fact_m *= i;
    }
    for (int i = 1; i <= (n - m); i++)//(n-m)!
    {
        fact_n_m *= i;
    }
    return fact_n / (fact_m * fact_n_m);// формула 
}

std::vector <int> func_Pascal(int k)
{
    std::vector <int> result;
    for (int i = 0; i < k + 1; i++)
    {
        result.push_back(C(i, k));//добавить в конец
    }
    for (int i = 0; i < result.size(); i++) 
    {
        std::cout << result[i];
    }
    return result;
}
//vector<bool> read_from_file(string file_name)
//{
//	char buff[50];
//	ifstream in;
//	in.open("C:\\Users\\source\\repos\Exam_2020_2021_winter\File.txt");
//	in.getline(buff, 50);
//	in.close(); 
//	cout << buff << endl; 
//	return 0;
//}
//
//bool write_to_file(std::string file_name, vector<bool> f)
//{
//	ofstream file("in.txt"); 
//	file << "111001"; 
//	file.close(); 
//	system("pause");
//	return file;
//}
//int func_substr_len(std::string input_str) {
//	string str;
//	int count=0;
//	int max = 1;
//	cout << "Enter string" << endl;
//	cin >> str;
//	for (int i = 0; i < str.length()-1; i++) {
//		if (str[i] != str[i+1]) {
//			count++;
//		}
//		else {
//			count = 0;
//			if (count >= max) {
//				max = count;
//			}
//		}
//	}
//
//	
//
//
//}