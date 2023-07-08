/*
Given an integer array nums and two integers k and t, return true if there are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false

 

Constraints:

    1 <= nums.length <= 2 * 104
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 104
    0 <= t <= 231 - 1


*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void printArray(vector<pair<int,int>> inputArray){
    for(int i =0; i < inputArray.size(); i++){
      cout << "inputArray[ i: " << inputArray[i].second << " ]: " << inputArray[i].first <<endl;
    }
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    vector<pair<int,int>> intArray;
    
    for(int i = 0; i < nums.size(); i++){
        intArray.push_back(make_pair(nums[i], i));
    }
    sort(intArray.begin(), intArray.end());
  
    printArray(intArray);
  
  return false;
}

int main()
{
    vector<int> nums1 = {1,2,3,1};
                  //{(0,1),(3,1),(1,2),(2,3)}
                //2,1,,0
    int k1 = 3, t1 = 0;
    containsNearbyAlmostDuplicate(nums1, k1, t1);
    //std::cout << "Practice makes Perfect!" << std::endl;
    return 0;
}



