/*
79. Word Search
Medium

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

 

Constraints:

    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board and word consists of only lowercase and uppercase English letters.

 

Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <utility>

using namespace std;

bool performIterativeDFS(vector<vector<char>>& board, string word, int startRow, int startCol){
	int numRows = board.size(), numCols = board[0].size(), numLetters = word.size();
	stack<pair<int, pair<int, int>>> dfsStack;
	set<pair<int,int>> visitedLetters;

	bool retVal = false;

	dfsStack.push(make_pair(0, make_pair(startRow, startCol)));

	while(!dfsStack.empty()){
		pair<int, pair<int,int>> currLetter = dfsStack.top();
		dfsStack.pop();
		if(visitedLetters.count(currLetter.second) > 0)
			continue;
		else
			visitedLetters.insert(currLetter.second);

		int currRow = currLetter.second.first, currCol = currLetter.second.second, currIndex = currLetter.first;
		cout<<"currIndex: " << currIndex << " board["<<currRow<<"]["<<currCol<<"]: "<< board[currRow][currCol]<<endl;
		if(currIndex >= numLetters)
			continue;

		if(board[currRow][currCol] == word[currIndex]){
			if(currIndex == numLetters-1){
				//cout<<"currIndex: " << currIndex << " board["<<currRow<<"]["<<currCol<<"]: "<< board[currRow][currCol]<<endl;
				retVal = true;
			}
			//continue the DFS
			//Above [row-1][col]
			if(currRow - 1 >= 0)
				dfsStack.push(make_pair(currIndex + 1, make_pair(currRow - 1, currCol)));
			
			//Below [row+1][col]
			if(currRow + 1 < numRows)
				dfsStack.push(make_pair(currIndex + 1, make_pair(currRow + 1, currCol)));

			//Left [row][col-1]
			if(currCol - 1 >= 0)
				dfsStack.push(make_pair(currIndex + 1, make_pair(currRow, currCol - 1)));
			//Right	[row][col+1]
			if(currCol + 1 < numCols)
				dfsStack.push(make_pair(currIndex + 1, make_pair(currRow, currCol + 1)));
		}
		else{
			visitedLetters.erase(currLetter.second);
		}
	}
	return retVal;
}

bool performRecursiveDFS(vector<vector<char>>& board, string& word, int idx, int currRow, int currCol, int numRows, int numCols){
	//Error bounds	
	if(idx > word.size() || currRow < 0 || currRow >= numRows || currCol < 0 || currCol >= numCols || board[currRow][currCol] != word[idx])
		return false;
	//Found last letter in word - return true
	if(board[currRow][currCol] == word[idx] && idx == word.size() - 1)
		return true;

	vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

	bool retVal = false;

	//Mark this location as visited for this recursive path
	char currChar = board[currRow][currCol];
	board[currRow][currCol] = '_';

	for(auto dir : dirs){
		int newRow = currRow + dir[0], newCol = currCol + dir[1];
		retVal |= performRecursiveDFS(board, word, idx + 1, newRow, newCol, numRows, numCols);
	}
	board[currRow][currCol] = currChar;

	return retVal;
}

bool exist(vector<vector<char>>& board, string word) {
	int numRows = board.size(); 
	int numCols = board[0].size();
	cout<<"numRows: "<< numRows << " numCols: " << numCols << endl;
	int numLetters = word.size();

	bool retVal = false;
	
	if(numLetters < 1)
		return false;

	//Run an iterative DFS with the starting node being the first letter of the input word
	char firstLetter = word[0];

	for(int row = 0; row < numRows; row++){
		for(int col = 0; col < numCols; col++){
				//cout<<"board["<<row<<"]["<<col<<"]: "<< board[row][col] << " ";
				if(board[row][col] == firstLetter){
					//retVal |= performIterativeDFS(board, word, row, col);
					retVal |= performRecursiveDFS(board, word, 0, row, col, numRows, numCols);
				}
		}
	}
	return retVal;
}

int main(){

	/*vector<vector<char>> input1 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	string inputWord1 = "find";
	cout<< (exist(input1, inputWord1) == true ? "true" : "false")<<endl;

	vector<vector<char>> input2 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	string inputWord2 = "ABCE";
	cout<< (exist(input2, inputWord2) == true ? "true" : "false")<<endl;

	vector<vector<char>> input3 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	string inputWord3 = "ABCB";
	cout<< (exist(input3, inputWord3) == true ? "true" : "false")<<endl;

	vector<vector<char>> input4 = {{'a','b'},{'c','d'}};
	string inputWord4 = "acdb";
	cout<< (exist(input4, inputWord4) == true ? "true" : "false")<<endl;*/


	vector<vector<char>> input5 = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
	string inputWord5 = "ABCESEEEFS";
	cout<< (exist(input5, inputWord5) == true ? "true" : "false")<<endl;

}







