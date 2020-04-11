#include<iostream>
#include<vector>
#include<chrono>
using std::vector;

std::pair<int,int> maxSub(std::vector<int>&arr)
{
    int resSum=-(1<<30);
    std::pair<int,int> resIndecies;


    for (int i = 0; i < arr.size(); i++)
    {
        int current=arr[i];
        std::pair<int,int>indecies;
        indecies.first=i;
        indecies.second=i;
        
        for (int j = i+1; j < arr.size(); j++)
        {
            if (current>resSum)
            {
                resSum=current;
                resIndecies.second=indecies.second;
            }
        }
    }
    return resIndecies;
    
}

std::tuple<int,int,int> findMaxCrossing(vector<int>&arr,int begin,int middle,int end)
{
    int recordLeft=-(1<<30);
    int currentLeft=0;
    int bestLeftIndex;
    for (int i = middle; i >= begin; i--)
    {
        currentLeft+=arr[i];
        if (currentLeft>recordLeft)
        {
            recordLeft=currentLeft;
            bestLeftIndex=i;
        }
    }
    int recordRight=-(1<<30);
    int currentRight=0;
    int bestRightIndex;
    for (int i = middle ; i < end; i++)
    {
        currentRight+=arr[i];
        if (currentRight>recordRight)
        {
            recordRight=currentRight;
            bestRightIndex=
        }
        
    }
    
    
}

int main()
{
    std::vector<int>numbers;
    auto start1=std::chrono::system_clock::now();
    auto sol1=maxSub(numbers,0,numbers.size());
    auto duration=std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()-start1);
    std::cout<<"Duration is "<<duration.count()<<"\n\n";

    auto start2=std::chrono::system_clock::now();
    auto sol2=maxSub(numbers,0,numbers.size());
    auto duration=std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()-start1);
    std::cout<<"Duration is "<<duration.count()<<"\n";
}