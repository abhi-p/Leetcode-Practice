/*
33. Search in Rotated Sorted Array
Medium

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:
left=4,right=2, mid=7

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
if (target<midVal && target<rightVal) || (target>midVal && target>rightVal)

if (target<mid && target>left) || (target>mid && target<left)

Example 2:

Input: nums = [4,5,6,7,8,9,0,1,2], target = 5
Output: -1
left = 5, right = 8
mid = (8-5)/2+5 = 6
              
Example 3:

Input: nums = [1], target = 0
Output: -1

 

Constraints:

    1 <= nums.length <= 5000
    -104 <= nums[i] <= 104
    All values of nums are unique.
    nums is an ascending array that is possibly rotated.
    -104 <= target <= 104


*/
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
  int numsLength = nums.size();
  int left = 0, right = nums.size()-1, mid = (right - left)/2 + left;
  int pivot = 0;

  while (left <= right && left >= 0 && right < numsLength) {
    
    mid = (right - left)/2 + left;
    
    int leftVal = nums[left], rightVal = nums[right], midVal = nums[mid];
    
    //cout<<"left: "<<left<<" right: "<<right << " mid: "<<mid<<endl;
    //cout<<"nums[left]: "<<leftVal<<" nums[right]: "<<rightVal << " nums[mid]: "<<midVal<<endl;
  
    //Check if leftVal < mid -> if not - pivot must be between left and mid
    if (leftVal > midVal) {
      right = mid - 1;
    }
    //Check if rightVal > mid -> if not - pivot must be between mid and right
    else if (rightVal < midVal) {      
      left = mid + 1;
    }
    //Both conditions hold - leftVal < midVal && rightVal > midVal
    else{      
      if (nums[left] < nums[left - 1])
        mid = left - 1;
      else
        mid = left;
      break;
    }
  }
  //cout<<"left: "<<left<<" right: "<<right << " mid: "<<mid<<endl;
  //cout<<"nums[left]: "<<nums[left]<<" nums[right]: "<<nums[right] << " nums[mid]: "<<nums[mid]<<endl;
  cout<<"pivot index: "<<mid<<" pivotValue: "<<nums[mid]<<endl;
  pivot = mid;
  
  //Depending on which sub array the target is in - run binary search
  left = 0, right = numsLength - 1;
  //First subArray: [left,pivot], second subArray: (pivot, right]
  
  if(target >= nums[left] && target <= nums[pivot]){
    int l, r;
    while(left <= right) {
      mid = 
      if(target <)
    }
  }
  else if(target >= nums[pivot] && target <= nums[right]){
    
  }
  else
    return -1;

}

int main()
{
    vector<int> inputNums;
    int inputTarget;
  
    inputNums = {4,5,6,7,0,1,2};
    inputTarget = 1;
    std::cout << search(inputNums, inputTarget) << std::endl;
  
    inputNums = {4,5,6,7,8,9,0,1,2};
    inputTarget = 5;
    std::cout << search(inputNums, inputTarget) << std::endl;  
    return 0;
}

