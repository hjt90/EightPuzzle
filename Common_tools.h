#ifndef COMMON_TOOLS_H
#define COMMON_TOOLS_H
#include <vector>
#include <time.h>
#include <stdlib.h>

int array2int(int[]);
int vector2int(std::vector<int>);
const std::vector<int> int2vector(int);
std::vector<int> create_random();
double calculate_B(int N, int d);

#endif // COMMON_TOOLS_H
