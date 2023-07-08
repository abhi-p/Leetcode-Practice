#include <vector>
#include <iostream>
#include <map>
#include <stdlib.h>

using namespace std;


class Solution {
	//key: values in the original input array
	//value: vector of indices where key can be found in the original input array
	map<int, vector<int>> inputNums;
public:
	void printMap(){
		for(auto keyVal : inputNums){
			cout<<keyVal.first<<": ";
			for(auto val : keyVal.second){
				cout<<val<<" ";
			}
			cout<<endl;
		}
	}
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
			if(inputNums.count(nums[i]) == 0){
				inputNums[nums[i]] = {i};
			}
			else{
				inputNums[nums[i]].push_back(i);
			}
		}
		//printMap();
    }
    
    int pick(int target) {
		if(inputNums.count(target) <= 0){
			return -1;
		}
		else{
			int minIndex = 0;//inputNums[target].front();
			int maxIndex = inputNums[target].size() - 1;//inputNums[target].back();
			//cout<<minIndex<<" "<<maxIndex<<endl;
			int randomIndex = minIndex + (rand() % (maxIndex - minIndex + 1));
			//cout<<randomIndex<<endl;
			return inputNums[target][randomIndex];
		}
    }
};

int main(){
	vector<int> inputNums = {1,2,3,3,3};
	int target = 3;

	Solution* obj = new Solution(inputNums);
	int param_1 = obj->pick(target);
	cout<<param_1<<endl;

}
