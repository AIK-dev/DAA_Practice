#include<iostream>
#include<cmath>
using std::pow;
using std::sqrt;

int fib(int n) { 
  double phi = (1 + sqrt(5)) / 2; 
  return round(std::pow(phi, n) / sqrt(5)); 
} 

int compress(int a[],int n)
{
  if (n==0)
  {
    return 0;
  }

  int j=1;
  for (int i = 1; i < n; i++)
  {
    if (a[i]!=a[i-1])
    {
      a[j++]=a[i];
    }
  }
  return j;
}
template<class T>
void swap(int &a,int&b)
{
  int temp=a;
  a=b;
  b=temp;
}

void inplMerge(int x[],int y[],int n,int m)
{
  for (int i = 0; i < m; i++)
  {
    int first=0;
    if (x[i]<y[0])
    {
      swap(x[i],y[0]);
    }
    for (int j = 0; first < n&&y[first]>y[i]; j++)
    {
      y[j-1]=y[j];
    }
    
  }
  
}

int main()
{
  int a[]={  1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 7 };
  int n=sizeof(a)/sizeof(a[0]);
  int m=compress(a,n);
  for (int i = 0; i < m; i++)
  {
    printf("%d",a[i]);
  }
  
}