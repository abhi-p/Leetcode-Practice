/*
Given an integer array nums, reorder it such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

You may assume the input array always has a valid answer.

 

Example 1:

Input: nums = [3,5,2,1,6,4]
Output: [3,5,1,6,2,4]
Explanation: [1,6,2,5,3,4] is also accepted.
Example 2:

Input: nums = [6,6,5,6,3,8]
Output: [6,6,5,6,3,8]
 

Constraints:

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 104
It is guaranteed that there will be an answer for the given input nums.
 

Follow up: Could you solve the problem in O(n) time complexity?*/
*/
//Our Task is to reorder the given array in place such that every element at an odd index is greater than or equal to the two adjacent elements at even indices

#include <vector>
#include <iostream>

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
		retVal &= i % 2 == 0 ? input[i] <= input[i+1] : input[i] >= input[i+1];
	}
	return retVal;
}

//Swap inplace elements at indices i and i+1
//Assumes index + 1 < input.size()
void swap(vector<int> &input, int index) {
	int temp = input[index+1];
	input[index+1] = input[index];
	input[index] = temp;
}

void wiggleSort(vector<int>& nums) {
    int len = nums.size();
	if(len <= 1)
		return;
	for (int i = 0; i < len-1; i++) {
		//consider i and i+th element
		//if i is even - we want nums[i] <= nums[i+1]
		if (i%2 == 0) {
			if (nums[i] > nums[i+1]) {
				swap(nums, i);
			}
		}
		//if i is odd - we want nums[i] >= nums[i+1]
		else {
			if (nums[i] < nums[i+1]) {
				swap(nums, i);
			}
		}

	}
}

int main(){
	vector<int> input;
	cout<<boolalpha;
	
	input = {3,2,1,4,5,7,2};

	wiggleSort(input);
	printVec(input);

	cout<<checkVec(input)<<endl;

	input = {1,2,3,4};

	wiggleSort(input);
	printVec(input);
	cout<<boolalpha;
	cout<<checkVec(input)<<endl;
	
}
