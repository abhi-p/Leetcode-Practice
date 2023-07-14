/*
846. Hand of Straights
Medium
2.2K
146
Companies

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 

Constraints:

    1 <= hand.length <= 104
    0 <= hand[i] <= 109
    1 <= groupSize <= hand.length
*/

#include <vector>
#include <iostream>
#include <map>

using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {

	int handSize = hand.size();
	if(handSize % groupSize != 0)
		return false;

	map<int, int> freqMap;
	for(auto elem : hand){
		if(freqMap.count(elem) < 0) {
		freqMap.insert({elem, 1});
		}
		else
		freqMap[elem]+=1;
	}

	for(auto keyValPair : freqMap) {
		
		int currElem = keyValPair.first;
		int numElem = keyValPair.second;

		while (freqMap[currElem]!=0){

			for (int i=currElem; i<currElem+groupSize;i++) {
			    freqMap[i]--;

			    if(i == currElem + groupSize - 1)
			    continue;
			    if(freqMap.count(i + 1) > 0 && freqMap[i + 1] > 0)
			    continue;
			    else
			    return false;
			}
		}

	}

	return true;
}

int main() {
	vector<int> input = {1,2,3,6,2,3,4,7,8};
	bool res = isNStraightHand(input, 3);
	cout<<boolalpha;
	cout<<res<<endl;
}
