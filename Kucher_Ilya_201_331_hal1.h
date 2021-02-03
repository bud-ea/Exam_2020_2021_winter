#pragma once
#include <vector>
#include <string>

int num_of_args(std::vector<bool> f);
std::vector<bool> read_from_file(std::string file_name);
bool write_to_file(std::string file_name, std::vector<bool> f);
std::string table(std::vector<bool> f);

