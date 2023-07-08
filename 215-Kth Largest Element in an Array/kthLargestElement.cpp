/*
215. Kth Largest Element in an Array
Medium

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

You must solve it in O(n) time complexity.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
p=0,i=0
p=1,i=1
[3,5,2,1,5,6,4] pivot=4
p=1,i=2
[3,5,2,1,5,6,4]

[]
[3,2,5,1,5,6,4]k=2
[3,2,1,5,5,6,4]
[3,2,1,4,5,6,5]

[5,6,5
[5,6,5]
[5,5,6]

indices: l=0,r=5
p=l
p=2,i=2
[3,2,]                   



Constraints:

    1 <= k <= nums.length <= 105
    -104 <= nums[i] <= 104
*/

//Used quickSelect to solve this question

#include <vector>
#include <iostream>

using namespace std;
void recursivePivot(int l,int r,vector<int> &nums, int k, int &kthLargestElem, bool& ans){
  //Base case - short circuit recursion 
  if(ans)
    return;

  int p=l;
  int pivot=nums[r];
  for (int i=l;i<r;i++){
    if (nums[i]<=pivot){
      int temp= nums[p];
      nums[p]=nums[i];
      nums[i]=temp;
      
       p++;
    } 
  }
  int temp = nums[p];
  nums[p]=pivot;
  nums[r]=temp;
  
  int compareK = nums.size()-k;
  if (p==compareK){
    kthLargestElem = pivot;
    ans = true;
  }
  else if (p > compareK)
    recursivePivot(l, p-1, nums, k, kthLargestElem, ans);
  else if (p < compareK)
    recursivePivot(p+1, r, nums, k, kthLargestElem, ans);
}

int findKthLargest(vector<int>& nums, int k) {
  int returnVal = 0;
  bool answer = false;
  //Used QuickSelect to solve this
  /*
  QuickSelect: Similar to quickSort - choose a pivot, divide up input array into left and right subarrays
   leftSubarray has all elems <= pivot
   rightSubarray has all elems > pivot
   
   
   after paritioning - compare pivot to k
   
   if(pivot < inputArray.size() - k)
    too many elements bigger than pivot - so consider right subarray for recursive call
   if(pivot > inputArray.size() - k)
    too many elements smaller than pivot - so consider left subarray for recursive call
   else - we found that pivot == inputArray.size() - k ==  therefore pivot is kth smallest element - return pivot
  
  
  */
  recursivePivot(0, nums.size()-1, nums, k, returnVal, answer);
  return returnVal;
}

int main()
{
  vector<int> inputNums;
  int inputK;
  
  inputNums = {3,2,1,5,6,4};
  inputK = 2;
  cout<<findKthLargest(inputNums, inputK)<<endl;

  inputNums = {3,2,3,1,2,4,5,5,6};
  inputK = 4;
  cout<<findKthLargest(inputNums, inputK)<<endl;

}

