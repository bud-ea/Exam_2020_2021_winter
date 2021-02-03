#include "Pavlov_K.h"
#include <iostream>
#include <vector>

using namespace std;
int Pavlov_K::num_of_args(vector<bool> f)
{
	int n = 0;
	while (pow(2, n) != f.size())
		n++;
	return n;
}

