#pragma once
#include <vector> // used to work with vector data struct
#include <string> // used to work with strings :)

/// <summary>
/// Get number of arguments for function
/// </summary>
/// <param name="f">Vector of function's values</param>
/// <returns>Number of arguments of function. 0 returned if number of values is not power of 2</returns>
int num_of_args(std::vector<bool> f);
std::vector<bool> read_from_file(std::string file_name);
bool write_to_file(std::string file_name, std::vector<bool> f);
std::string table(std::vector<bool> f);
std::string func_sdnf(std::vector<bool> f);
std::string func_sknf(std::vector<bool> f);
std::string func_Zhegalkin(std::vector<bool> f);