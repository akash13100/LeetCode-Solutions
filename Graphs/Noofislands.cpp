#include<bits/stdc++.h>
using namespace std;
vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,1,0,-1}; 
void dfs(vector<vector<int>> &matrix,int sr, int sc,int er,int ec)
{
    if(sr<0 || sc <0 || sr>=er|| sc>=ec)
        return; // Its an out of bounds address
    
    if(matrix[sr][sc] == 0 || matrix[sr][sc] == -1)
        return; // Already discovered;
    
    if(matrix[sr][sc] == 1) // Sink the connected components
    {
        matrix[sr][sc] = -1;
    }
    for(int i = 0; i<4; i++)
    {
        dfs(matrix,sr+dx[i],sc+dy[i],er,ec);
    }
}
int Noofislands(vector<vector<int>> &matrix)
{
    int noofislands = 0;
    int er = (int)matrix.size();
    int ec = (int)matrix[0].size();
    for(int i = 0; i<matrix.size(); i++)
    {
        for(int j = 0; j<matrix[i].size(); j++)
        {
           if(matrix[i][j] == 1)
           {
               dfs(matrix,i,j,er,ec);
               noofislands++;
           }
        }
    }
    return noofislands;
}
int main()
{
cin.tie(NULL);
ios_base::sync_with_stdio(false);
 vector<vector<int>> matrix = {{1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1}};
    cout<<Noofislands(matrix);
    
}
