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


//Assume all nodes are ints in int32 range [-2^31, 2^31 - 1]

//Use quickunion implementation of disjointSet with path compression (inside find) and rank (inside unionSet)

class DisjointSetQuickUnion{

  public: 
  //rootArray[i] = parent of node i
  vector<int> rootArray;
  //rank[i] = distance to connected component's root
  vector<int> rank;
  //intRes[i] = rootArray[i] / i = values[i]
  vector<double> intRes;
  int numNodes;
  
  DisjointSetQuickUnion(int n) : numNodes(n), rootArray(n, 1), rank(n, 1), intRes(n, 1.0) {
    //initialize rootArray, rank intermediateResults
    for(int i = 0; i < numNodes; i++){
      rootArray[i] = i;
    }
  }
  
  
  int find(int x, double& accumulator){
   // cout<<"x: " << x << " accumulator: "<<accumulator <<" intRes[x]: " << intRes[x]<<endl;
      //With path compression
    if (x==rootArray[x])
        return x;
      //Path compression - update each node's parent to be root of the connected component
      rootArray[x] = find(rootArray[x], accumulator);

      intRes[x] *= accumulator;
      accumulator=intRes[x];

      return rootArray[x];
    //Without path compression
    //return rootArray[x];
    
  }

  void unionSet(int x, int y, double value){
    //First check if two inputs are not already connected
    double accumulation = 1.0;
    int rootX=find(x, accumulation);
    accumulation = 1.0;
    int rootY=find(y, accumulation);
    
    //Note: if two nodes are already connected - what do we do with the new value?
    if(rootX == rootY)
      return;

    //Choose higher rank to be the new root of newly created connected component
    if (rank[rootX]>rank[rootY]){
      //Connect y's tree to x's tree as a sub-tree
      //intermediateResults[y] = rootX/y => rootX/x * x/y
      double temp = intRes[y]; 
      intRes[y]=intRes[x]*value;
      intRes[rootY]=intRes[y]/temp;

      //intRes[rootY]=intRes[x]*value;
      rootArray[rootY]=rootX;
    }
    else if(rank[rootY]>rank[rootX]){
      //Connect x's tree to y's tree as a sub-tree
      //intermediateResults[x] = rootY/x => rootX/x * x/y

      double temp = intRes[x]; 
      intRes[x]=intRes[y]/value;
      intRes[rootX]=intRes[x]/temp;

      //intRes[x]=intRes[y]/value;
      rootArray[rootX]=rootY;
    }
    else{
      //Connect rootY's tree to rootX's tree as a sub-tree
      //By convention as rootX and rootY have the same height/rank
      intRes[rootY]=(intRes[x]*value)/intRes[y];

      rootArray[rootY]=rootX;
      rank[rootX]++;
    }
  }
  
  bool connected(int x, int y){
    double accumulation = 1.0;
    int rootX = find(x, accumulation);
    accumulation = 1.0;
    int rootY = find(y, accumulation);

    return rootX == rootY;
  }
  
