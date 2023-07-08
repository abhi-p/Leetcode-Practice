#include <iostream>
#include <queue>

using namespace std;

/*
https://leetcode.com/problems/number-of-islands/

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.

*/

void runBFS(int rowNum, int colNum, vector<vector<char>>& grid, int numRows, int numCols){
    deque<pair<int,int>> bfsQueue;
    bfsQueue.push_back(make_pair(rowNum,colNum));

    while(!bfsQueue.empty()){
        pair<int,int> currCoords = bfsQueue.front();
        bfsQueue.pop_front();
		int currRow = currCoords.first, currCol = currCoords.second;

        //cout << "currRow: " << currRow << " currCol: " << currCol;

        if(grid[currRow][currCol] == '1'){
			//Mark already visited nodes as '2'
            grid[currRow][currCol] = '2';

            //Check boundary conditions
            //Left hand node
            if(currCol > 0)
                bfsQueue.push_back(make_pair(currRow, currCol - 1));
            //Right hand node
            if(currCol + 1 < numCols)
                bfsQueue.push_back(make_pair(currRow, currCol + 1));

            //node above
            if(currRow > 0)
                bfsQueue.push_back(make_pair(currRow - 1, currCol));
            //node below
            if(currRow + 1 < numRows)
                bfsQueue.push_back(make_pair(currRow + 1, currCol));
        }
    } 

}

int numIslands(vector<vector<char>>& grid) {
    int numRows = grid.size(), numCols = grid[0].size(), numIslands = 0;

    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            if(grid[i][j] == '1'){
                numIslands++;
                runBFS(i, j, grid, numRows, numCols);
            }
        }
    }

    return numIslands;
}

void printInputGrid(vector<vector<char>> &grid){
	int numRows = grid.size(), numCols = grid[0].size();

	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){
			cout<<" " << grid[i][j];
		}
		cout<<endl;	
	}
}

int main()
{
	vector<vector<char> > inputGrid1 = {
										{'1','1','1','1','0'},
										{'1','1','0','1','0'},
										{'1','1','0','0','0'},
										{'0','0','0','0','0'}
										};

	printInputGrid(inputGrid1);

    cout << "numberOfIslands: " << numIslands(inputGrid1) << endl;

	vector<vector<char> > inputGrid2 = {
										{'1','1','1','0','0'},
										{'1','1','0','1','0'},
										{'1','1','0','0','0'},
										{'0','0','0','0','0'}
										};
	printInputGrid(inputGrid2);

    cout << "numberOfIslands: " << numIslands(inputGrid2) << endl;

	vector<vector<char> > inputGrid3 = {
										{'1','1','0','0','0'},
										{'1','1','0','1','0'},
										{'1','0','1','0','0'},
										{'0','0','0','1','1'}
										};
	printInputGrid(inputGrid3);

	cout << "numberOfIslands: " << numIslands(inputGrid3) << endl;

    return 0;
}
