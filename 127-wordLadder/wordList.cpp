/*
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
*/

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
