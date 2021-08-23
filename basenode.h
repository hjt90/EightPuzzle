#ifndef BASENODE_H
#define BASENODE_H
#include <vector>

class BaseNode
{
public:
    BaseNode(int status);
    BaseNode() = default;
    BaseNode(const BaseNode &) = default;
    bool operator==(const BaseNode &rhs) const;
    int Parent;
    friend class Astar_search;

protected:
    std::vector<int> push_forward() const;
    int status;

private:
    int zero_space; //0-8
};

#endif // BASENODE_H
