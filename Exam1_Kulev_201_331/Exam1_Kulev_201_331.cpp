#include "Half1.h"
#include "Half2.h"
#include <iostream>

void runHalf1();
void runHalf2();

int main()
{
    //runHalf1();
    runHalf2();

    return 0;
}

void runHalf2()
{
    std::string roman("MCMLXXXIV");
    printf_s("Roman (%s) to arabic: %d\n", roman.c_str(), roman_to_arab(roman));

    int pK = 3;
    printf_s("Pascal triangle for k = %d:\n", pK);
    for (int i : func_Pascal(pK))
    {
        printf_s("%d ", i);
    }

    printf_s("\n");

    std::string seq("longest word in the universe");
    printf_s("Longest sequence of \"%s\" is %d\n", seq.c_str(), func_substr_len(seq));
}

void runHalf1()
{
    std::vector<bool> vec = { false, true, true, false, false, true, false, false };
    printf_s("num_of_args: %d\n", num_of_args(vec));

    // PLEASE CHANGE FILE NAME!
    std::string filePathIn("D:\\vec.txt");
    printf_s("Reading vector from: %s\n", filePathIn.c_str());
    std::vector<bool> inpVec = read_from_file(filePathIn);
    for (bool b : inpVec)
    {
        printf_s("%d ", b);
    }
    printf_s("\n");

    // PLEASE CHANGE FILE NAME!
    std::string filePathOut("D:\\vec_out.txt");
    printf_s("Writing vector to: %s\n", filePathOut.c_str());
    bool result = write_to_file(filePathOut, vec);
    printf_s("Write result: %d (%s)\n", result, result ? "success" : "error");

    std::string fTable = table(vec);
    printf_s("Table:\n%s\n", fTable.c_str());

    printf_s("%s\n", func_sdnf(vec).c_str());
    printf_s("%s\n", func_sknf(vec).c_str());
}