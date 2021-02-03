#include "func.h"
#include <string>

int num_of_args(vector<bool> f)
{
    return ceil(log2(f.size()));
    // логарифм от количества наборов 
}

vector<bool> read_from_file(string file_name)
{
    vector < bool > result; // для записи текста
    ifstream file(file_name);
    copy(istream_iterator<bool>(file), istream_iterator<bool>(), back_inserter(result));
    return result;
}
