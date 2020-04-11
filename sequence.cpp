#include<iostream>
#include<algorithm>
using std::sort;

static int arr[1048576];
int main()
{
    int n;
    int k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    std::sort(arr,arr+n);
    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    
    if (k==1)
    {
        printf("%d",arr[n-1]);
    } 
     
    int cur=1;
    for (int i = n-2; i >= 0; i--)
    {

        if (arr[i]+1==arr[i+1])
        {
            ++cur;
        }
        else
        {
            cur=1;
        }   
        if (cur==k)
        {
            printf("%d\n",arr[i]);
            break;
        }
    }
}