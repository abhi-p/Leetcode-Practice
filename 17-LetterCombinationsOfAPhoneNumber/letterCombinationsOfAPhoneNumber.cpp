/*
17. Letter Combinations of a Phone Number
Medium

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []

Example 3:

Input: digits = "2"
Output: ["a","b","c"]

 

Constraints:

    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].
*/


#include <vector>
#include <iostream>
#include <map>
using namespace std;

void printMap(map<int, vector<char>> inputMap){
  for(auto elem : inputMap){
    cout<<elem.first <<" :";
    for(auto c : elem.second){
      cout<<c<<",";
    }
    cout<<endl;
  }
}
void printVec(vector<string> string_vec){
  for(auto val : string_vec){
    cout<<val<<" ,";
  }
  cout<<endl;
}



vector<string> letterCombinations(string digits) {
  map<int, vector<char>> digitsMap;
  vector<string> returnStrings;
  if(digits.size() == 0)
    return returnStrings;

  returnStrings.push_back("");
  
  digitsMap[2] = {'a','b','c'};
  digitsMap[3] = {'d','e','f'};
  digitsMap[4] = {'g','h','i'};
  digitsMap[5] = {'j','k','l'};
  digitsMap[6] = {'m','n','o'};
  digitsMap[7] = {'p','q','r','s'};
  digitsMap[8] = {'t','u','v'};
  digitsMap[9] = {'w','x','y','z'};

  //printMap(digitsMap);
  
  for (int i=0;i<digits.size();i++){
    vector<string> currVec;
    for(auto s : returnStrings){
      int currNum = digits[i] - '0';
      for (auto currChar: digitsMap[currNum]){
        string currString = s+currChar;//s.push_back(currChar);

        currVec.push_back(currString);

      }  
    }

    returnStrings=currVec;

  }

  return returnStrings;
}

int main()
{
  vector<string> retVec;
  string inputDigits;
  
  inputDigits = "233";
  
  retVec = letterCombinations(inputDigits);
  cout<<retVec.size()<<endl;
  for(auto s : retVec){
    cout<<s<<",";
  }

}

