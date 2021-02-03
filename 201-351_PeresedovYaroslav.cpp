#include "201-351_PeresedovYaroslav.h"

vector<bool> read_from_file(string file_name, vector<bool> f)
{
    
}

int num_of_args(vector<bool> f)
{
    return(
        int(
                log(double(f.size())) / log(2.0) //логарифм длины вектора по основанию 2 
            )

        );
}


int main()
{
    vector <bool> test1{ 1, 0, 0, 1, 1, 1, 1, 1};
    cout << num_of_args(test1);
}

