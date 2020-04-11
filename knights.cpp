#include<iostream>
#include<queue>
#include<set>
#include<unordered_map>
using std::unordered_map;
using std::set;
using std::queue;

inline void optimize()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };


int field[2048][2048]{0};
std::pair<int,int> knights[2048];

// Check if (x, y) is valid chess board coordinates
// Note that a knight cannot go out of the chessboard
bool valid(int x, int y,int N)
{
	if (x < 0 || y < 0 || x >= N || y >= N||field[x][y]==1)
		return false;

	return true;
}

struct Node
{
    int x, y,dist;
    Node(int x,int y,int dist=0):x{x},y{y},dist{dist}
    {}
    bool operator<(const Node&o)const{
        return x<o.x||(x==o.x&&y<o.y);
    }
};

int BFS(Node src,Node dest,int N)
{
    set<Node>visited;
    queue<Node>q;
    q.push(src);
    while (!q.empty())
    {
        Node node=q.front();
        q.pop();
        int x=node.x;
        int y=node.y;
        int dist=node.dist;
        if (x==dest.x&&y==dest.y)
        {
            return dist+1;
        }
        if (!visited.count(node))
        {
            visited.insert(node);
            for (int i = 0; i < 8; i++)
            {
                int x1=x+row[i];
                int y1=y+col[i];
                if (valid(x1,y1,N))
                {
                    q.push({x1,y1});
                }
                
            }
        }
        
    }
    return 0;
    //return INT32_MIN;  
}


int main()
{
    optimize();


    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int x,y;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d",&x,&y);
        field[x][y]=1;
    }

    for (int i = 0; i < k; i++)
    {
        scanf("%d%d",&x,&y);
        knights[i]=std::make_pair(x,y);
    }

    int princessX,princessY;
    scanf("%d%d",&princessX,&princessY);
    Node dst{princessX,princessY};
    if (k<=0)
    {
        std::exit(3);
    }
    
    Node start{knights[0].first,knights[0].second};
    //Solution???
    int maxTime=BFS(start,dst,n);

    int survivalCount=maxTime>0?1:0;
    for (int i = 1; i < k; i++)
    {
        start.x=knights[i].first;
        start.y=knights[i].second;
        int currTime=BFS(start,dst,n);
        if (currTime>0)
        {
            survivalCount++;
            if (maxTime<currTime)
            {
                maxTime=currTime;
            }
            
            //maxTime=maxTime<currTime?currTime:maxTime;
        }

    }
    printf("%d %d",survivalCount,maxTime);
}