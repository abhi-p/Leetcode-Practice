#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void dfs_pacific_atlantic(vector<vector<int>>& heights, vector<vector<int>>& grid, int row,int col, int ROWS,int COLS){
  
  if (grid[row][col]!=0)
    return;
  grid[row][col]+=1;

  vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
  
  for (auto dir: dirs){
    int newRow=row+dir.first, newCol=col+dir.second;
    
    if (newRow>=0 && newCol>=0 && newRow<ROWS && newCol<COLS){
      if (heights[row][col]<=heights[newRow][newCol]){
        dfs_pacific_atlantic(heights, grid, newRow, newCol, ROWS, COLS);        
      }      
    }    
  }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
  int ROWS=heights.size();
  int COLS=heights[0].size();   

  vector<int> rowVec(COLS, 0);
  vector<vector<int>> pacificGrid, atlanticGrid, returnVec;

  for (int i = 0; i < ROWS; i++){
    pacificGrid.push_back(rowVec);
    atlanticGrid.push_back(rowVec);
  }
  
  //Iterate over first and last rows
  for(int i = 0; i < COLS; i++){
    dfs_pacific_atlantic(heights, pacificGrid, 0, i, ROWS, COLS);
    dfs_pacific_atlantic(heights, atlanticGrid, ROWS-1, i, ROWS, COLS);

  }
  
  //Iterate over first and last cols
  for(int i = 0; i < ROWS; i++){
    dfs_pacific_atlantic(heights, pacificGrid, i, 0, ROWS, COLS);
    dfs_pacific_atlantic(heights, atlanticGrid, i, COLS-1, ROWS, COLS);

  }
 
  for(int i = 0;  i < ROWS; i++){
    for (int j = 0; j < COLS; j++){
      if(pacificGrid[i][j] != 0 && atlanticGrid[i][j] != 0){
        vector<int> solutionCoord = {i,j};
        returnVec.push_back(solutionCoord);
      }
    }
  }
  return returnVec;
}

int main(){
  
}
