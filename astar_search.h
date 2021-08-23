#ifndef ASTAR_SEARCH_H
#define ASTAR_SEARCH_H
#include <vector>
#include <queue>
#include <time.h>
#include "basenode.h"

enum class CountH_Type : int
{
    Euclid = 0,
    HVdist,
    Simple,
    BFS
};

class Astar_Node : protected BaseNode
{
public:
    Astar_Node(int status, int G);
    Astar_Node() = default;
    Astar_Node(const Astar_Node &) = default;
    bool operator>(const Astar_Node &rhs) const;
    static CountH_Type type;
    static std::vector<int> goal;
    friend class Astar_search;
    bool operator==(const Astar_Node &rhs) const;
    bool operator==(const int &rhs) const;

protected:
    int F;
    int G;

private:
    int CountH() const;
    void display() const;
};

class Astar_search
{
public:
    Astar_search(int start, int goal, CountH_Type type);
    std::vector<int> show_path();
    std::vector<int> start_search();
    void clear();
    static bool check_ok(int start, int goal);

protected:
    std::vector<Astar_Node> CLOSE_List;
    std::priority_queue<Astar_Node, std::vector<Astar_Node>, std::greater<Astar_Node> > OPEN_List;

private:
    int step;
    int extern_pos;
};

#endif // ASTAR_SEARCH_H
