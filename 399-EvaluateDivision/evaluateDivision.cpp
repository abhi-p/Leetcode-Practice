/*

2You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]

a/b=2    b/c=3

a/(3c) = 2 -> a/c = 6

b/a=0.5
x
|(1)
a -(2)- b
      /(3)
   c
rootArray[i] = rootX;
rootArray[i] = x;
b/x = b/a * a/x


root=[(pair)]

a/c = ? 
b/a = ?
a/e = ?
a/a = ?
x/x = ?

Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]

a/b = 1.5   b/c = 2.5 b/d=5 

a/c=  3.75, c/b=0.4 bc/cd=5, 


Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]

 

Constraints:

    1 <= equations.length <= 20
    equations[i].length == 2
    1 <= Ai.length, Bi.length <= 5
    values.length == equations.length
    0.0 < values[i] <= 20.0
    1 <= queries.length <= 20
    queries[i].length == 2
    1 <= Cj.length, Dj.length <= 5
    Ai, Bi, Cj, Dj consist of lower case English letters and digits.

*/


#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
class DisjointSetQuickUnion{
  
  //int *rootArray;
  //int *rank;
  //["a","b"] => 2.0
  //["b","c"] => 3.0
  
  //intermediateResults['b'] = a/b
  //intermediateResults['c'] = a/c => intermediateResults['b'] * intermediateResults['c'] => 6.0
  //intermediateResults[x] = rootArray[x] / x = 2
  //rootArray[x] = rootArray[rootArray[x]]
  //intermediateResults[x] = rootArray[rootArray[x]] / x = 
  //int *intermediateResults;

	vector<int> rootArray;
	vector<int> rank;
	vector<int> intermediateResults;
  int numNodes = 0;

public:
  void printRootArray(){
    for (int i=0;i<numNodes;i++)
      cout<<"rootArray["<<i<<"]: "<<rootArray[i]<<endl;
    cout<<endl;
 
  }
  
  DisjointSetQuickUnion(int inputNumNodes) : rootArray(inputNumNodes, 0), rank(inputNumNodes, 0), intermediateResults(inputNumNodes,0), numNodes(inputNumNodes) {
    //rootArray = new int[inputNumNodes];
    //rank = new int[inputNumNodes];
    //intermediateResults = new int[inputNumNodes];

    for (int i=0;i<numNodes;i++){
      rootArray[i] = i;
      intermediateResults[i] = rank[i] = 1;
    }
  } 

  
  int find(int x){
    if (x==rootArray[x])
      return x;
    //Path compression - update each node's parent to be root of the connected component
    rootArray[x] = find(rootArray[x]);
    intermediateResults[x] *= intermediateResults[rootArray[x]];
    return rootArray[x];
  }
  
  void unionSet(int x, int y){
    //First check if two inputs are not already connected
    int rootX=find(x);
    int rootY=find(y);
    
    if(rootX == rootY)
      return;
    
    //Choose higher rank to be the new root of newly created connected component
    if (rank[rootX]>rank[rootY]){
      //Connect y's tree to x's tree as a sub-tree
      //intermediateResults[y] = rootX/y => rootX/x * x/y
      intermediateResults[rootY]*=intermediateResults[x]
      rootArray[rootY]=rootX;
    }
    else if(rank[rootY]>rank[rootX]){
      //Connect x's tree to y's tree as a sub-tree
      rootArray[rootX]=rootY;
    }
    else{
      //Connect y's tree to x's tree as a sub-tree
      //By convention as rootX and rootY have the same height/rank
      intermediateResults[y]=intermediateResults[x]*value

      rootArray[rootY]=rootX;
      rank[rootX]++;
    }
  }

  bool connected(int x, int y){
    return find(x) == find(y);
  }    
};
*/
//RootArray stores parent node of node_i
//IntermediateResults[i] = rootArray[i]/i -> the parent of ith node divided by i
class DisjointSetQuickFind{
	vector<int> rootArray;
	vector<double> intermediateResults;
	int numNodes;
	public:
	DisjointSetQuickFind(int n) : rootArray(n,0), intermediateResults(n,1.0), numNodes(n) {
		for(int i = 0; i < n; i++){
			rootArray[i] = i;		
		}
	}
	
	//Returns parent of node
	int find(int node){
		return rootArray[node];
	}
	
	//Value = node1/node2 -> given as input list of values 
	void unionSet(int node1, int node2, double value){
		int rootNode1 = find(node1);
		int rootNode2 = find(node2);
		
		//Both nodes are already pointing to the same parent
		if(rootNode1 == rootNode2)
			return;
		else{
			//Update every node which has rootNode2 to be rootNode1			
			for(int i=0; i < numNodes; i++){
			  if(rootArray[i] == rootNode2){
					rootArray[i] = rootNode1;
					intermediateResults[i] = intermediateResults[node1] * value; 
				}
			}
		}
	}
};


vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	vector<double> retVec;
	map<string, int> variables;
	int var = 0;

	//Mapping string variables to integer nodes
	for(auto equation : equations){
		string firstVar = equation[0];
		string secondVar = equation[1];
		//cout<<"firstVar: "<<firstVar<<" variables.count(firstVar): "<<variables.count(firstVar)<<endl;
		if(variables.count(firstVar) == 0){
			variables[firstVar] = var;
			var+=1;
		}
		if(variables.count(secondVar) == 0){
			variables[secondVar] = var;
			var+=1;
		}
	}
	
	//Debug print variables map
	/*for(auto keyValPair : variables){
		string varName = keyValPair.first;
		int varVal = keyValPair.second;
		cout<<varName <<": " <<varVal<<endl;
	}*/

	
	int numNodes = variables.size();

	DisjointSetQuickFind disjointSet(numNodes);

	
	for(unsigned int i = 0; i < equations.size(); i++){
		string firstVar = equations[i][0];
		string secondVar = equations[i][1];
		int node1 = variables.count(firstVar) == 0 ? -1 : variables[firstVar];
		int node2 = variables.count(secondVar) == 0 ? -1 : variables[secondVar];
		
		int node1 = variables[firstVar], node2 = variables[secondVar];
		
		disjointSet.unionSet(node1, node2, values[i]);
	}
	

	return retVec;
}


int main()
{
	vector<vector<string>> inputEquations;
	vector<double> inputValues;
	vector<vector<string>> inputQueries;
	vector<double> retVec;
	
	//Input 1
	inputEquations = {{"a","b"},{"b","c"}};
	inputValues = {2.0,3.0};
	inputQueries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

	retVec = calcEquation(inputEquations, inputValues, inputQueries);

	//Input 2
	inputEquations = {{"a","b"},{"b","c"},{"bc","cd"}};
	inputValues = {1.5,2.5,5.0};
	inputQueries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};

	retVec = calcEquation(inputEquations, inputValues, inputQueries);


	//Input 3
	inputEquations = {{"a","b"}};
	inputValues = {0.5};
	inputQueries = {{"a","b"},{"b","a"},{"a","c"},{"x","y"}};

	retVec = calcEquation(inputEquations, inputValues, inputQueries);

	return 0;
}

