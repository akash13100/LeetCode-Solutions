#include<bits/stdc++.h>
using namespace std;
vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,1,0,-1}; 
void Floodfillrec(vector<vector<int>> &matrix, int colour, int ri, int ci,int row, int col)
{
  if(i<0 || j<0 || i>row || j>col)
    return;
   
  matrix[ri][ci] = colour;
  for(int i = 0; i<4; i++)
  {
      Floodfillrec(matrix,colour,ri+dx[i],ci+dy[i],row,col);
  }
  return; 
}
void Floodfill(vector<vector<int>> &matrix, int colour, int i, int j)
{
 int row = matrix.size();
 int col = matrix[0].size(); 
 Floodfillrec(matrix,colour,i,j,row,col);
 return; 
} 
