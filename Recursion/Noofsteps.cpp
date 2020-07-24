#include<bits/stdc++.h> 
using namespace std;
int Noofsteps(int n)
{
     // Base case
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    
    int res = 0;
    for(int i = 1; i<4; i++)
    {
        res += Noofsteps(n-i);
    } // Dp problem.
    return res;
}
int Noofstepsdp(int n)
{
 vector<int> dp(n+1,1);
 for(int i = 1; i<=n; i++)
{
  int temp = 0;
  if(i-1>=0)
  temp+=dp[i-1];
  if(i-2>=0)
  temp+=dp[i-2];
  if(i-3>=0)
  temp+=dp[i-3];
  dp[i] = temp;  
 }
 return dp[n]; 
 } 
