/*
139. Word Break
Medium

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

"apple" => [0, 4],[8, 12]
"pen" => [5,7]

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

Constraints:

    1 <= s.length <= 300
    1 <= wordDict.length <= 1000
    1 <= wordDict[i].length <= 20
    s and wordDict[i] consist of only lowercase English letters.
    All the strings of wordDict are unique.
*/
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <deque>

using namespace std;

void printWordIndices(vector<pair<int, int>> inputIndices){
  for (auto indices : inputIndices){
    cout << "[" << indices.first << "," << indices.second << "], ";
  }
  cout<<endl;
}

void printWordIndices(unordered_map<int, vector<int>> inputIndices){
  for (auto indices : inputIndices){
    cout<<indices.first<<": ";
    for (auto element: indices.second){
      cout<<element<<", ";
    }
    cout<<endl;
  }
  cout<<endl;
}

bool wordBreak(string s, vector<string>& wordDict) {
  //vector<pair<int, int>> wordIndices;
  //Key: startIndex
  //Value: vector of end indices
  unordered_map<int, vector<int>> wordIndices;
 
  for( auto word : wordDict){
    int position = 0;

    while(position != string::npos){
      position = s.find(word, position);
      
      if(position != string::npos){
         //wordIndices.push_back(make_pair(position, position + word.size() - 1));
         if(wordIndices.count(position) > 0){
           //push_back onto existing vector
           //wordIndices[position].push_back(position + word.size() - 1);
           wordIndices[position].push_back(position + word.size());
         }
         else{
           //make new vector 
            wordIndices[position]= vector<int>();
            //wordIndices[position].push_back(position + word.size() - 1);
            wordIndices[position].push_back(position + word.size());

         }
         //position += word.size();
         position += 1;
      }
    }
  }
  
  printWordIndices(wordIndices);
  
  deque<int> bfs_queue;
  bfs_queue.push_back(0);
  int numChars = 0;
  
  while(!bfs_queue.empty()){
    int currIndex = bfs_queue.front();
    bfs_queue.pop_front();
    //cout<<currIndex<<endl;
    if(currIndex >= s.size())
      return true; //break;

    if(wordIndices.count(currIndex) > 0){
      //Populating the found words in the input string
      for(auto endIndex : wordIndices[currIndex])
        bfs_queue.push_back(endIndex);
    }
    
  }
    
  return false;
}

int main()
{
  
  //we gfrist create A DICTIONary with key as start as start index and values as end index
  //Then we satrt at key zero go to the first element and see if there are any elements in key (element+1)
  
  string s;
  vector<string> wordDict;
  bool ret;
  
  /*s = "applepenapple";
  wordDict = {"apple","pen","app"};
  ret= wordBreak(s, wordDict);
  cout<<ret<<endl;
  
  s = "catsandog";
  wordDict = {"cats","dog","sand","and","cat"};
  ret= wordBreak(s, wordDict);
  cout<<ret;*/
  
  "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
  
  s = "aaaaaaa";
  wordDict = {"aaaa","aaa"};
  /*
  aaaa => [0,4], [1,5],[2,6],[3,8]
  aaa => [0,3],[1,4],[2,5]
  */
  ret= wordBreak(s, wordDict);
  cout<<ret;

    return 0;
}



    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] and
                    word_set.find(s.substr(j, i - j)) != word_set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
