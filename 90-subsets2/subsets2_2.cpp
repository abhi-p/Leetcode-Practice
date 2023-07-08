/*
78. Subsets
Medium

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

*/
#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
#include <map>

using namespace std;

void printPowerSet(vector<vector<int>> inputPowerSet){
  for (auto set: inputPowerSet) {
    cout<< "[";
    for(auto element:set){
      cout << element<< ",";
    }
    cout << "], "<<endl<<endl;
  }
  
}

void printSet(vector<int> inputSet){
  cout<< "[";
  for (auto num: inputSet) {
    cout << num<< ",";
  }
  cout << "]";
}

void printInterRepMap(map<int,int> inputMap){
  for (auto const& x : inputMap){
    cout<<x.first << ": " << x.second << endl;
  }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  int numElements = nums.size();
  //Return powerSet
  vector<vector<int>> powerSet;
  
  //Key: input value
  //Value: number of times input value occurs in the input sequence
  map<int, int> interRepMap;

  sort(nums.begin(), nums.end());

  //Generate intermediate representation of input sequence
  for(auto inputNum : nums){
     if(interRepMap.count(inputNum) > 0){
       interRepMap[inputNum] += 1;
     }
     else{
       interRepMap[inputNum] = 1;
     }
  }

  //Push empty set into powerset
  powerSet.push_back({});

  //Go over all input numbers which are keys in interRepMap
  for (auto const& x : interRepMap){
    int inputVal = x.first;
    int inputValOccurences = x.second;

    //Used to hold newly generated subsets
    //Base case where we generate subsets from previously created subsets
    vector<vector<int>> intermediateSet;
    for(auto set : powerSet){  
      set.push_back(inputVal);
      intermediateSet.push_back(set);
      set.pop_back();
    }

    for(auto set : intermediateSet){
      powerSet.push_back(set);
    }
    //Uptil here - solution for subsets 1 (input sequence without duplicates)

    //If inputNum is duplicated, only append inputNum to sets which contain i inputNums
    for(int i=1; i < inputValOccurences; i++){
      vector<vector<int>> intermediateSet2;
      for(auto set : powerSet){
        int setLength = set.size();
        //If the subset doesnt have enough numbers in it
        if(setLength < i)
          continue;

        //Check to see if set[setLength-i]...set[setLength] == inputNum
        int number = set[setLength - i];
        if(number == inputVal){
          set.push_back(inputVal);
          intermediateSet2.push_back(set);
          set.pop_back();
        }

      }
      for(auto set : intermediateSet2){
          powerSet.push_back(set);
      }
    }
  }
  return powerSet;
}

int main()
{
    vector<int> inputSet1 = {2,2,1};
    vector<int> inputSet2 = {1,2,3};
    vector<int> inputSet3 = {0};

    
    subsetsWithDup(inputSet1);
    /*
    subsets(inputSet2);
    subsets(inputSet3);
    */
  
    //subsetsWithDup(inputSet2);

    return 0;
}

