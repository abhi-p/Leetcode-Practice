/*
416. Partition Equal Subset Sum
Medium
10.9K
198
Companies

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

 

Constraints:

    1 <= nums.length <= 200
    1 <= nums[i] <= 100
*/
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;
bool recursiveCall(vector<int> &input, int currElem, int currSum, int targetSum, vector<vector<int>> &memoTable){

    if (currSum==targetSum)
        return true;
    if(currElem == input.size())    
        return false;
	if (currSum>targetSum)
        return false;

    if(memoTable[currElem][currSum] != -1)
        return memoTable[currElem][currSum] == true;
    
    
    int currNum = input[currElem];
    
    bool includePath = recursiveCall(input, currElem + 1, currSum + currNum, targetSum, memoTable);
    bool excludePath = recursiveCall(input, currElem + 1, currSum, targetSum, memoTable); 
    memoTable[currElem][currSum]  = includePath || excludePath;

    return includePath || excludePath;
}

bool canPartition(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    if(totalSum %2 != 0)
        return false;
    
    vector<vector<int>> memo(nums.size()+ 1,vector<int>(totalSum / 2 + 1, -1));
    return recursiveCall(nums, 0, 0, totalSum/2, memo);
}
 
int main() {
	vector<int> nums = {1,2,3,5,17,6,14,12,6};
	cout<<boolalpha;
	cout<<canPartition(nums)<<endl;

	nums = {1,5,11,5};

	cout<<canPartition(nums)<<endl;
}
