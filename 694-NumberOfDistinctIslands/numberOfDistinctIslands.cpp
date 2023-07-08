/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Return the number of distinct islands.

 

Example 1:


Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
Output: 1
Example 2:


Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

void dfs(vector<vector<int>>& grid,int curRow, int curCol, int ROW, int COL, string &path, char curDir){
  
  if (curCol>=COL || curRow>=ROW || curCol<0 || curRow<0 || grid[curRow][curCol]!=1)
    return;
  
  //Mark curr space as visited
  grid[curRow][curCol] = -1;
  
  path.push_back(curDir);
  
  vector<vector<int>> dirs = {
                              {-1,0},//up
                              {1,0},//down
                              {0,-1},//left
                              {0,1},//right
  };
  vector<char> charDirs = {'U','D','L','R'};

  for(int i = 0; i < dirs.size(); i++){
    int newRow = curRow + dirs[i][0], newCol = curCol + dirs[i][1];
    
    dfs(grid, newRow, newCol, ROW, COL, path, charDirs[i]);
  }
  path.push_back('B');

}

int numDistinctIslands(vector<vector<int>>& grid) {

  int rows=grid.size();
  int cols=grid[0].size();
  unordered_set<string> uniqueIslands;
  string path;
  
  for (int row=0;row<rows;row++){
    for (int col=0;col<cols;col++){
      if (grid[row][col]==1){
        path = "";
        dfs(grid, row, col, rows, cols, path, 'D');
        cout<<path<<endl;
        uniqueIslands.insert(path);
      }
    }
  }

  return uniqueIslands.size();
}

int main(){
  vector<vector<int>> inputGrid;
  
  inputGrid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
  cout<<numDistinctIslands(inputGrid)<<endl;
  
  inputGrid = {{1,1,0,1,1},{1,0,0,0,0},{0,0,0,0,1},{1,1,0,1,1}};
  cout<<numDistinctIslands(inputGrid)<<endl;
  
  inputGrid = {{1,1,0},{0,1,1},{0,0,0},{1,1,1},{0,1,0}};
  cout<<numDistinctIslands(inputGrid)<<endl;

}
