#include<iostream>
#include<vector>
using std::vector;
using std::min;



inline void optimize()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

constexpr unsigned mod=5741;

unsigned int genTickets(unsigned digits,unsigned sum)
{
    vector<vector<unsigned>>sub(digits,vector<unsigned>(sum+1));    

    for (unsigned i = 0; i <= min(9u,sum); i++)
    {
        sub[0][i]=1;
    }

    for (unsigned i = 1; i < digits;i++)
    {
        for (unsigned j = 0; j <= sum; j++)
        {
            for (unsigned digit = 0; digit <= 9; digit++)
            {
                if (j>=digit)
                {
                    sub[i][j]+=sub[i-1][j-digit];
                    sub[i][j]%=mod;
                }
                
            }
        }
    }
    
    return (sub[digits-1][sum]*sub[digits-1][sum])%mod;
}

int main()
{
    optimize();
    unsigned int digits;
    unsigned int sum;
    scanf("%u%u",&digits,&sum);
    if (sum%2!=0)
    {
        printf("0");
    }
    else
    {
        printf("%u",genTickets(digits,sum/2));
    }
    printf("\n");
    
    return 0;
}