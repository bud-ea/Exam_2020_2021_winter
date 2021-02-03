#include <C:\Users\leto1\source\repos\Exam_2020_2021_winter\Letov 201-351\Letov 201-351\header.h>

vector<bool> read_from_file(std::string file_name)
{
	vector<bool> rtrn;
	string temp;

	ifstream orig(file_name, ifstream::in);

	if (orig.is_open())
	{
		getline(orig, temp);
		for (int i = 0; i < temp.length(); i++)
			if (temp[i] == '1')
				rtrn.push_back(1);
			else if (temp[i] == '0')
				rtrn.push_back(0);
	}
	else
	{
		cout << "error";
	}
	return rtrn;
}

bool write_to_file(std::string file_name, vector<bool> f)
{
	ofstream orig(file_name, ofstream::out | ofstream::trunc);
	if (orig.is_open())
	{
		string buf;
		for (int i = 0; i < f.size(); i++)
			if (f[i])
				buf.push_back('1');
			else if (!f[i])
				buf.push_back('0');
		orig << buf;
		orig.close();
	}
	else
		return false;
}

int num_of_args(vector<bool> f)
{
	int pow = 0;
	int size = f.size();
	do
	{
		size /= 2;
		pow++;
	} while (size / 2 != 0);
	return pow;
}

string table(vector<bool> f)
{
	int power = num_of_args(f);
	string rtrn;
	string buf;
	int counter = 0;
	for (int i = 0; i < f.size(); i++)
	{
		int j = i;
		counter = 0;
		do
		{
			buf.append(std::to_string(j % 2));
			j /= 2;
			counter++;
		} while (j != 0 || counter < power);
		reverse(buf.begin(), buf.end());
		rtrn.append(buf + ' ' + std::to_string(f[i]) + '\n');
		buf.clear();
	}
	return rtrn;
}

//std::string func_sdnf(vector<bool> f)
//{
//	string rtrn;
//	string sub = "x ";
//	for (int i = 0; i < f.size(); i++)
//	{
//		//if (f[i] = )
//	}
//	return rtrn;
//}

bool XOR(bool x, bool y)
{
	return (x + y) % 2;
}

std::string func_Zhegalkin(vector<bool> f)
{
	string rtrn;
	string buf;

	for (int i = 0; i < f.size(); i++)
		buf.append(std::to_string(f[i]));

	int counter = f.size();

	for (int i = 0; i < f.size(); i++)
	{
		int counter = f.size() - i;

		for (int j = 0; j < f.size() - i; j++);
		{
			buf.append(std::to_string(XOR(buf.size() - counter, buf.size() - counter + 1)));
		}
		
	}
	return rtrn;
}

std::vector<int> func_Pascal(int k)
{
	vector<int> rtrn;
	unsigned long coef;

	coef = 1;
	for (int j = 0; j <= k; j++) 
	{
		rtrn.push_back(coef);
		coef *= (k - j);
		coef /= (j + 1);
	}
	return rtrn;
}

void clear(bool* mas) // функция для возвращения хранилища в исходное положение 
{
	for (int j = 0; j < 26; j++)
		mas [j] = false;
}

int func_substr_len(std::string input_str)
{
	int max = 0, counter = 0;
	bool storage[26] = { false }; // инициализация массива-хранилища для подсчета встречаемых букв

	for (int i = 0; i < input_str.size(); i++)
	{
		
		if (storage[input_str[i] - 97] == false) // проверка, что в хранилище еще нет такой буквы
		{
			counter++;
			storage[input_str[i] - 97] = true; // помечаем в хранилище, что буква уже встречалась
		}
		else
		{
			counter = 1; // единица, потому что нудно учитывать последнюю букву, которая входит в ряд одинаковых (abbbc)
			clear(storage);
			storage[input_str[i] - 97] = true; // опять же для учета текущий буквы
		}
		if (counter > max)
			max = counter;
	}

	return max;
}

int roman_to_arab(std::string roman_number)
{
	int arab_num = 0; // переменная для подсчета

	map<char, int> RA; // map для перевода символов римских чисел в арабские числа
	RA['I'] = 1;
	RA['V'] = 5;
	RA['X'] = 10;
	RA['L'] = 50;
	RA['C'] = 100;
	RA['D'] = 500;
	RA['M'] = 1000;

	vector<int> arab_number; // вектор куда, запишутся переведнные из римских арабские числа

	int counter = 1;

	for (int i = 0; i < roman_number.size(); i++)
		arab_number.push_back(RA[roman_number[i]]);

	bool flag_no_end = true; // флаг, который определяет, находятся ли мЕньшие числа в конце вектора

	for (int i = 0; i < arab_number.size() - 1 ; i++)
	{
		if (arab_number[i] < arab_number[i + 1]) // проверка, что левые числа, меньше правых
			arab_number[i] *= -1; // отрицание значения 
		else if (arab_number[i] == arab_number[i + 1])
		{
			int counter = 1;

			while (arab_number[i] == arab_number[i + 1]) // цикл для подсчета подряд идущих одинаковых цифр
			{
				counter++;
				if (i < arab_number.size() - 2)
					i++;
				else
				{
					flag_no_end = false;
					break;
				}
			}
			if (flag_no_end) // если подряд идущие цифры не в конце вектора (числа)
				for (int j = 0; j < counter; j++) // тогда отрицаем все подряд идушие одинаковые цифры
					arab_number[arab_number.size() - 2 - j] *= -1;
		}
	}
	
	for (int i = 0; i < arab_number.size(); i++) // цикл сложения
		arab_num += arab_number[i];
	return arab_num;
}

int main()
{
	/*string tmp;
	cin >> tmp;
	cout << roman_to_arab(tmp);*/
	
	vector<int> temp;
	temp = func_Pascal(33);
	for (int i = 0; i < temp.size(); i++)
		cout << temp[i];



	//vector<bool> temp = { 0, 0, 0, 1, 0, 0, 0, 1 };
	//cout << func_Zhegalkin(temp);
	//string tin = "C:/Users/leto1/source/repos/Exam_2020_2021_winter/Letov 201-351/Letov 201-351/test_in.txt";
	//write_to_file(tin, temp);
	/*vector<bool> zxc;
	string tout = "C:/Users/leto1/source/repos/Exam_2020_2021_winter/Letov 201-351/Letov 201-351/test_out.txt";
	zxc = read_from_file(tout);
	for (int i = 0; i < zxc.size(); i++)
		cout << zxc[i];*/

}