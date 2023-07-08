/*
340. Longest Substring with At Most K Distinct Characters
Medium

2589

76

Add to List

Share
Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

 

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.
 

Constraints:

1 <= s.length <= 5 * 104
0 <= k <= 50

*/
#include <string>
#include <map>
#include <iostream>

using namespace std;


int lengthOfLongestSubstringKDistinct(string s, int k) {
      
    int l = 0, r = 0;
    map<char,int> distinctChars;
    int maxLen=0;
  
    while (r <= s.size()){
      while (distinctChars.size()>k){
        

        if (distinctChars[s[l]]<=1)
          distinctChars.erase(s[l]);
        else
          distinctChars[s[l]]--;
        cout<<"distinctChars.size(): "<<distinctChars.size()<<endl;
        l+=1;
      }

      int curLength = r - l;
      maxLen = max(maxLen, curLength);
      cout<<"maxLength: "<<maxLen<<" "<<s.substr(l,curLength) <<endl;
      if (r==s.size())
          break;

      if (distinctChars.count(s[r])>0){
        distinctChars[s[r]]+=1;
      }
      else{
        //distinctChars.insert(s[r]);
        distinctChars[s[r]]=1;
      }

      r+=1;

    }
    return maxLen;
}

int main(){
  
 string s = "eceba";
 int k = 2;
 
 cout<<lengthOfLongestSubstringKDistinct(s,k);
  
}

