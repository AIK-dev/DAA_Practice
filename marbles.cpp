#include<iostream>
#include<set>
using std::pair;
using std::make_pair;
using std::set;


//typedef pair<int,int> pi;


long long C(int n, int m){
    if(m>n-m) m=n-m;
    
    long long ans=1;
    
    for(int i=0;i<m;i++) ans=ans*(n-i)/(i+1);
    
    return ans;
}

int main(){
    int T,n,k;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&n,&k);
        printf("%lld\n",C(n-1,k-1));
    }
    
    return 0;
}

/* bool findFirstArg(set<pi>data,int value)
{
    set<pi>::iterator it=data.begin();
    while (it!=data.end())
    {
        if ((*it).first==value)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int tests;
    scanf("%d",&tests);

    int i=0;
    while (i++<tests)
    {
        char input[64]{0};
        scanf("%s",input);
        unsigned long k;
        scanf("%lu",&k);

        set<pi> data;
        for (int i = 0; i < 39; i++)
        {
            if (input[i]=='1')
            {
                data.insert(make_pair(i+1,i+1));
            }
        }
        int lastKey;
        int lastValue;
        int newVal;
        for (int i = 0; i < k-1; i++)
        {
            auto iter=data.begin();
            lastKey=(*iter).second;
            lastValue=(*iter).first;
            data.erase(iter);
            newVal=lastKey+lastValue;
            while (findFirstArg(data,newVal))
            {
                newVal+=lastKey;
            }
            data.insert(make_pair(newVal,lastKey));
        }
        auto iter=data.begin();
        printf("%d",(*iter).first);
    }
} */

/*     priority_queue<pi,vector<pi>,greater<pi>> pq;

    
    int greatestPushed=INT32_MIN;
    for (int i = 0; i < 39; i++)
    {
        if (input[i]=='1')
        {
            pq.push(make_pair(i+1,i+1));
            if (i+1<greatestPushed)
            {
                greatestPushed=i+1;
            }
            
        }
    }
    //int answer=pq.top().first;
    //printf("%d",answer);

    int k;
    scanf("%d",&k);
    int lastKey;
    int lastValue;
    int newValue;
    for (int i = 1; i < k; i++)
    {
        lastKey=pq.top().second;
        lastValue=pq.top().first;
        pq.pop();
        newValue=lastValue+lastKey;
        while (greatestPushed==newValue)
        {
            newValue+=lastKey;
        }
        if (greatestPushed<=newValue)
        {
            greatestPushed=newValue;
        }
        pq.push(make_pair(newValue,lastKey));
    }
    int answer=pq.top().first;
    printf("%d",answer); */
    
/*     pq.push(make_pair(10,200));
    pq.push(make_pair(20,100));
    pq.push(make_pair(15,400)); */
