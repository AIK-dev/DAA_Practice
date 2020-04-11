#include<iostream>
#include<vector>
using std::vector;

void inline optimize()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

int main()
{
    optimize();

    unsigned size;
    scanf("%u",&size);

    vector<int>seq(size);

    for (unsigned i = 0; i < size; i++)
    {
        scanf("%d",&seq[i]);
    }

    unsigned long long result=size;

    for (unsigned end = 0; end < size-1; end++)
    {
        unsigned start=end;
        for (; end < size-1&&seq[end]==seq[end+1]; end++)
        {
        }
        unsigned long long len=end-start+1;
        result+=len*(len-1)/2;
    }
    printf("%llu",result);

    return 0;
}