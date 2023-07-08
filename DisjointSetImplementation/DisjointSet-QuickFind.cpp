#include <iostream>
#include <vector>

using namespace std;

//Disjoint set


//Union find
//Assuming all inputs are in range of uint32 [-2^31, 2^31 - 1]

class DisjointSetQuickFind{
  
  int *rootArray;
  int numNodes = 0;

public:
  void printRootArray(){
    for (int i=0;i<numNodes;i++)
      cout<<"rootArray["<<i<<"]: "<<rootArray[i]<<endl;
    cout<<endl;
 
  }
  
  DisjointSetQuickFind(int inputNumNodes){
    rootArray = new int[inputNumNodes];
    numNodes = inputNumNodes;
    for (int i=0;i<numNodes;i++)
      rootArray[i] = i;
  } 
  
  int find(int x){
    return rootArray[x];
  }
  
  void unionSet(int x, int y){
    //First check if two inputs are not already connected
    int rootX=find(x);
    int rootY=find(y);
    
    if(rootX == rootY)
      return;

    //Assume we always choose rootX as joined set's root
    for(int i=0; i < numNodes; i++){
      if(rootArray[i] == rootY)
        rootArray[i] = rootX;
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
    DisjointSetQuickFind uf(10);
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
