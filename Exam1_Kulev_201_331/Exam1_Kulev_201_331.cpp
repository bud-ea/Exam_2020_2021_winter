#include "Half1.h"
#include <iostream>

int main()
{
    std::vector<bool> vec = {false, true, true, false, false, true, false, false};
    //printf_s("num_of_args: %d\n", num_of_args(vec));

    /*std::string filePathIn("D:\\vec.txt");
    printf_s("Reading vector from: %s\n", filePathIn.c_str());
    std::vector<bool> inpVec = read_from_file(filePathIn);
    for (bool b : inpVec)
    {
        printf_s("%d ", b);
    }
    printf_s("\n");

    std::string filePathOut("D:\\vec_out.txt");
    printf_s("Writing vector to: %s\n", filePathOut.c_str());
    bool result = write_to_file(filePathOut, vec);
    printf_s("Write result: %d (%s)\n", result, result ? "success" : "error");*/

    std::string fTable = table(vec);
    printf_s("Table:\n%s\n", fTable.c_str());

    printf_s("%s\n", func_sdnf(vec).c_str());


    return 0;
}