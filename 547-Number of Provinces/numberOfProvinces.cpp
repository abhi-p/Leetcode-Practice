/*
547. Number of Provinces
Medium
6.7K
280
Companies

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

 

Constraints:

    1 <= n <= 200
    n == isConnected.length
    n == isConnected[i].length
    isConnected[i][j] is 1 or 0.
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]
*/

#include <vector>
#include <iostream>

using namespace std;

//Using disjoint set
//Assume number of cities < 2^31 -1 

class disjointSet{
	vector<int> setArr;
	vector<int> rank;
	int numCities;
	int numProvinces;
public:


	disjointSet(int n) : numProvinces(n), numCities(n), setArr(n, 0), rank(n, 1){
		for(int i = 0; i < setArr.size(); i++){
			setArr[i] = i;
		}
	}

	int findRoot(int input){
		while(setArr[input] != input){
			return findRoot(setArr[input]);
		}
		return input;
	}
	
	bool isConnected(int input1, int input2){
		return findRoot(input1) == findRoot(input2);
	}

	void add(int input1, int input2){
		int input1Root = findRoot(input1), input2Root = findRoot(input2);
		if(input1Root == input2Root)
			return;
		setArr[input1Root] = input2Root;
		numProvinces--;
	}

	int getNumProvinces(){
		return numProvinces;
	}
};


int findCircleNum(vector<vector<int>>& isConnected) {
	int numRows = isConnected.size(), numCols = isConnected[0].size();

    disjointSet unionFind(numRows);
	
	for(int i = 0; i < numRows; i++){
		for(int j = 0; j < numCols; j++){
			if(isConnected[i][j])
				unionFind.add(i,j);
		}
	}
	return unionFind.getNumProvinces();
}


int main(){
	vector<vector<int>> inputTest;	

	inputTest = {{1,1,0},{1,1,0},{0,0,1}};

	cout<<findCircleNum(inputTest)<<endl;

	inputTest = {{1,0,0},{0,1,0},{0,0,1}};

	cout<<findCircleNum(inputTest)<<endl;
}
