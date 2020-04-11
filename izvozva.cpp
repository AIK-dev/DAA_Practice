#include<iostream>
#include<algorithm>
#include<vector>
using std::vector;

inline void optimize()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

class UnionFind
{
private:
    vector<unsigned>root;
    vector<unsigned>rank;
    unsigned components;
public:
    UnionFind(unsigned items):
        root{items},rank{items},components{items}
    {
        for (unsigned i = 0; i < components; i++)
        {
            root[i]=i;
        }
    }

    void connect(unsigned it,unsigned other)
    {
        unsigned int root_i=find(it);
        unsigned int root_j=find(other);

        if (root_i==root_j)
        {
            return;
        }
        if (rank[root_i]<rank[root_j])
        {
            root[root_i]=root_j;
        }
        else
        {
            root[root_j]=root_i;
            if (rank[root_i]==rank[root_j])
            {
                ++rank[root_i];
            }
        }
        --components;
    }
    unsigned find(unsigned item)
    {
        unsigned curr=item;
        while (curr!=root[curr])
        {
            curr=root[curr];
        }
        while (item!=curr)
        {
            unsigned parent=root[item];
            root[item]=curr;
            item=parent;
        }
        return curr;
    }
    bool connected(unsigned int item,unsigned int other)
    {
        return find(item)==find(other);
    }
};

struct Edge
{
    unsigned source;
    unsigned destination;
    unsigned weight;
};
bool operator>(const Edge&left,const Edge&right)
{
    return left.weight>right.weight;
}

unsigned maxWeight(vector<Edge>&edges,unsigned n)
{
    UnionFind set(n);
    std::sort(edges.begin(),edges.end(),std::greater<Edge>());
    unsigned currWeight=edges.front().weight;

    for (unsigned i = 0,added=0; added < n-1; i++)
    {
        if (!set.connected(edges[i].source,edges[i].destination))
        {
            set.connect(edges[i].source,edges[i].destination);
            currWeight=std::min(currWeight,edges[i].weight);
            ++added;
        }
        
    }
    return currWeight;
}


int main()
{
    optimize();
    unsigned n;
    unsigned m;
    scanf("%u%u",&n,&m);
    vector<Edge> edges(m);

    for (unsigned i = 0; i < m; i++)
    {
        scanf("%u%u%u",&edges[i].source,&edges[i].destination,&edges[i].weight);
    }
    printf("%u\n",maxWeight(edges,n));
}
