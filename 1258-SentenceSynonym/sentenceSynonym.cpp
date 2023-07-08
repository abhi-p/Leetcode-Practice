/*
1258. Synonymous Sentences
Medium

You are given a list of equivalent string pairs synonyms where synonyms[i] = [si, ti] indicates that si and ti are equivalent strings. You are also given a sentence text.

Return all possible synonymous sentences sorted lexicographically.

 

Example 1:

Input: synonyms = [["happy","joy"],["sad","sorrow"],["joy","cheerful"]], text = "I am cherrful today but was sad yesterday"
Output: ["I am cheerful today but was sad yesterday","I am cheerful today but was sorrow yesterday","I am happy today but was sad yesterday","I am happy today but was sorrow yesterday","I am joy today but was sad yesterday","I am joy today but was sorrow yesterday"]

Example 2:

Input: synonyms = [["happy","joy"],["cheerful","glad"]], text = "I am happy today but was sad yesterday"
Output: ["I am happy today but was sad yesterday","I am joy today but was sad yesterday"]

 happy     sad 
 |    |      |
 joy  |   sorrow 
      |
     cheerful
 

Constraints:

    0 <= synonyms.length <= 10
    synonyms[i].length == 2
    1 <= si.length, ti.length <= 10
    si != ti
    text consists of at most 10 words.
    All the pairs of synonyms are unique.



*/

#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class disjointSet {
  vector<int> rootArray;
  vector<int> rank;
  int numNodes;
  
  public:
  disjointSet(int n, vector<string> inputNodes) : rootArray(n, 1), rank(n, 1), numNodes(n){
    for(int i = 0; i < n; i++){
      rootArray[i] = i;
    }
  }
  
  int find(int inputNode){
    if( rootArray[inputNode] == inputNode)
      return inputNode;
    //Recursive path compression
    rootArray[inputNode] = find(rootArray[inputNode]);
    return rootArray[inputNode];
  }
  
  void unionOperation(int x, int y){
    int rootX = find(x), rootY = find(y);
   
    if (rootX==rootY)
      return;
    
    if(rank[rootX] > rank[rootY]){
        //Want to add y to x as a subtree
      rootArray[rootY] = rootX;
    }
    else if(rank[rootX] < rank[rootY]){
        //Want to add x to y as a subtree
      rootArray[rootX] = rootY;
    }
    else{
      rootArray[rootY]=rootX;
      rank[rootX]+=1;
    }    
  }
  
  bool isConnected(int node1, int node2){
    return find(node1) == find(node2);
  }
};




vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
  vector<string> retVec;
  int index =0;
  map<string,int> wordMap;
  for (auto syn: synonyms){
    if (wordMap.count(syn[0])==0){
      wordMap[syn[0]]=i;
      i++;
    }
    if (wordMap.count(syn[1])==0){
      wordMap[syn[1]]=i;
      i++;
    }
    
  }
  
  disjointSet synonymsDS(wordMap.size());
  
  for (auto syn: synonyms){
    synonymsDS.unionOperation(wordMap[syn[0]],wordMap[syn[1]]);
  }
  
  retVec.push_back(text);
  
  
  istringstream inputStringStream(text);
  
  do {
    string word;
    inputStringStream >> word;
    
    
    if (wordMap.count(word)>0){
      for(int i = 0; i < wordMap.size(); i++){
        if(i == wordMap[word])
          continue;
        
        if(isConnected(wordMap[word], i)){
          //Replace synonym in all output strings
          
        }
      }
      
    }
    
    
  } while(inputStringStream);

}


int main()
{
    std::cout << "Practice makes Perfect!" << std::endl;
    return 0;
}



