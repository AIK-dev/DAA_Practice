#include<iostream>
#include<cmath>
using std::cin;
using std::cout;

int main()
{
    float numbers[65540];
    int index=0;

    char inp[1024]{0};
    fgets(inp,1020,stdin);
    float f;
    while (inp[0]!='\0'&&inp[0]!='\n')
    {
        f=std::stof(inp);
        numbers[index]=sqrt(f);
        index++;
        fgets(inp,1020,stdin);
    }
    for (int i = index-1; i >= 0; --i)
    {
        printf("%f\n",numbers[i]);
    }
    
    return 0;
}