#include<iostream>

int main()
{
    int m,n,k;
    scanf("%d %d %d" ,&m,&n,&k); //We had %k here...

    int*a=new int[m*n]{0};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i*n+j]);
        }
    }
    printf("\nTrying to print a\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",a[i*n+j]);
        }
        printf("\n");
    }
    int *b=new int[n*k]{0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d",&b[i*k+j]);//there was a here...
        }
    }
        printf("\nTrying to print b\n");

        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            printf("%d ",b[i*k+j]);
        }
        printf("\n");
    }

    int*res=new int[m*k]{0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
                res[i*k+j] = 0;
                for (int c = 0; c < n; c++)
                       res[i*k+j] += a[i*k+c] * b[c*k+j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            printf("%d ",res[i*k+j]);
        }
        printf("\n");
    }

/*     int i, size;
    int *v;
    scanf("%d", &size);
    v = new int[size];
    for(i=0; i < size; i++)
    scanf("%d", &v[i]);

    for (int i = 0; i < size; i++)
    {
        printf("%d",v[i]);
    } */
    
}