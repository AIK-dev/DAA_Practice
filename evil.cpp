#include<iostream>
#include<algorithm>
#include<stack>
using std::stack;
using std::sort;
using std::cout;
using std::min;
using std::max;

struct Interval 
{ 
    int start, end; 
}; 
  
// Compares two intervals according to their staring time. 
// This is needed for sorting the intervals using library 
// function std::sort(). See http://goo.gl/iGspV 
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
} 
  
// The main function that takes a set of intervals, merges 
// overlapping intervals and prints the result 
int mergeIntervals(Interval arr[], int n) 
{ 
    // Test if the given set has at least one interval 
    if (n <= 0) 
        return 0; 
  
    // Create an empty stack of intervals 
    stack<Interval> s; 
  
    // sort the intervals in increasing order of start time 
    sort(arr, arr+n, compareInterval); 
  
    // push the first interval to stack 
    s.push(arr[0]); 
  
    // Start from the next interval and merge if necessary 
    for (int i = 1 ; i < n; i++) 
    { 
        // get interval from stack top 
        Interval top = s.top(); 
  
        // if current interval is not overlapping with stack top, 
        // push it to the stack 
        if (top.end < arr[i].start) 
            s.push(arr[i]); 
  
        // Otherwise update the ending time of top if ending of current 
        // interval is more 
        else if (top.end < arr[i].end) 
        { 
            top.end = arr[i].end; 
            s.pop(); 
            s.push(top); 
        } 
    } 
  
    int acc=0;
    // Print contents of stack 
    while (!s.empty()) 
    { 
        Interval t = s.top();
        acc+=(t.end-t.start+1);
        s.pop(); 
    } 
    return acc; 
} 
  
// Driver program  
static Interval arr[1000002];
int main()  
{ 
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d",&arr[i].start,&arr[i].end);
    }

    //Interval arr[] = { {2,5}, {9,9}, {3,7} };  
    //int n = sizeof(arr)/sizeof(arr[0]);  
    printf("%d",mergeIntervals(arr, m));  
    return 0;  
}  