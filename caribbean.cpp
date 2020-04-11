#include<iostream>
#include<vector>
using std::vector;

typedef vector<vector<vector<int>>>no;
typedef vector<vector<int>> cpp11;
typedef vector<int> qq;

inline void optimize()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

class Path
{
private:
    vector<vector<vector<vector<int>>>> paths;
    unsigned cities;
    const unsigned mod=1000003;
    unsigned find(unsigned island,unsigned x,unsigned y,unsigned z)
    {
        if (x+y+z==0)
        {
            return island!=0;
        }
        if (paths[x][y][z]!=-1)
        {
            return paths[x][y][z][island];
        }
        unsigned res=0;
        if (island!=0&&x>0)
        {
            res+=x*(find(0,x-1,y,z));
        }
        if (island!=1&&y>0)
        {
            res+=y*find(1,x,y-1,z);
        }
        if (island!=2&&z>0)
        {
            res+=z*find(2,x,y,z-1);
        }
        return paths[x][y][z][island]=res%mod;
    }
public:
    Path(unsigned int cities):
        paths(cities+1,no(cities+1,cpp11(cities+1,qq(3,-1)))),
        cities(cities)
        {}
    unsigned int find()
    {
        return find(0,cities-1,cities,cities);
    }
};

int main()
{
    optimize();
    unsigned cities;
    scanf("%u",&cities);
    printf("%u\n",Path(cities).find());
    return 0;
}
