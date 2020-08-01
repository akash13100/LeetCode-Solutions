//
//  main.cpp
//  HashingGFG
//
//  Created by Akash Sehgal on 13/06/20.
//  Copyright © 2020 Akash Sehgal. All rights reserved.
//

#include <iostream>
#include<string>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<list>
#define pb push_back
#define inf INT_MAX
#define all(x) x.begin(),x.end();
#define w(x) int x; cin>>x; while(x--)
#define mod 1000000007
#define setbits(x) __builtin_popcount(x)
#define ll long long
//#define for(a,b,c) for(int i = a; i<b; i+=c)
using namespace std;
// Hashmaps Leetcode and gfg
class TODOList
{
    public :
    /*
   8)Count maximum points on same line.
  15) Given an array of pairs, find all symmetric pairs in it
     
     */
};
class TreeNode
{
    public :
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
void PrintBinaryTreeVerticalorder(TreeNode *root)
{
    queue<pair<TreeNode*,int>> q;
    // Vertical distance from the center of the root;
    q.push(make_pair(root,0));
    pair<TreeNode*,int> p = make_pair(nullptr,0);
    q.push(p);
    // Do a level order traversal
    map<int,vector<TreeNode*>> mp;
    while(!q.empty())
    {
        auto front = q.front();
        q.pop();
        if(front.first == NULL)
            continue; // Skip this iteration, this just indicates a new level in the tree.
        else
        {
            mp[front.second].push_back(front.first);
            if(front.first->left)
            {
                q.push(make_pair(front.first->left,front.second-1));
            }
            if(front.first->right)
            {
                q.push(make_pair(front.first->right,front.second+1));
            }
        }
    }
    // Print the hashmap stored elements;
}
// If arr2 is a subset of arr1
// Store the elements in a hashmap and traverse, if not found return false else return true;
class Node
{
    public :
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};
// Union and intersection of 2 linkedlist
pair<vector<int>,Node*> UnionandIntersectionof2lists(Node *head1, Node *head2)
{
// Complete function. Pretty simple.
    vector<int> res;
    return make_pair(res,nullptr);
}
// Target sum
// Given an array find values that sum to a particular target
pair<int,int> Targetsum(vector<int> &nums,int target )
{
    // std::sort and 2 pointer
    // hashmap based approach
    unordered_map<int,int> mp;
    for(int i = 0; i <nums.size(); i++)
    {
        int search = nums[i] - target;
        if(mp.count(search)>0)
        {
            return {nums[i],search};
        }
        else
            mp.insert(make_pair(nums[i],1));
    }
    return {inf,inf};
}
// To do : min operations to make array elements same
int Minoperationstohomogenize(vector<int> &nums)
{
    // Approach :
    /*
     Basically find the most frequent element in the array and then you can compute the elements operations
     The no of operations will be equal to the number of elements in the array - the most frequent elements

     */
    unordered_map<int,int> m;
    for(int i = 0; i<nums.size(); i++)
    {
        m[nums[i]++];
    }
    int maxfreq = INT_MIN;
    for(auto it : m)
    {
        maxfreq = max(maxfreq,it.second);
    }
    return (int)nums.size()-maxfreq;
}
int Maxdistancebetweemsimilarelements(vector<int> &nums)
{
    unordered_map<int,int> m;
    // Map is going to srtore the index of the element along with its value.
    int mxdist = 0;
    for(int i = 0; i<nums.size(); i++)
    {
         if(m.count(nums[i]) > 0 )
         {
             int dist = i+1-m[nums[i]];
             mxdist = max(dist,mxdist);
         }
        else
            m.insert(make_pair(nums[i],i+1));
    }
    return mxdist;
}
// Find symmetric pairs in an array.
// Very similar just has the first element to the second and check.
// Amazon coding problem
void GroupAnagrams(vector<int> &words)
{
     // You need to group anagrams, need to couple the words with the same set of characters
    vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string,vector<string>> m;
    for(int i = 0; i<strs.size(); i++)
    {
        string sorted(strs[i]);
        std::sort(sorted.begin(),sorted.end());
        m[sorted].push_back(strs[i]);
    }
    vector<vector<string>> res;
    for(auto it : m)
    {
        res.push_back(it.second);
    }
    return res;
}
}
int main(int argc, const char * argv[]) {
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    
}

