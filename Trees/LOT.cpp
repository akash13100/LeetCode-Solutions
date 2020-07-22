#include<iostream>
#include<bits/stdc++.h> 
class TreeNode 
{
 TreeNode *left;
 TreeNode *right;
 int val;
 TreeNode(int x)
 {
val = x;
} 
};
class Solution
{ 
vector<vector<int>> LevelOrderTraversal(TreeNode *root)
{
 vector<vector<int>> res;
 vector<int> curlevel;
 queue<TreeNode*> q;
 q.push(root);
 q.push(NULL):
 while(q.emty())
{
TreeNode *front = q.front();
q.pop();
if(front == NULL)
{
res.push_back(curlevel);
curlevel.clear();
if(q.empty())
break;
else
q.push(NULL); 
}
else
{
curlevel.push_back(front->val);
   if(front->left)
q.push(front->left);
   if(front->right)
q.push(front->right);
}
}
return res; 
}
};
