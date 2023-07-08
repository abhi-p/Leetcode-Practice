/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.



Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
1:[2,4,5]
2:[1,3]
3:[2,4]
4:[1,3]
5:[1]


visited:{1,2,3,4,5}

firstEdge = [1,2]
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

void performDFS(map<int, unordered_set<int>> &adjacencyList, unordered_set<int> &visitedNodes, int startNode, int destinationNode){
  if(visitedNodes.count(destinationNode) > 0){
		//We can go from startNode to destinationNode because destinationNode is present in the visitedNodes set
		//Stop DFS early since we already have visited destinationNode    
		return;
  }
	visitedNodes.insert(startNode);
	for(auto const& node: adjacencyList[startNode]){
		//cout<< "Travelling from node " << startNode << " to node " << node<<endl;
		if(visitedNodes.count(node) == 0){
			//This node wasn't already visited
			visitedNodes.insert(node);
			performDFS(adjacencyList, visitedNodes, node, destinationNode);
		}
	}
	return;
}

void printAdjacencyList(map<int, unordered_set<int>> adjacencyList){
  for(auto const& p : adjacencyList){
    cout<<p.first << ":";
    for(const int & node : p.second){
      cout<< " " << node;
    }
    cout<<endl;
  }
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
  
  map<int, unordered_set<int>> adjacencyList;
  //set<vector<int>> redundantEdges;
	vector<int> returnVec = {-1, -1};

  for(int i = 0; i < edges.size(); i++){
    vector<int> edge = edges[i];
    adjacencyList[edge[0]].insert(edge[1]);
    adjacencyList[edge[1]].insert(edge[0]);
  }
	printAdjacencyList(adjacencyList);
  	
  for(int i = 0; i < edges.size(); i++){
    vector<int> currEdge = edges[i];
    cout<<"Removing edge: [" << currEdge[0] << "," << currEdge[1] <<"]" <<endl; 
    adjacencyList[currEdge[0]].erase(currEdge[1]);
    adjacencyList[currEdge[1]].erase(currEdge[0]);
    //printAdjacencyList(adjacencyList);

    unordered_set<int> visitedNodes;
    performDFS(adjacencyList, visitedNodes, currEdge[0], currEdge[1]);

		if(visitedNodes.count(currEdge[1]) > 0) {
			//We can still traverse from currEdge[0] to currEdge[1] after removing edge, therefore this is the redundant edge
			//redundantEdges.insert({currEdge[0], currEdge[1]});
			returnVec[0] = currEdge[0];
			returnVec[1] = currEdge[1];
			cout<<"edge [" << returnVec[0] << ", " << returnVec[1] << "] is redundant"<<endl<<endl;;	
		} 

    adjacencyList[currEdge[0]].insert(currEdge[1]);
    adjacencyList[currEdge[1]].insert(currEdge[0]);
  }
  return returnVec;
}

int main()
{
    
  vector<vector<int>> inputGraph1 = {{1,2},{1,3},{2,3}};
  vector<int> redundantEdge1 = findRedundantConnection(inputGraph1);

	cout<< "redundantEdge: [" << redundantEdge1[0] << "," << redundantEdge1[1] << "]" << endl <<endl;
  
	vector<vector<int>> inputGraph2 = {{1,2},{2,3},{3,4},{1,4},{1,5}};
	vector<int> redundantEdge2 = findRedundantConnection(inputGraph2);

	cout<< "redundantEdge: [" << redundantEdge2[0] << "," << redundantEdge2[1] << "]" << endl <<endl;

	vector<vector<int>> inputGraph3 = {{3,4},{1,2},{2,4},{3,5},{2,5}};
	vector<int> redundantEdge3 = findRedundantConnection(inputGraph3);

	cout<< "redundantEdge: [" << redundantEdge3[0] << "," << redundantEdge3[1] << "]" << endl <<endl;

  return 0;
}
