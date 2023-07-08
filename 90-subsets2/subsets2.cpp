//See subsets2_2.cpp for solution

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

vector<vector<int>> subsets(vector<int>& nums) {
  int numElements = nums.size();
  vector<vector<int>> powerSet;
  map<int, vector<vector<int>>> subsets;
  
  powerSet.push_back({});
  subsets[0].push_back({});
  
  sort(nums.begin(), nums.end());
  
  for (auto num : nums){
    powerSet.push_back(vector<int> {num});
    subsets[1].push_back(vector<int>{num});
  }
  
  //Generate all subsets of lengths 2...n
  for(int i = 2; i <= numElements; i++){
      for (auto set : subsets[i-1]){
        int largestSetNum = set.back();
        int startingIndex = 0;
        while(startingIndex < numElements && nums[startingIndex] <= largestSetNum)
           startingIndex++;
        while(startingIndex < numElements){
          set.push_back(nums[startingIndex]);
          subsets[i].push_back(set);
          powerSet.push_back(set);
          set.pop_back();
          startingIndex++;
        }
    }
  }
  
  printPowerSet(powerSet);
  
  return powerSet;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  int numElements = nums.size();
  vector<vector<int>> powerSet;
  //unordered_set<int> visitedSet;
  
  //Push empty set into powerset
  powerSet.push_back({});
  
  
//  set<vector<int> > set_of_vectors;

  for (auto num : nums){
  
    
    vector<vector<int>> intermediateSet;
    for(auto set : powerSet){
      
      //[[],[1],[2],[1,2]]
     
      set.push_back(num);
      intermediateSet.push_back(set);
      set.pop_back();
        
      }
    }
    
    for(auto set : intermediateSet){
      powerSet.push_back(set);
    }
    
  }
  printPowerSet(powerSet);
  return powerSet;
}

void printInterRepMap(map<int,int> inputMap){
  for (auto const& x : inputMap){
    cout<<"x: " << x.first << " " << x.second << endl;
  }
}

vector<vector<int>> subsets2(vector<int>& nums) {
  int numElements = nums.size();
  vector<pair<int, int>> interRep;
  map<int, int> interRepMap;

  sort(nums.begin(), nums.end());
  
  for(auto inputNum : nums){
     if(interRepMap.count(inputNum) > 0){
       interRepMap[inputNum] += 1;
     }
     else{
       interRepMap[inputNum] = 1;
     }
  }
  
  printInterRepMap(interRepMap);  
  
  
  vector<vector<int>> powerSet;
  //unordered_set<int> visitedSet;
  
  //Push empty set into powerset
  powerSet.push_back({});
  /*
  
//  set<vector<int> > set_of_vectors;

  for (auto num : nums){
    visited=0;
    if (visitedSet.count(num)==0) {
      visitedSet.insert(num);
    }
    else
      visited=1
    
    vector<vector<int>> intermediateSet;
    for(auto set : powerSet){
      
      //[[],[1],[2],[1,2]]
      if visited==1{
        if (std::find(set.begin(), set.end(), num) != v.end()) {
      set.push_back(num);
      intermediateSet.push_back(set);
      set.pop_back();
        
    }
      }
      
    else{
      set.push_back(num);
      intermediateSet.push_back(set);
      set.pop_back();
        
      }
    }
    
    for(auto set : intermediateSet){
      powerSet.push_back(set);
    }
    
  }
  printPowerSet(powerSet);
  */
  return powerSet;
  
}


int main()
{
    vector<int> inputSet1 = {2,1,3,4};
    vector<int> inputSet2 = {1,2,3};
    vector<int> inputSet3 = {0};

    
    subsets2(inputSet1);
    /*
    subsets(inputSet2);
    subsets(inputSet3);
    */
  
    subsetsWithDup(inputSet2);
    std::cout << "Practice makes Perfect!" << std::endl;
    return 0;
}

