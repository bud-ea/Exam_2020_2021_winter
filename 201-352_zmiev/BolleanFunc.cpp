#include "BolleanFunc.h"

int num_of_args(std::vector<bool> f)
{
	return ceil(log2(f.size())); //округление в большую логарифма с основанием 2
}

std::vector<bool> read_from_file(std::string file_name)
{
	std::string bufLine;
	std::vector<bool> resultVector;

	std::ifstream inputStream(file_name);
	if (inputStream.is_open())
	{
		while (std::getline(inputStream, bufLine))
		{
			for (int i = 0; i < bufLine.size(); i++) //перебираем полученную из файла строку
			{
				if (bufLine[i] == '0') resultVector.push_back(false);
				else resultVector.push_back(true);
			}
		}
	}

	return resultVector;
}

bool write_to_file(std::string file_name, std::vector<bool> f)
{
	std::ofstream outputStream(file_name, std::ios::out);
	if (outputStream.is_open())
	{
		for (auto i : f)
		{
			outputStream << i; //использу€ поток вывода пишем вектор в файл
		}
		return true;
	}
	else
	{
		return false;
	}
}

std::string table(std::vector<bool> f)
{
	std::string bufStr;
	for (int i = 0; i < f.size(); i++)
	{
		std::bitset<8> bit(i); //преобразуем int в битовое представление
		bufStr = bufStr + bit.to_string() + "\t" + std::to_string(f[i]) + "\n";
	}

	return bufStr;
}

int roman_to_arab(std::string roman_number)
{
	std::map<char, int> romanMap;
	romanMap['I'] = 1;
	romanMap['V'] = 5;
	romanMap['X'] = 10;
	romanMap['L'] = 50;
	romanMap['C'] = 100;
	romanMap['D'] = 500;
	romanMap['M'] = 1000; //словарь из рамских и арабских цифр

	int prevNum = 0;
	int result = 0;
	for (char c : roman_number) //перебираем все символы в римской строке
	{
		int currentNum = romanMap[c]; //записываем текущую цифру из словар€
		if (currentNum < prevNum) //если текущий символ меньше предыдущего, значит мы идЄм в меньшую сторону и просто плюсуем
		{
			result += prevNum;
			prevNum = currentNum;
		}
		else if (currentNum > prevNum) //если значение больше
		{
			if (prevNum == 0) //и если предыдуща€ равна 0 значит мы только начали перебирать
				prevNum = currentNum;
			else //если нет, значит у нас ситуаци€ например "IV" и надо вычитать
			{
				result += currentNum - prevNum;
				prevNum = 0;
			}
		}
		else if (currentNum == prevNum) //если текущий и предыдущий равны, просто складываем
		{
			result += prevNum + currentNum;
			prevNum = 0;
		}
	}

	return result + prevNum;
}

std::vector<int> func_Pascal(int k)
{
	std::vector<int> result;

	for (int i = 0; i <= k; i++)
	{ //формула дл€ нахождени€ последней строки в треугольнике паскал€:
		result.push_back(fact(k) / (fact((double)k - i) * fact(i)));
	} //n! / m! * (n-m)!

	return result;
}

double fact(double num) //функци€ рекурсивного вычислени€ факториала
{
	if (num == 0) return 1;
	else return num * fact(num - 1);
}

int func_substr_len(std::string input_str)
{
	int firstChar = 0;
	int result = 0;
	std::set<char> charSet; //создаЄм set в котором будут хранитьс€ все символы подстроки

	for (int i = 0; i < input_str.size(); i++) //перебираем строку
	{
		if (charSet.find(input_str[i]) == charSet.end()) //если символа нет, значит добавл€ем 
		{
			charSet.insert(input_str[i]);
		}
		else //если же есть, то
		{
			if (charSet.size() > result) //если размер подстроки больше размера предыдущей
			{
				result = charSet.size(); //записываем новое значение
			}
			charSet.clear();
			firstChar++;
			i = firstChar; //очиша€м set и начинаем перебирать строку со следующего элемента
		}
	}

	if (result == 0) result = charSet.size(); //если set ниразу не обнулилс€

	return result;
}