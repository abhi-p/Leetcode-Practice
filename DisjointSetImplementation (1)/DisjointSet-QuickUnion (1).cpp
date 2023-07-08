#include <iostream>
#include <vector>

using namespace std;

//Disjoint set


//Quick Union
//Assuming all inputs are in range of uint32 [-2^31, 2^31 - 1]
//Implementing path compression optimization in find()
//Implementing union rank optimization in UnionSet()

class DisjointSetQuickUnion{
  
  int *rootArray;
  int *rank;
  int numNodes = 0;

public:
  void printRootArray(){
    for (int i=0;i<numNodes;i++)
      cout<<"rootArray["<<i<<"]: "<<rootArray[i]<<endl;
    cout<<endl;
 
  }
  
  DisjointSetQuickUnion(int inputNumNodes){
    rootArray = new int[inputNumNodes];
    rank = new int[inputNumNodes];
    numNodes = inputNumNodes;
    for (int i=0;i<numNodes;i++){
      rootArray[i] = i;
      rank[i] = 1;
    }
  } 
  
  int find(int x){
    if (x==rootArray[x])
      return x;
    //Path compression - update each node's parent to be root of the connected component
    rootArray[x] = find(rootArray[x]);
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
      rootArray[rootY]=rootX;
    }
    else if(rank[rootY]>rank[rootX]){
      //Connect x's tree to y's tree as a sub-tree
      rootArray[rootX]=rootY;
    }
    else{
      //Connect y's tree to x's tree as a sub-tree
      //By convention as rootX and rootY have the same height/rank
      rootArray[rootY]=rootX;
      rank[rootX]++;
    }
  }

  bool connected(int x, int y){
    return find(x) == find(y);
  }    
};

// Test Case
int main() {
    // for displaying booleans as literal strings, instead of 0 and 1
    cout << boolalpha;
    DisjointSetQuickUnion uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);

    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    cout << uf.connected(4, 9) << endl;  // true
    uf.printRootArray();

    return 0;

}
