#include "basenode.h"
#include "Common_tools.h"

int changeId[9][4] = {{-1, -1, 3, 1}, {-1, 0, 4, 2}, {-1, 1, 5, -1}, {0, -1, 6, 4}, {1, 3, 7, 5}, {2, 4, 8, -1}, {3, -1, -1, 7}, {4, 6, -1, 8}, {5, 7, -1, -1}};

BaseNode::BaseNode(int sta) : Parent(0), status(sta)
{
    int num = sta;
    this->zero_space = 0;
    for (int i = 0; i < 9; i++)
    {
        if (num % 10 == 0)
            this->zero_space = 8 - i;
        num /= 10;
    }
}

bool BaseNode::operator==(const BaseNode &rhs) const
{
    return this->status == rhs.status;
}

/* *
 * lenth: 4
 * up, left, down, right
 * 1~8 if exists
 * -1 ifnot
 * */
std::vector<int> BaseNode::push_forward() const
{
    std::vector<int> res;
    const std::vector<int> base = int2vector(this->status);
    std::vector<std::vector<int>> forward = {base, base, base, base};
    for (int i = 0; i < 4; i++)
    {
        int a = changeId[this->zero_space][i];
        if (a != -1)
        {
            a = forward[i][a];
            forward[i][changeId[this->zero_space][i]] = 0;
            forward[i][this->zero_space] = a;
            res.emplace_back(vector2int(forward[i]));
        }
        else
            res.emplace_back(-1);
    }
    return res;
}
