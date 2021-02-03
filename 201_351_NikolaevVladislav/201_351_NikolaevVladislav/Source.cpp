#include "Header.h"

//функция подсчета аргументов, где каждое успешное деление на два определяет одну переменную
int num_of_args(vector<bool> f) {
	int num_of_args = 0;
	int size = f.size();
	while (size > 1) {
		size = size / 2;
		num_of_args = num_of_args + 1;
	}
	return num_of_args;

}
//функция чтения из файла
vector<bool> read_from_file(std::string file_name) {
	vector<bool> f;
	ifstream file(file_name, std::ios::in);//подготовка файла для ввода из файла
	if (!file.is_open()) {//проверка на открытие
		cout << "try again\n";
	}
	else {
		while (!file.eof()) {//пока не пустой считывает значения и заносит булевы значения в вектор
			bool func_val;
			file >> func_val;
			f.push_back(func_val);

		}

	}
	return f;
}
//функция записи в файл
bool write_to_file(string file_name, vector<bool> f)
{
	//создание объекта класса файлового вывода
	ofstream file;
	file.open(file_name, ofstream::out);//создаем и открываем с режимом для записи
	if (file.is_open() == true) {//проверяем открылся ли файл
		file << endl << "";
		for (int i = 0; i < f.size(); i++) {
			file << f[i]; //переносим элементы вектора в файл
		}
		//закрываем файл
		file.close();
		return true;
	}
	else {
		return false;
	}

}
//функция записи таблицы в строку
string table(vector<bool> f)
{
	string buf;
	int args = num_of_args(f);
	string table;
	int k = 0;
	for (int i = 0; i < f.size(); i++)
	{
		int j = i;
		k = 0;
		do//переводим из десятичной в двоичную 
		{
			buf.append(std::to_string(j % 2));//приписываем остатки от деления
			j /= 2;
			k++;
		} while (j != 0 || k < args);
		reverse(buf.begin(), buf.end());//разворачиваем строку чтобы остатки шли в обратном порядке
		table.append(buf + ' ' + std::to_string(f[i]) + '\n'); //дописываем значение функции в конец строки
		buf.clear();
	}
		
	return  table;

	/*for (int i = 0; i < args; i++) {
		
		table.append(std::to_string(i+1));
	}
	table.push_back('f');
	table.push_back('\n');*/
	
	//for (int i = 0; i < f.size(); i++) {
	//	int x = i;
	//	int bin = 0, k = 1;
	//	while (x)
	//	{
	//		bin += (x % 2) * k;
	//		k *= 10;
	//		x /= 2;
	//	}
	//	if ((bin % 10 >= 0) && (bin % 100 < 10)) {
	//		for (int j = 0; j < args - 1; j++) {
	//			table.append("0");
	//		}
	//		table.append(std::to_string(bin));
	//	}
	//	if ((bin % 1000 < 100) && (bin % 100 >= 10)) {
	//		for (int j = 0; j < args - 2; j++) {
	//			table.append("0");
	//		}
	//		table.append(std::to_string(bin));
	//	}
	//	if ((bin % 10000 <= 1000) && (bin % 1000 >= 100)) {
	//		for (int j = 0; j < args - 3; j++) {
	//			table.append("0");
	//		}
	//		table.append(std::to_string(bin));
	//	}
	//	table.append(std::to_string(f[i]));
	//	table.push_back('\n');
	//}
	/*if (args == 1) {
		for (int i = 0; i < f.size(); i++) {
			std::bitset<1> bin(i);
			table.append(bin.to_string());
			table.push_back(f[i]);
			table.push_back('\n');
		}
	}
	if (args == 2) {
		for (int i = 0; i < f.size(); i++) {
			std::bitset<2> bin(i);
			table.append(bin.to_string());
			string buf = f[i];
			table.append(buf.to_string());
			table.push_back('\n');
		}
	}
	if (args == 3) {
		for (int i = 0; i < f.size(); i++) {
			std::bitset<3> bin(i);
			table.append(bin.to_string());
			table.push_back(f[i]);
			table.push_back('\n');
		}
	}
	if (args == 4) {
		for (int i = 0; i < f.size(); i++) {
			std::bitset<3> bin(i);
			table.append(bin.to_string());
			table.push_back(f[i]);
			table.push_back('\n');
		}
	}
	if (args == 5) {
		for (int i = 0; i < f.size(); i++) {
			std::bitset<5> bin(i);
			table.append(bin.to_string());
			table.push_back(f[i]);
			table.push_back('\n');
		}
	}
	*/
	
}
unsigned long long bincoef(int n, int k)
{

	if (k > n / 2) {
		k = n - k;// тк в выводе получается симметрия то функция в точке (n,k) = функции в точке (n, n-k)
//пример: n=10 k=4 и n=10 k=6 функция имеет вид 10!/(4!*6!) от перестановки мест множителей в знаменателе результат не поменяется->экономится память    
	}
	if (k == 1) {
		return n; // при сокращении дроби в числителе остается один множитель равный n, а в знаменателе 1! -> return n
	}
	if (k == 0) {
		return 1; // при к=0 функция примет вид 1/0! = 1
	}
	unsigned long long r = 1;
	for (int i = 1; i <= k; i++) {
		r = r * (n - k + i);
		r = r / double(i);
		//идет подсчет числителя и одновременное деление на соответствующий множитель знаменателя
	}
	return r;
}
std::vector<int> func_Pascal(int n)
{
	vector<int> result;
	
	int k;
	
	cout << endl;
	for (int i = 0; i <= n; i++) {
		k = i;
		 result.push_back(bincoef(n, k));
	}
	return result;
}
//MCMXCIV
//известно что число введено верно т.е. по правилам и большими буквами
//известно что символы в римских числах расположены по возрастанию
//единственные исключения с 4, 9, 40, 90, 400, 900
//на обычных ветвлениях происходит последовательная проверка строки
//после возвращается значение в арабских цифрах
int roman_to_arab(std::string roman_number)
{
	int arab = 0;
	
	int i = 0;//проверка чисел расположена в порядке от большего к меньшему римскому числу
	while (i < roman_number.length()) {
		if (roman_number[i] == 'M') {
			arab += 1000;
			i++;
			continue;
		}
		if (roman_number[i] == 'C' && roman_number[i + 1] == 'M') {
			arab += 900;
			i += 2;
			continue;
		}
		if (roman_number[i] == 'D') {
			arab += 500;
			i++;
			continue;
		}
		if (roman_number[i] == 'C' && roman_number[i + 1] == 'D') {
			arab += 400;
			i += 2;
			continue;
		}
		if (roman_number[i] == 'C') {
			arab += 100;
			i++;
			continue;
		}
		if (roman_number[i] == 'X' && roman_number[i + 1] == 'C') {
			arab += 90;
			i += 2;
			continue;
		}
		if (roman_number[i] == 'L') {
			arab += 50;
			i++;
			continue;
		}
		if (roman_number[i] == 'X' && roman_number[i + 1] == 'L') {
			arab += 40;
			i += 2;
			continue;
		}
		if (roman_number[i] == 'X') {
			arab += 10;
			i++;
			continue;
		}
		if (roman_number[i] == 'I' && roman_number[i + 1] == 'X') {
			arab += 9;
			i += 2;
			continue;
		}
		if (roman_number[i] == 'V') {
			arab += 5;
			i++;
			continue;
		}
		if (roman_number[i] == 'I' && roman_number[i + 1] == 'V') {
			arab += 4;
			i += 2;
			continue;
		}
		if (roman_number[i] == 'I') {
			arab += 1;
			i++;
			continue;
		}

	}
	return arab;
}
//замена состояний всех букв на фолз
void update_status(bool* mas)
{
	for (int j = 0; j < 26; j++)
		mas[j] = false;
}



int func_substr_len(std::string input_str)
{
	bool letters_status[26] = { false };
	// булевый массив для 26 букв английского алфавита
	//который отражает состояние (фолз - не встречалась, тру - встречалась) каждой буквы на момент поиска длинны данной подстроки 
	int max_len = 0;//максимальная длина
	int k = 0;
	//k - это временный счетчик максимального значения


	for (int i = 0; i < input_str.size(); i++)
	{
		//когда буква встречается первый раз значение счетчика +1, статус буквы меняется на тру
		if (letters_status[input_str[i] - 97] == false)
		{
			k++;
			letters_status[input_str[i] - 97] = true;
		}
		else {//когда встречается второй раз все статусы обновляются в функции update_status
			k = 1;
			update_status(letters_status);
			letters_status[input_str[i] - 97] = true;
		}
		if (k > max_len) {
			max_len = k;
		}
			
	}

	return max_len;
}
