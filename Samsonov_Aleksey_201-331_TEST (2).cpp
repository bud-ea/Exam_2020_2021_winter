#include "Samsonov_Aleksey_201-331_TEST.h"// подключаем h.file

int num_of_args(std::vector<bool> f)
{
	return (int)log2(f.size());//берем логарифм от количества значений, 0 1 0 1 size=4 log2_2=4
}