/*
329. Longest Increasing Path in a Matrix
Hard
7.5K
111
company
Google
company
DoorDash
company
Amazon
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],
                 [6,6,8],
                 [2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
*/

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>>matrix);

int recursiveDFS(vector<vector<int>>& matrix, int currRow, int currCol, vector<vector<int>>& dpArray){
  int numRows = matrix.size(), numCols = matrix[0].size();

  if(dpArray[currRow][currCol] != 0)
    return dpArray[currRow][currCol];
  
  vector<vector<int>> directions = {
                                    {-1,0}, //above
                                    {0,-1}, //left
                                    {1,0}, //below
                                    {0,1}}; //right
  int currPath = 0;
  for(auto dir : directions){
    int newRow = currRow + dir[0];
    int newCol = currCol + dir[1];


    if (newRow >= 0 && newCol >= 0 && newRow < numRows && newCol < numCols){
       int res = 1;
       if (matrix[newRow][newCol] > matrix[currRow][currCol]) {
          res += recursiveDFS(matrix, newRow, newCol, dpArray);
       }
       currPath = max(currPath, res);
    }
  }
  dpArray[currRow][currCol] = currPath;
  return dpArray[currRow][currCol];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
  int numRows = matrix.size(), numCols = matrix[0].size(), maxPath = 1;

  vector<vector<int>> dpArray;
  
  vector<int> temp(numCols,0);
  
  for(int i = 0; i < numRows; i++)
    dpArray.push_back(temp);

  for (int i = 0; i<numRows; i++){
    for (int j = 0; j < numCols; j++){
     
     maxPath = max(maxPath, recursiveDFS(matrix,i,j,dpArray));
   
    }
  }
  //printMatrix(dpArray);
  return maxPath;
}

void printMatrix(vector<vector<int>>matrix){
  for (auto row: matrix){
    for (auto elem: row){
      cout<<elem<<", ";
      
    }
    cout<<endl;
    
  }
  
}


int main()
{
  
    vector<vector<int>> input;
    int ret;
  
    input = {{9,9,4},{6,6,8},{2,1,1}};
    ret = longestIncreasingPath(input);
    cout<<ret<<endl;
//  [[3,4,5],
//   [3,2,6],
  // [2,2,1]]

    input = {{3,4,5},{3,2,6},{2,2,1}};
    ret = longestIncreasingPath(input);
  
    cout<<ret<<endl;
    return 0;
}
