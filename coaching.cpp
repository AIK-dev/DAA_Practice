#include<iostream>

bool comparator(char x,char y){
	if(x>='a'&&x<='z'&&y>='A'&&y<='Z') return true;
        else if(x>='A'&&x<='D'&&y>='a'&&y<='z')return false;
	else return (x<y);
}
void quickSort(char* a, int n)
{
	int i = 0, j = n - 1;
	char x = a[n / 2];
	char y;
	do
	{
		while (comparator(a[i] ,x))
		{
			++i;
		}
		while (comparator(x,a[j]))
		{
			--j;
		}
		if (i<j)
		{
			y = a[i]; a[i] = a[j]; a[j] = y;
			++i; --j;
		}
		else
		{
			if (i==j)
			{
				++i; --j;
			}
		}
	} while (i<=j);
	if (j>0)
	{
		quickSort(a, j+1);
	}
	if (i<n-1)
	{
		quickSort(a + i, n - i);
	}
}

int main()
{
  /*  long arrSize;
    scanf("%ld",&arrSize);
    if (arrSize<=0)
    {
        printf("Err\n");
    }
    static char inp[10000000];//[16777216];
    scanf("%s",inp);
    //std::sort(inp,inp+arrSize,comparator);
    quickSort(inp, arrSize);
    for (int index = 1; index < arrSize; ++index)
        printf("%c", inp[index]);
        printf("\n");
        return 0;  */
}
/* 20
Abcabc12345ABCDE1234

15
Apd8S92Sa1ASSiL
 */
void printArray(char* input, int inputSize)
{
    if (inputSize > 0) printf("%c", input[0]);
    for (int index = 1; index < inputSize; ++index)
        printf("%c", input[index]);
    printf("\n");
}