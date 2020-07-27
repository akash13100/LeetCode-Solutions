#include<bits/stdc++.h>
using namespace std;
// Substrings multiple ways
void substringutil(string s, vector<string> &substrings)
{
     if(s.size()==0)
    {
    substrings.pb(" ");
    return;
    }
    
    char x = s[0];
    substringutil(s.substr(1),substrings);
    int n = (int)substrings.size();
    for(int i = 0; i<n; i++)
    {
        string s = x + substrings[i];
        substrings.push_back(s);
    }
    return;
}
vector<string> Substrings(string s)
{
    vector<string> substrings;
    substringutil(s,substrings);
    return substrings;
}
// Substrings another way
void GenerateSubsequences(char *input, char *output, int i, int j)
{
     if(input[i]=='\0')
     {
         output[j] = '\0';
         cout<<output;
         return;
     }
    output[j]  = input[i];
    GenerateSubsequences(input,output,i+1,j+1);
    // Second base case
    GenerateSubsequences(input,output,i+1,j); // Overwrite the position.
}
