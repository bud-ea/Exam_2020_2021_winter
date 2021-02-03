#include <iostream> // cout cin
#include <vector> // для работы с векторами
#include <math.h> // для математических операций

using namespace std;

vector<bool> f = {0, 0, 0, 1, 1, 0, 1, 1};

int num_of_args(vector<bool> f) {
    int n = log2(f.size()); //длинна = 2^n -> n = log2(длинна вектора)
    return n;
}

int main() {
    int n = num_of_args(f);
    cout << n;
}