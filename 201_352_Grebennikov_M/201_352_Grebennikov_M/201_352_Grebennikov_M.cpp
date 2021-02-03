#include <iostream>
#include <math.h>
#include <vector>
#include "func.h"

using namespace::std;

int main()
{
	string ss = "C:\sil\zxc.txt";
	vector<bool> g;
	g = read_from_file(ss);
	for (int i = 0; i < g.size(); i++)
		cout << g[i] << ' ';

}