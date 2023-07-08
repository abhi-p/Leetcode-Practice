/*
40. Combination Sum II
Medium
7.7K
192
Companies

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

 

Constraints:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30
*/

#include <vector>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

void recursiveCombinationSum2(vector<int>& candidates, int target, vector<int> currCombination, int currSum, vector<vector<int>>& validCombinations, int currIndex, set<vector<int>>& validCombinationsSet){

	//Base case: currSum > target -> return
	if(currSum > target)
		return;
	if(currSum == target)
		validCombinationsSet.insert(currCombination);		
		//validCombinations.push_back(currCombination);

	for(int i = currIndex; i < candidates.size(); i++){
		currCombination.push_back(candidates[i]);
		currSum += candidates[i];
		if(currSum > target){
			currCombination.pop_back();
			currSum -= candidates[i];
			continue;
		}
			
		recursiveCombinationSum2(candidates, target, currCombination, currSum, validCombinations, i+1, validCombinationsSet);
		currCombination.pop_back();
		currSum -= candidates[i];	
	}
		
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> retCombos;
	set<vector<int>> retCombosSet;
	vector<int> currCombo;

	sort(candidates.begin(), candidates.end());
	
    recursiveCombinationSum2(candidates, target, currCombo, 0, retCombos, 0, retCombosSet);
	for(auto combo : retCombosSet){
		retCombos.push_back(combo);
	}
	return retCombos;
}

void printOutput(vector<vector<int>> validCombinations){
	cout<<"["<<endl;
	for(auto combo : validCombinations){

		cout<<"[";
		for(auto candidate: combo){
			cout<<candidate<<",";
		}
		cout<<"]"<<endl;
	}
	cout<<"]"<<endl<<endl;
}
int main(){

	vector<int> candidates;
	int target;
	vector<vector<int>> ret;

	
	candidates = {2,3,6,7};
	target = 7;

	//Output: [[7]]
	ret = combinationSum2(candidates, target);
	printOutput(ret);

	candidates = {2,3,5};
	target = 8;

	//Output: [[3,5]]
	ret = combinationSum2(candidates, target);
	printOutput(ret);
	
	candidates = {10,1,2,7,6,1,5};
	target = 8;
	//10,1,2,7,6,1,5
	//1,1,2,5,6,7,10

	//Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
	ret = combinationSum2(candidates, target);
	printOutput(ret);



}
