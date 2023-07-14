/*
77. Combinations
Medium
6.3K
190
Companies

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.

 

Constraints:

    1 <= n <= 20
    1 <= k <= n
*/
#include <iostream>
#include <vector>

using namespace std;

void recursiveCall(vector<int> currSoln, int n, int k, vector<vector<int>> &solns, int currNum) {
    if(currSoln.size() == k) {
        solns.push_back(currSoln);
        return;
    }
    
    int temp = currNum;
    while(temp <= n){
        currSoln.push_back(temp);
        temp++;
        recursiveCall(currSoln, n, k, solns, temp);
        currSoln.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
    
    recursiveCall({}, n, k, ret, 1);
    return ret;
}

int main() {
	vector<vector<int>> res = combine(5, 2);

	for(auto vec : res) {
		cout<<endl;
		for(auto val : vec)
			cout<<val<<" ";
		cout<<endl;
	}
}

