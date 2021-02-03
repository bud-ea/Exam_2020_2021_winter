#pragma once
#include <iostream>		//дл€ работы с вводом и выводом в консоль
#include <vector>		//дл€ работы с векторами
#include <string>		//дл€ работы со строками
#include <fstream>		//дл€ работы с файлами
#include <cmath>		//std::log
#include <algorithm>	//std::reverse


int num_of_args(std::vector<bool> f);

std::vector<bool> read_from_file(std::string file_name);

bool write_to_file(std::string file_name, std::vector<bool> f);

std::string table(std::vector<bool> f);

std::string func_sdnf(std::vector<bool> f);

std::string func_sknf(std::vector<bool> f);

std::string func_Zhegalkin(std::vector<bool> f);