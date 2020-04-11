#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using std::vector;
using std::pair;
using std::make_pair;
//using namespace std;

struct Date
{
    int day;
    int month;
    int year;

    void print()const
    {
        printf("%d.%d.%d\n",day,month,year);
    }
    bool operator<(const Date&d2)
    {
        return magic()<d2.magic();
    }
    long int magic() const { return static_cast<long int>(month * 100 + day + year * 10000);}
};

/* bool compare(const Date&d1,const Date&d2)
{
    return d1.magic()<d2.magic();
} */


int main()
{
     Date arr[256];
    int n;
    scanf("%d",&n);
    char pt='\0';
    for (int i = 0; i < n; i++)
    {
        scanf("%d%c%d%c%d",&arr[i].day,&pt,&arr[i].month,&pt,&arr[i].year);
    } 
/*     std::sort(arr,arr+n);
    for (int i = 0; i < n; i++)
    {
        arr[i].print();
    } */
     
     vector<pair<Date,int>>vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back(make_pair(arr[i],i));
    }
    printf("Sorting?\n"); 
    std::sort(vp.begin(),vp.end(),[](auto&left,auto&right){return left.first<right.first});
    for (int i = 0; i < n; i++)
    {
        vp[i].first.print();
    }  
    
}