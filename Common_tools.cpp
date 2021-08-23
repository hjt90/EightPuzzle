#include "Common_tools.h"
#include <algorithm>
#include <math.h>

int array2int(int array[])
{
    int res = 0;
    for (int i = 0; i < 9; i++)
    {
        res *= 10;
        res += array[i];
    }
    return res;
}

int vector2int(std::vector<int> array)
{
    int res = 0;
    for (int i = 0; i < 9; i++)
    {
        res *= 10;
        res += array[i];
    }
    return res;
}

const std::vector<int> int2vector(int num)
{
    std::vector<int> res;
    for (int i = 0; i < 9; i++)
    {
        res.emplace_back(num % 10);
        num /= 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

std::vector<int> create_random()
{
    bool vis[9] = {0};
    std::vector<int> res;
    int tmp;
    for (int i = 0; i < 9;)
    {
        tmp = rand() % 9;
        if (!vis[tmp])
        {
            vis[tmp] = 1;
            res.push_back(tmp);
            i++;
        }
    }
    return res;
}

static inline long double calculate_dd(long double i, int d)
{
    long double res = 1, tmp = 1;
    for (int j = 1; j <= d; j++)
    {
        tmp *= i;
        res += tmp;
    }
    return res;
}

double calculate_B(int N, int d)
{
    long double left = 1, right = 100;
    long double mid_tmp, mid;
    while (abs(right - left) > 1e-4)
    {
        mid = (left + right) / 2;
        mid_tmp = calculate_dd(mid, d);
        if (N < mid_tmp)
            right = mid;
        else
            left = mid;
    }
    return double(left);
}
