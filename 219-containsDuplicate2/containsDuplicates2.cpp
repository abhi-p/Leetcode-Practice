/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

 

Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109
    0 <= k <= 105
*/

#include <iostream>
#include <map>
#include <vector>


using namespace std;

void printMap(map<int, int> inputMap){
	for(map<int, int>::iterator it = inputMap.begin(); it != inputMap.end(); it++){
		cout << "inputMap[" << it->first << "]: " << it->second << endl;
	}
	cout << endl;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	//Map - key: input array element
	//		value: index of element in input array
	map<int, int> possibleDups;
	int inputVectorSize = nums.size();

	for(int i = 0; i < inputVectorSize; i++){
		//If we find a duplicate element, and it's position satifies the 'k' condition
		if(possibleDups.count(nums[i]) > 0 && abs(possibleDups[nums[i]] - i) <= k){
			return true;		
		}
		//If we dont find a duplicate element, or if we do find one, but its position doesn't
		// satisfy the 'k' condition, then update its index
		else{
			possibleDups[nums[i]] = i;
		}
		//printMap(possibleDups);
	}
	return false;
}

int main(){
	vector<int> input1 = {0, 2, 3, 4, 5, 5, 7};
	int input1_k = 1;
	cout << containsNearbyDuplicate(input1, input1_k) << endl;

	vector<int> input2 = {1,2,3,1,2,3};
	int input2_k = 2;
	cout << containsNearbyDuplicate(input2, input2_k) << endl;

	vector<int> input3 = {1,0,1,1};
	int input3_k = 1;
	cout << containsNearbyDuplicate(input3, input3_k) << endl;

}


