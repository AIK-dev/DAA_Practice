#include<iostream>
#include<algorithm>
using std::sort;


//Reduce the problem 

int minimumElement(int arr[],int n)
{
    int result=INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]<result)
        {
            result=arr[i];
        }
    }
    return result-1;
}

void reduction(int arr[],int n)
{
    int shiftUp=abs(minimumElement(arr,n));
    for (int i = 0; i < n; i++)
    {
        arr[i]+=shiftUp;
    }
    //SortPositiveNums;
    std::sort(arr,arr+n);

    int shiftDown=shiftUp;
    for (int i = 0; i < n; i++)
    {
        arr[i]-=shiftDown;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void printArr(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void reductionExample(int a[],int n)
{
    int*b=new int[n]{0};
    if (!b)
    {
        exit(-1);
    }
    int p=n;
    int s=-1;
    for (int k = 0; k < n; k++)
    {
        if (a[k]>0)
        {
            p--;
            b[p]=a[k];
        }
        else if(a[k]<0)
        {
            s++;
            b[s]=-a[k];
        }
    }
    sort(b,b+s+1);
    sort(b+p,b+n);
    printArr(b,s+1);
    printArr(b+p,b+n);

/*     for (int k = 0; k <= s; k++)
    {
        a[k]=-b[s-k];
    }
    for (int k = s+1; k <= p-1; k++)
    {
        a[k]
    } */
    

    delete[]b;
}

int main()
{
    int a[]={20,10,0,-2,8,-1,0,-6,90,20,-2,0};
    int n=sizeof(a)/sizeof(a[0]);
    reductionExample(a,n);
}