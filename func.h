#include <iostream>
#include <vector> // для работы с векторами
#include <math.h> // для математических операций
#include <fstream> // для записи/чтения из файла
#include <string> // для работы со строками

using namespace std;


int num_of_args(vector<bool> f) { // получение кол-ва переменных
  int n = log2(f.size());
  return n;
}

vector<bool> read_from_file(string file_name) { // чтение значений из файла
  vector<bool> return_vector; // вектор который возвращаем
  string basic_string;
  ifstream out(file_name);
  if (!out.is_open()) {
    cout << "Ошибка открытия файла!\n";
  } else {
    while (!out.eof()) { // цикл считывания значений
      basic_string = "";
      out >> basic_string;
      if (basic_string == "") continue;
      return_vector.push_back(stoi(basic_string)); // передача значений в вектор
    }
  }
  out.close();     // закрываем файл
  return return_vector;
}

bool write_to_file(std::string file_name, vector<bool> f) { // запись в файл
  ofstream in;
  bool record_result; // возвращаемая переменная
  in.open(file_name, ios::app);
  int i;
  for (i = 0; i < f.size() - 1; i++) {
    in << f[i] << " ";
  }
  in << f[i];
  in.close();
  vector<bool> vector; // дополнительный вектор для проверки совпадения результата записи и исходного
  vector = read_from_file(file_name);
  if (vector == f) {
    record_result = true;
  }

  return record_result;
}

string table(vector<bool> f) {
  string table;
  int num = num_of_args(f);

  for (int i = 1; i <= num; i++) {
    table += "x" + to_string(i) + "\t"; // вывод шапки
  }
  table += "f\n";

  for (int i = 0; i < f.size(); i++) {
    for (int j = 0; j <= num; j++) {
      if (j == num)
        table += to_string(f.at(i));
      else
        table += to_string((bool) (i & (int) (pow(2, (num - j - 1))))) + "\t";
    }
    table += "\n";
  }
  return table;
}

string func_sdnf(std::vector<bool> f) {
  string func("f_sdnf(");
  int num = num_of_args(f); // получаем количество аргументов
  bool has_s_func = false; // используется для обработки, если функция имеет SDNF

  for (int i = 1; i <= num; i++) {
    func += "x" + std::to_string(i);
    if (i != num)
      func += ", ";
  }
  func += ") = ";

  for (int i = 0; i < f.size(); i++) {// перебираем все значения функции
    // SDNF строится только для истинных значений функции!
    if (f.at(i)) { // сообщаем, что функция действительно имеет sdnf
      has_s_func = true;
      func += "(";
      for (int j = 0; j < num; j++) { // пройти по таблице истинности
        // тот же метод получения значения для аргумента, который использовался выше
        bool arguments = (bool) (i & (int) (pow(2, (num - j - 1))));
        // обрабатываем, если значение аргумента ложно
        if (!arguments)
          func += "'";

        func += "x" + std::to_string(j + 1); //выводим элемент формулы
        if (j != num - 1)
          func += " & ";
      }
      func += ") v ";
    }
  }

  return func;
}
