#include "Func.h"
#include <string>

int num_of_args(vector<bool> f)
{
    return ceil(log2(f.size())); // כמדאנטפל מע ךמכ-גא םאבמנמג
}

vector<bool> read_from_file(string file_name)
{
    std::vector < bool > result;
    std::ifstream file(file_name);
    std::copy(std::istream_iterator<bool>(file), std::istream_iterator<bool>(), std::back_inserter(result));
    return result;
}