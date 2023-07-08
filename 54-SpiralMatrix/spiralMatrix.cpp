#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <limits> //INT_MAX = 2^32 -1 

using namespace std;

void readVec(vector<int> vec){
  for (int i=0;i<vec.size();i++){
    cout<<vec[i]<<", ";
    
  }
  cout<<endl;
}
/*
void recursiveSpiralOrder(vector<vector<int>>& matrix, int startRow, int startCol, vector<int>& retVec, int numRows, int numCols){
  
  //pop spiral order into retVec
  
  if (startRow>numRows || startCol>numCols){
    cout<<"("<<startRow<<","<<numRows<<"),("<<startCol<<","<<numCols<<")"<<endl;
    return;
  }
  int i = 0, j = 0;
  //iterate over first row
  i = startRow;
  for (j=0;j < numCols; j++){
    retVec.push_back(matrix[i][j+startCol]);
  }
  
  //iterate over last col
  j = numCols-1 + startCol;
  for(i = 1; i < numRows; i++){
    retVec.push_back(matrix[i + startRow][j]);
  }
  
  //iterate over last row
  i = numRows-1 + startRow;
  for(j = numCols - 1; j > startCol; j--){
    retVec.push_back(matrix[i][j + startCol - 1]);
  }
  
  //iterate over first col
  j = startCol;
  for(i = numRows - 1; i > startRow+1; i--){
    retVec.push_back(matrix[i + startRow-1][j]);
  }
  
  recursiveSpiralOrder(matrix, startRow+1, startCol+1, retVec, numRows-2, numCols-2);
}
*/

void recursiveSpiralCopy(const vector<vector<int>>& inputMatrix, int currRow, int currCol, int numRows, int numCols, vector<int>& returnVec){
	int i = currRow, j = currCol;
	//Base case: if currRow >= numRows || currCol >= numCols - return
	if(currRow >= numRows || currCol >= numCols)
		return;

	//4 for loops
	//Iterate over top row: i: currRow, 				j = currCol -> numCols - 1
	//Iterate over last col: i: currRow -> numRows - 1, j: numCols - 1
	//Iterate over last row: i: numRows - 1,			j: numCols - 1 -> currCol
	//Iterate over first col:i: numRows - 1 -> currRow	j: currCol
	
	//Iterate over top row
	i = currRow;
	for(j = currCol; j < numCols; j++){
		returnVec.push_back(inputMatrix[i][j]);	
	}

	//Iterate over last col
	//Start i at currRow + 1 to avoid duplicating top right hand corner element 
	j = numCols - 1;
	for(i = currRow+1; i < numRows; i++){
		returnVec.push_back(inputMatrix[i][j]);
	}	
	
	//Iterate over last row:
	//Start j at numCols - 2 to avoid duplicating bottom right hand corner element
	i = numRows - 1;
	if(i != currRow) {
		for(j = numCols - 2; j >= currCol; j--){
			returnVec.push_back(inputMatrix[i][j]);
		}
	}

	//Iterate over first col
	//Start i at numRows - 2 to avoid duplicating bottom left hand corner element
	j = currCol;
	if(j != numCols -1) {
		for(i = numRows - 2; i > currRow; i--){
			returnVec.push_back(inputMatrix[i][j]);
		}
	}
	recursiveSpiralCopy(inputMatrix, currRow + 1, currCol + 1, numRows - 1, numCols - 1, returnVec); 
	return;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int numRows = matrix.size(), numCols = matrix[0].size();
  vector<int> retVec;
  recursiveSpiralCopy(matrix, 0, 0, numRows, numCols, retVec);
  readVec(retVec);
  return retVec;
}


int main()
{
  vector<vector<int>> matrix;
  matrix = {{1,2,3},{4,5,6},{7,8,9}};
  spiralOrder(matrix);
  //Output: [1,2,3,6,9,8,7,4,5]
 
  matrix = {{1,2,3,35},{4,5,6, 65},{7,8,9, 95},{10,11,12, 64},{13,14,15, 84}};
  /*
   
    {1, 2, 3,  35}
    {4, 5, 6,  65}   //numRows=3, startRow=1 startCol=1. numCol=2
    {7, 8, 9,  95}
    {10,11,12, 64}
    {13,14,15, 84}
    */
	//ouput   [1,2,3,35,65,95,64,84,15,14,13,10,7,4,5,6,9,12,11,8]
  spiralOrder(matrix);
  
  matrix = {{1,2,3, 4},{5,6,7,8},{9,10,11,12}};
  spiralOrder(matrix);

  /*output:  [1,2,3,4,8,12,11,10,9,5,6,7]

    {1, 2, 3, 4},
    {5, 6, 7, 8}, //numRows=1,startRow=1,numCols=2,startCol=1
    {9,10,11,12}}
  */
  matrix = {{7},{9},{6}};
  spiralOrder(matrix);

/*  
   {{7},
    {9}, 
    {6}}
   Expected :[7,9,6]*/
  //spiralOrder(matrix);

  return 0;
}

