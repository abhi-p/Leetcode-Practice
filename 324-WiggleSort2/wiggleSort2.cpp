/*
324. Wiggle Sort II
Medium
2.7K
901
Companies

Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.

 

Example 1:

Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.

Example 2:

Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]

 

Constraints:

    1 <= nums.length <= 5 * 104
    0 <= nums[i] <= 5000
    It is guaranteed that there will be an answer for the given input nums.

 
Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printVec(vector<int> &input) {
	for(auto elem : input) {
		cout<<elem<<" ";
	}
	cout<<endl;
}

bool checkVec(vector<int> &input) {
	bool retVal = true;	
	for(int i = 0; i < input.size() - 1; i++) {
		retVal &= i % 2 == 0 ? input[i] < input[i+1] : input[i] > input[i+1];
	}
	return retVal;
}

void wiggleSort(vector<int>& nums) {
    int len = nums.size(), maxIndex = 0, minIndex = 0, numOddIndices = 0;
	vector<int> tempArr;
	
	sort(nums.begin(), nums.end());
	tempArr = nums;	
	//printVec(tempArr);
	maxIndex = nums.size() - 1;
	numOddIndices = nums.size() / 2;
	minIndex = nums.size() - numOddIndices-1;

	for(int i = 0; i < nums.size(); i++) {
		if(i % 2 == 0){
			nums[i] = tempArr[minIndex];
			minIndex--;
		}
		else{
			nums[i] = tempArr[maxIndex];
			maxIndex--;
		}
	}

}

int main(){
	vector<int> input;
	cout<<boolalpha;
	input = {3,2,1,4,5,7,2};
	printVec(input);
	wiggleSort(input);
	printVec(input);
	cout<<checkVec(input)<<endl;


	input = {1,5,1,1,6,4};
	printVec(input);
	wiggleSort(input);
	printVec(input);
	cout<<checkVec(input)<<endl;

	input = {1,3,2,2,3,1};
	printVec(input);
	wiggleSort(input);
	printVec(input);
	cout<<checkVec(input)<<endl;

	input = {1,1,2,1,2,2,1};
	printVec(input);
	wiggleSort(input);
	printVec(input);
	cout<<checkVec(input)<<endl;

}
