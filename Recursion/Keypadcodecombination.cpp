// MOST OPTIMAL :) 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Phone keypad problem using recursion
// You hacve to generate all possible strings from a number given to you
void Phonekeypadutil(int n, vector<string> &res, unordered_map<int,string> &m)
{
    //
    if(n==0)
    {
        res.push_back("");
        return;
    }
    
    int ld = n%10;
    n/=10;
    Phonekeypadutil(n,res,m);
    string characters = m[ld];
    // Now I solve for the problem.
    int x = (int)res.size();
    for(int j = 1; j<characters.size(); j++)
    {
        int i = 0;
        while(i<x) // Making copies of the small output;
        {
            res.push_back(res[i]);
            i++;
        }
    }
    int i = 0;
    for(int j = 0; j<characters.size(); j++)
    {
        int k = 0;
        while(k<x)
        {
            char toappend = characters[j];
            k++;
            res[i] = res[i] + toappend;
            i++;
        }
    }
    return;
}
vector<string> Phonekeypadcombination(int n)
{
    unordered_map<int,string> m;
    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tuv";
    m[9] = "wxyz";
    vector<string> res;
    Phonekeypadutil(n,res,m);
    return res;
}
