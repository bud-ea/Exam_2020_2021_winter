#pragma once
#include <vector> // used to work with vector data struct
#include <string> // used to work with strings :)

/// <summary>
/// Get number of arguments for function
/// </summary>
/// <param name="f">Vector of function's values</param>
/// <returns>Number of arguments of function. 0 returned if number of values is not power of 2</returns>
int num_of_args(std::vector<bool> f);

/// <summary>
/// Read bool vector from file
/// Values of vector must be separated by space
/// </summary>
/// <param name="file_name">Path to file</param>
/// <returns>Set of values from file</returns>
std::vector<bool> read_from_file(std::string file_name);

/// <summary>
/// Writes values from vector to file
/// </summary>
/// <param name="file_name">Path to file</param>
/// <param name="f">Set of values</param>
/// <returns>If write succeed</returns>
bool write_to_file(std::string file_name, std::vector<bool> f);

/// <summary>
/// Construct truth table for set of values for function
/// </summary>
/// <param name="f">Value set</param>
/// <returns>Truth table</returns>
std::string table(std::vector<bool> f);

/// <summary>
/// Construct sdnf by function value set
/// </summary>
/// <param name="f">Value set</param>
/// <returns>SDNF for function if it's set of values is valid</returns>
std::string func_sdnf(std::vector<bool> f);

/// <summary>
/// Construct sknf by function value set
/// </summary>
/// <param name="f">Value set</param>
/// <returns>SKNF for function if it's set of values is valid</returns>
std::string func_sknf(std::vector<bool> f);
std::string func_Zhegalkin(std::vector<bool> f);