/*
994. Rotting Oranges
Medium

You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2.

*/


#include <iostream>
#include <queue>
#include <climits>
#include <utility>
#include <unordered_set>

using namespace std;

int runBFS(vector<vector<int>> &inputGrid, int startI, int startJ){
  deque<pair<int, pair<int,int>>> bfsQueue;
  unordered_set<pair<int,int>> visitedNodes;
  
  int numRows = inputGrid.size();
  int numCols = inputGrid[0].size();
  int returnVal = 0;
  int currentDist = 0;

  bfsQueue.push_back(make_pair(0, make_pair(startI, startJ)));
  
  while(!bfsQueue.empty()){
    pair<int, pair<int,int>> currentLocation = bfsQueue.front();
    
    int currentDist = currentLocation.first;
    int i = currentLocation.second.first, j = currentLocation.second.second;
    bfsQueue.pop_front();
    
    if(visitedNodes.count(currentLocation.second) == 0 && inputGrid[i][j] != 0){
      visitedNodes.insert(currentLocation.second);
      
      //Populate adjacent nodes into bfsQueue
      
      //Above node: [i-1][j]
      if(i - 1 > 0){
        bfsQueue.push_back(make_pair(currentDist + 1, make_pair(i-1, j)));
      }
      
      //Below node: [i+1][j]
      if(i + 1 < numRows){
        bfsQueue.push_back(make_pair(currentDist + 1, make_pair(i+1, j)));
      }
      
      //Left node: [i][j-1]
      if(j - 1 > 0){
        bfsQueue.push_back(make_pair(currentDist + 1, make_pair(i, j-1)));
      }
      
      //Right node: [i][j+1]
      if(j + 1 < numCols){
        bfsQueue.push_back(make_pair(currentDist + 1, make_pair(i, j+1)));
      }
      
      //Check if currentNode is a fresh orange
      if(inputGrid[i][j] == 1){
        returnVal = currentDist;
      }
    }
  }
  return returnVal;
}

int orangesRotting(vector<vector<int>>& grid) {
  
  //go through input grid - for each rotten orange, run bfs, keep track of last fresh orange found
  // compare last fresh orange across all iterations of bfs
  // return highest length of fresh orange
  
  int numRows = grid.size();
  int numCols = grid[0].size();
  int globalFurthestFreshOrange = 0;//INT_MAX;
  
  for(int i = 0; i < numRows; i++){
    for(int j = 0; j < numCols; j++){
      if(grid[i][j] == 2){
        //Run BFS on this orange
        int currFurthestFreshOrange = runBFS(grid, i, j);
        if(currFurthestFreshOrange < globalFurthestFreshOrange){
          globalFurthestFreshOrange = currFurthestFreshOrange;
        }
      }
    }
  }
  return globalFurthestFreshOrange;
}

int main()
{
    vector<vector<int>> inputGrid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << orangesRotting(inputGrid) <<endl;
    //std::cout << "Practice makes Perfect!" << std::endl;
    return 0;
}