  double intResGet(int x){
    return intRes[x];
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
  /*
	for(auto keyValPair : variables){
		string varName = keyValPair.first;
		int varVal = keyValPair.second;
		cout<<varName <<": " <<varVal<<endl;
	}*/

	int numNodes = variables.size();
  cout<<"numNodes: "<<numNodes<<endl;
	DisjointSetQuickUnion disjointSet(numNodes);

	for(unsigned int i = 0; i < equations.size(); i++){
		string firstVar = equations[i][0];
		string secondVar = equations[i][1];
		int node1 = variables.count(firstVar) == 0 ? -1 : variables[firstVar];
		int node2 = variables.count(secondVar) == 0 ? -1 : variables[secondVar];
		
    //both node1 and node2 should exist in the variables map
      //something went horribly wrong if they dont
		
		disjointSet.unionSet(node1, node2, values[i]);
	}
  
  
  //Debug - print rootArray and intRes array
  cout<<"rootArray:"<<endl;
  for (auto root: disjointSet.rootArray){
    cout<<root<<", ";
  }

  
  for(unsigned int i = 0; i < queries.size(); i++){
		string firstVar = queries[i][0];
		string secondVar = queries[i][1];
		int node1 = variables.count(firstVar) == 0 ? -1 : variables[firstVar];
		int node2 = variables.count(secondVar) == 0 ? -1 : variables[secondVar];
    
    //if either node1 and node2 dont exist in the variables map
    //we havent got a equation using that variable in the equations array
    if(node1 == -1 || node2 == -1){
      retVec.push_back(-1.0);
    }
    else if (!disjointSet.connected(node1,node2)){
      retVec.push_back(-1.0);
    }
    else{
      
      double intRes = 1.0/disjointSet.intResGet(node1) * disjointSet.intResGet(node2);
      retVec.push_back(intRes);
    }
	}
	
  cout<<endl<<"intermediateResults:"<<endl;

  for (auto res: disjointSet.intRes){
    cout<<res<<", ";
  }
  cout<<endl;
  
  cout<<"retVec: "<<endl;
  for (auto ret: retVec){
    cout<<ret<<", ";
  }
  cout<<endl;
  

	return retVec;
}

int main()
{
  vector<vector<string>> inputEquations;
  vector<vector<string>> inputQueries;
  vector<double> inputValues; 
  vector<double> output;

  //Ex. 1
  inputEquations = {{"a","b"},{"b","c"}};
  inputValues = {2.0,3.0};
  inputQueries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
  output = calcEquation(inputEquations, inputValues, inputQueries);
  //expectedOutput: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
  
  //Ex. 2  
  inputEquations = {{"a","b"},{"b","c"},{"bc","cd"}};
  inputValues = {1.5,2.5,5.0};
  inputQueries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
  output = calcEquation(inputEquations, inputValues, inputQueries);
  //expected output: [3.75000,0.40000,5.00000,0.20000]
                    
  //Ex. 3
  inputEquations = {{"a","b"}};
  inputValues = {0.5};
  inputQueries = {{"a","b"},{"b","a"},{"a","c"},{"x","y"}};
  output = calcEquation(inputEquations, inputValues, inputQueries);
  //expected output: [0.50000,2.00000,-1.00000,-1.00000]

  
  //Test Case# 15 on leetcode
  inputEquations = {{"a","e"},{"b","e"}};
  inputValues = {4.0,3.0};
  inputQueries = {{"a","b"},{"e","e"},{"x","x"}};
  output = calcEquation(inputEquations, inputValues, inputQueries);
  //expected output: [1.33333,1.00000,-1.00000]
  
  //Test Case# 16 on leetcode
  inputEquations = {{"a","b"},{"e","f"}, {"b", "e"}};
  inputValues = {3.4,1.4,2.3};
  inputQueries = {{"b","a"},{"a","f"},{"f","f"},{"e","e"},{"c","c"},{"a","c"},{"f","e"}};
  output = calcEquation(inputEquations, inputValues, inputQueries);
  //expected output:[0.29412,10.94800,1.00000,1.00000,-1.00000,-1.00000,0.71429]
  
  //Test Case# 20 on leetcode
  inputEquations = {{"a","b"},{"c","b"},{"d","b"},{"w","x"},{"y","x"},{"z","x"},{"w","d"}};
  inputValues = {2.0,3.0,4.0,5.0,6.0,7.0,8.0};
  inputQueries = {{"a","c"},{"b","c"},{"a","e"},{"a","a"},{"x","x"},{"a","z"}};
  output = calcEquation(inputEquations, inputValues, inputQueries);
  //expected output:[0.66667,0.33333,-1.00000,1.00000,1.00000,0.04464]
  
  //Test Case# 23 on leetcode
  inputEquations = {{"a","b"},{"c","d"},{"e","f"},{"a","c"},{"f","c"}};
  inputValues = {2.0,3.0,4.0,5.0,1.0/6.0};
  inputQueries = {{"c","e"}};
  output = calcEquation(inputEquations, inputValues, inputQueries);
  //expected output:[1.5]
  //output: 0.2

  return 0;
}

