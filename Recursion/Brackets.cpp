#include<bits/stdc++h>
#define w(x) int x;cin>>x;while(x--)
using namespace std;
void generateBrackets(char *output, int n, int index,int obc, int clc)
{
 if(index == 2*n)
 {
 output[index] = '\0';
 cout<<output<<endl;
 return; 
}
if(obc<n)
{
 output[index] = '(';
 generateBrackets(output,n,index+1,obc+1,clc);
}
if(clc<obc)
{
 output[index] = '(';
 generateBrackets(output,n,index+1,obc,clc+1); 
}
  return; 
} 
int main()
{
 w(t)
 {
int n;
cin>>n;
char *output = new char[2*n];
int indx = 0;

 
 }
}
