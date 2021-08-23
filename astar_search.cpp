#include <time.h>
#include <math.h>
#include <algorithm>
#include "astar_search.h"
#include "Common_tools.h"
using namespace std;

CountH_Type Astar_Node::type = CountH_Type::Euclid;
std::vector<int> Astar_Node::goal;

Astar_Node::Astar_Node(int status, int ceng) : BaseNode(status), G(ceng)
{
    F = ceng + this->CountH();
}

bool Astar_Node::operator>(const Astar_Node &rhs) const
{
    return (this->F == rhs.F) ? this->G > rhs.G : this->F > rhs.F;
}

bool Astar_Node::operator==(const Astar_Node &rhs) const
{
    return this->status == rhs.status;
}

bool Astar_Node::operator==(const int &rhs) const
{
    return this->status == rhs;
}

int Astar_Node::CountH() const
{
    double H = 0;
    const vector<int> base = int2vector(this->status);
    int i, j;
    switch (this->type)
    {
    default:
    case CountH_Type::Euclid:
        for (i = 0; i <= 8; i++)
        {
            for (j = 0; j <= 8; j++)
            {
                if (this->goal[j] == base[i])
                    break;
            }
            H += sqrt(pow((i % 3 - j % 3), 2) + pow((i / 3 - j / 3), 2));
        }
        break;
    case CountH_Type::HVdist:
        for (i = 0; i <= 8; i++)
        {
            for (j = 0; j <= 8; j++)
            {
                if (this->goal[j] == base[i])
                    break;
            }
            H += (abs(i % 3 - j % 3) + abs(i / 3 - j / 3));
        }
        break;
    case CountH_Type::Simple:
        for (i = 0; i < 9; i++)
        {
            if (base[i] != this->goal[i])
                H++;
        }
        break;
    case CountH_Type::BFS:
        break;
    }
    return (int)H;
}

void Astar_Node::display() const
{
    const vector<int> base = int2vector(this->status);
    for (int i = 0; i < 9; i++)
    {
        ;
    }
    return;
}

Astar_search::Astar_search(int start, int goal, CountH_Type type) : step(0), extern_pos(1)
{
    Astar_Node::type = type;
    Astar_Node::goal = int2vector(goal);
    OPEN_List.push(Astar_Node(start, 0));
}

/**
 * return step, extern_pos if exist
 * */
std::vector<int> Astar_search::start_search()
{
    clock_t start_clk = clock();
    vector<int> res;
    int goal_num = vector2int(Astar_Node::goal);
    while (!OPEN_List.empty())
    {
        Astar_Node now_pos = OPEN_List.top();
        if (now_pos.status == goal_num)
        {
            CLOSE_List.push_back(now_pos);
            clock_t end_clk = clock();
            int cost_time = (end_clk - start_clk);
            int open_length = this->OPEN_List.size();
            res.push_back(cost_time);
            res.push_back(now_pos.G);
            res.push_back(extern_pos);
            res.push_back(open_length);
            return res;
        }
        OPEN_List.pop();
        vector<int> next = now_pos.push_forward();
        for (int i = 0; i < 4; i++)
        {
            if (next[i] != -1)
            {
                this->extern_pos++;
                Astar_Node tmp(next[i], now_pos.G + 1);
                auto pos = find(CLOSE_List.begin(), CLOSE_List.end(), tmp);
                if (pos != CLOSE_List.end())
                {
                    continue;
                }

                tmp.Parent = now_pos.status;
                OPEN_List.push(tmp);
            }
        }
        CLOSE_List.push_back(now_pos);
    }
    res.push_back(-1);
    return res;
}

std::vector<int> Astar_search::show_path()
{
    vector<int> res;
    auto pos = CLOSE_List.end() - 1;
    while (pos != CLOSE_List.end())
    {
        res.push_back(pos->status);
        pos = find(CLOSE_List.begin(), CLOSE_List.end(), pos->Parent);
    }
    reverse(res.begin(), res.end());
    return res;
}

void Astar_search::clear()
{
    CLOSE_List.clear();
    while (!OPEN_List.empty())
        OPEN_List.pop();
    step = 0;
    extern_pos = 1;
    return;
}

bool Astar_search::check_ok(int start, int goal)
{
    vector<int> init_v = int2vector(start);
    vector<int> goal_v = int2vector(goal);
    int init_pre = 0, goal_pre = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (init_v[j] < init_v[i] && init_v[j] * init_v[i])
                init_pre++;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (goal_v[j] < goal_v[i] && goal_v[j] * goal_v[i])
                goal_pre++;
        }
    }
    if (goal_pre % 2 == init_pre % 2)
        return 1;
    else
        return 0;
}
