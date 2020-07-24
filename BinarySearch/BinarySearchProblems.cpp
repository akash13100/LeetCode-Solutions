#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
#define pb push_back
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define inf INT_MAX 
#define all(v) v.begin(),v.end()
#define pop pop_back
#define for(a,b,c) for(int i = a; i<b; i+=c)
#define for2(a,b,c) for(int i = a; i>=b; i-=c)
#define w(x) int x;cin>>x; while(x--)
// Binary Search
int BinarySearch(vector<int> &nums, int target)
{
    if(nums.size()==0)
        return -1;
    int l = 0;
    int r = (int)nums.size()-1;
    while(l<r)
    {
        int mid = l + (r-l)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid]<target)
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}
// Upper bounds and lowers bound of the element in the STL;
pair<int,int> FirstLastoccurence(vector<int> &nums, int target)
{
     // Finding out the first occurence of the element
    int l = 0;
    int r = (int)nums.size()-1;
    int lb = 0;
    while(l<r)
    {
        int mid = l + (r-l)/2;
        if(nums[mid] == target)
        {
            lb = mid;
            r = mid-1;
        }
        else if(nums[mid]<target)
            l = mid+1;
        else
            r = mid-1;
    }
    l = 0;
    r = (int)nums.size()-1;
    int ub = 0;
    while(l<r)
    {
        int mid = l + (r-l)/2;
        if(nums[mid] == target)
        {
            ub = mid;
            l = mid+1;
        }
        else if(nums[mid]<target)
            l = mid+1;
        else
            r = mid-1;
    }
    return make_pair(lb,ub);
}
// Pivot in sorted and rotated array Classic Binary Search Problem 
// 
