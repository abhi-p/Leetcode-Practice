/*
We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Example 2:

Input: nums = [1,2,3,4]
Output: 2

Example 3:

Input: nums = [1,1,1,1]
Output: 0
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;
void printMap(map<int, int> inputMap){
	for(auto keyValPair : inputMap){
		cout<<keyValPair.first << " "<<keyValPair.second<<endl;
	}
}
int findLHS(vector<int>& nums) {
	map<int, int> numsMap;
	int maxSubsequenceLength = 0;

	
	for(auto num : nums){
		if(numsMap.count(num) == 0)
			numsMap[num] = 1;
		else
			numsMap[num] += 1;
	}

	printMap(numsMap);

	for(auto keyValPair : numsMap){
		int key = keyValPair.first, val = keyValPair.second;

		if(numsMap.count(key+1) > 0)
			maxSubsequenceLength = max(maxSubsequenceLength, val + numsMap[key + 1]);
		//cout<<keyValPair.first << " "<<keyValPair.second<<endl;
	}
	return maxSubsequenceLength;
}

int main(){
	vector<int> input;
	int ret;

	input = {1,3,2,2,5,2,3,7};
	ret = findLHS(input);
	cout<<ret<<endl;

}
