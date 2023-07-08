/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

 

Constraints:

    1 <= nums.length <= 105
    -10^9 <= nums[i] <= 10^9
*/

#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
	//Loop through input numbers, placing each into hashmap, if the input number already exists in the map, return false
	// else return true after loop is complete

	set <int> lookupTable;

	for(unsigned int i = 0; i < nums.size(); i++){
		/*if(lookupTable.count(nums[i]) == 1){
			cout<< "nums[" << i << "]: " << nums[i] << "exists atleast twice in input array" << endl;
			return true;
		}
		else{
			lookupTable.insert(nums[i]);
		}*/
		pair<set<int>::iterator, bool> insert = lookupTable.insert(nums[i]);
		if(insert.second == false){
			cout<< "nums[" << i << "]: " << nums[i] << " exists atleast twice in input array" << endl;
			return true;
		}
	}

	return false;
}

int main() {
	vector<int> input1 = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	cout<< containsDuplicate(input1) << endl;

	vector<int> input2 = {0, 1, 2, 3, 4, 5, -1, -9, 0};
	cout<< containsDuplicate(input2) << endl;	

}
