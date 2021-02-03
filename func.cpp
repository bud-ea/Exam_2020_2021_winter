#include <iostream> // cout cin
#include <vector> // для работы с векторами
#include "func.h"
#include <string> // для работы со строками

using namespace std;

const string file = {"F:\\file.txt"}; // расположение файла1
const string file2 = {"F:\\file2.txt"}; // расположение файла2

vector<bool> f; // вектор по умолчанию

int main() {
  setlocale(0, " ");
  f = read_from_file(file);
  bool tr = write_to_file(file2, f);
  int a = num_of_args(f);
  cout << "1 Задание: " << a << endl;
  cout << "2 Задание: ";
  for (int i = 0; i < f.size(); i++){
    cout << f[i];
  }
  cout << endl;
  cout << "3 Задание:";
  if (tr == 1){
    cout << "True";
  } else{
    cout << "False";
  }
  cout << endl;
  cout << "4 задание: ";
  string string1 = table(f);
  cout << string1;
  cout << endl;
  cout << "5 Задание: ";
  string string2 = func_sdnf(f);
  cout << string2;
}