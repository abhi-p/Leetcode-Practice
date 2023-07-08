/*
34. Find First and Last Position of Element in Sorted Array
Medium
15K
362
Companies

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

 

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
    nums is a non-decreasing array.
    -109 <= target <= 109
*/
#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> vec){
	for(auto elem : vec){
		cout<<elem<<" ";
	}
	cout<<endl;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> retVec = {-1, -1};
    int left = 0, right = nums.size() - 1;
    
    //Find start
    while(left <= right){
        int mid = (right - left)/2 + left;

        if(nums[mid] < target){
            left = mid + 1;
        }
        else if (nums[mid] > target){
            right = mid - 1;
        }
        else{ //mid is target
            //Edge case where target's start index = 0
            if(mid == 0){
                retVec[0] = mid;
                break;
            }
            else{
                if(nums[mid-1] < nums[mid]){
                    retVec[0] = mid;
                    break;
                }
                else{
                    right = mid - 1;
                }
            }
        }
    }


    left = 0, right = nums.size() - 1;
    
    //Find end
    while(left <= right){
        int mid = (right - left)/2 + left;

        if(nums[mid] < target){
            left = mid + 1;
        }
        else if (nums[mid] > target){
            right = mid - 1;
        }
        else{ //mid is target
            //Edge case where target's end index = last index
            if(mid == nums.size() - 1){
                retVec[1] = mid;
                break;
            }
            else{
                if(nums[mid+1] > nums[mid]){
                    retVec[1] = mid;
                    break;
                }
                else{
                    left = mid + 1;
                }
            }
        }
    }
    //debug
    //cout<<retVec[0]<<" "<<retVec[1];

    return retVec;
}

int main(){

	vector<int> testCase, resVec;
	int target;

	testCase = {5,7,7,8,8,10};
	target = 8;
	
	
	resVec = searchRange(testCase, target);

	printVec(resVec);

	testCase = {5,7,7,8,8,10};
	target = 6;
	
	
	resVec = searchRange(testCase, target);

	printVec(resVec);

	testCase = {1};
	target = 0;
	
	
	resVec = searchRange(testCase, target);

	printVec(resVec);

	testCase = {0};
	target = 0;
	
	
	resVec = searchRange(testCase, target);

	printVec(resVec);

}
