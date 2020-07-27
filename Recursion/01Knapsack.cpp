#include<bits/stdc++.h>
using namespace std;
// 0-1 Knapsack problem using dynamic Programming or Using backtracking
int Profit(int n, int c,int *wt, int *prices)
{
    if( n==0 || c == 0)
        return 0; // No profit can be made;
  
    // Recursive call;
    
    int inc,exc;
    inc = exc = INT_MIN; // we need to compute the max profit.
    /*if(c-wt[n-1]>=0)
    {
    inc = prices[n-1] + Profit(n-1,c-wt[n-1],wt,prices);
    }
    exc = Profit(n-1,c,wt,prices); // Remaining n-1 items;
    return max(inc,exc);
     */
    if(c-wt[0]>=0)
    {
        inc = prices[0] + Profit(n-1, c-wt[0],wt+1,prices+1);
    }
    exc = Profit(n-1,c,wt+1,prices+1);
    return max(inc,exc);
}
