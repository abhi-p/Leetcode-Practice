/*
127. Word Ladder
Hard
9.7K
1.8K
Companies

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

 

Constraints:

    1 <= beginWord.length <= 10
    endWord.length == beginWord.length
    1 <= wordList.length <= 5000
    wordList[i].length == beginWord.length
    beginWord, endWord, and wordList[i] consist of lowercase English letters.
    beginWord != endWord
    All the words in wordList are unique.


*/

//Key to this question is to generate all intermediate representations of all words, use them as keys in the adjacencyList
//When running BFS, start with beginWord, generate all intermediateReps of beginWord, use adjacencyList to get all words that are
//1-character away in constant time

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <utility>
#include <unordered_set>

using namespace std;

void printVec(vector<string> inVec){
	for(auto elem : inVec)
		cout<<elem<<endl;
	cout<<endl;
}

void printMap(map<string, vector<string>> inMap){
	for(auto keyValPair : inMap){
		cout<<"map[ "<<keyValPair.first<<"]: ";

		for(auto word : keyValPair.second)
			cout<<word<<" ";
		cout<<endl;		
	}

}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	//vector<string> intRep;
	//Key: intermediate representation
	// Value: vector of words which are one character away intermediate representation
	map<string, vector<string>> intermediateRepMap;
	unordered_set<string> visitedSet;

	bool foundEndWord = false, foundBeginWord = false;
    for(auto word : wordList){
		if(!foundEndWord && word == endWord)
			foundEndWord = true;
		if(!foundBeginWord && word == beginWord)
			foundBeginWord = true;

		for(int i = 0; i < word.size(); i++){
			string temp = word;
			temp[i] = '*';
			//intRep.push_back(temp);
			intermediateRepMap[temp].push_back(word);
		}
	}

	
	if(!foundEndWord){
		cout<<"endWord isn't part of wordList"<<endl;
		return 0;
	}
	if(!foundBeginWord){
		cout<<"beginWord isn't part of wordList, add it to adjacencyList"<<endl;
		for(int i = 0; i < beginWord.size(); i++){
			string temp = beginWord;
			temp[i] = '*';
			intermediateRepMap[temp].push_back(beginWord);
		}
	}
	//printVec(intRep);
	printMap(intermediateRepMap);

	//intermediateRepMap is the adjacencyList
	//Run iterative BFS through adjacencyList starting at beginWord
	deque<pair<string, int>> BFSQueue;

	BFSQueue.push_back(make_pair(beginWord, 0));
	
	while(!BFSQueue.empty()){
		pair<string, int> currNode = BFSQueue.front();
		BFSQueue.pop_front();
		
		string currWord = currNode.first;
		int currStep = currNode.second;
		if(visitedSet.count(currWord) > 0)
			continue;
		else
			visitedSet.insert(currWord);
		if(currWord == endWord)
			return currStep + 1;

		for(int i = 0; i < currWord.size(); i++){
			string temp = currWord;
			temp[i] = '*';
			for(auto word : intermediateRepMap[temp]){
				BFSQueue.push_back(make_pair(word, currStep + 1));
			}
		}
	}
	

	return 0;
}

int main(){
	string beginWord, endWord;
	vector<string> wordList;

	beginWord = "hit";
	endWord = "cog";
	wordList = {"hot","dot","dog","lot","log","cog"};
	
	cout<<ladderLength(beginWord, endWord, wordList)<<endl;

	beginWord = "hot";
	endWord = "dog";
	wordList = {"hot","dog"};
	
	cout<<ladderLength(beginWord, endWord, wordList)<<endl;

}



//Python implementation
/*

from collections import deque

def ladderLength(beginWord, endWord, wordList):
  wordList.append(beginWord)
  
  if endWord not in wordList:
    return 0
  
  wordLen=len(beginWord)
  adj={}
  wordCombo={}
  
  for word in wordList:
    for i in range(wordLen):
      #inter = word
      inter=word[:i]+'*'+word[i+1:]
      
      if inter in wordCombo:
        wordCombo[inter].append(word)
      else:
        wordCombo[inter]=[word]
        
  print(wordCombo)
  queue=deque()
  queue.append((beginWord,1))
  visited=set()
  while queue:
    curr=queue.popleft()

    if curr[0] in visited:
        continue
    visited.add(curr[0])

    if curr[0]==endWord:
        return curr[1]


    for i in range(wordLen):
      inter=curr[0][:i]+'*'+curr[0][i+1:]

      for adjWord in wordCombo[inter]:
        queue.append((adjWord,curr[1]+1))

  return 0  


beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]

res=ladderLength(beginWord,endWord,wordList)
print(res)

*/
