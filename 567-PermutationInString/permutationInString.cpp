/*
567. Permutation in String
Medium
9.7K
311
Companies

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

 

Constraints:

    1 <= s1.length, s2.length <= 104
    s1 and s2 consist of lowercase English letters.
*/


#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printMap(map<char, int> input){
    for(auto keyValPair : input){
      cout<<"["<<keyValPair.first<<"]: "<<keyValPair.second<<endl;
    }
  cout<<endl;
}

bool match(map<char,int> &input){
	bool ret = true;
	for(auto keyValPair : input){
		if(keyValPair.second ==0)
			ret = true;
		else
			return false;
	}
	return ret;
}

bool checkInclusion(string s1, string s2) {
	if(s1.size() > s2.size())
		return false;
	if(s1.size() == 1)
		return s2.find(s1) != std::string::npos;
	map<char, int> s1Freq, s1Freq_2;

	for(auto ch : s1) {
		if(s1Freq.count(ch) > 0){
			s1Freq[ch]++;
		}
		else{
			s1Freq.insert({ch, 1});
		}
	}

	s1Freq_2 = s1Freq;
	//printMap(s1Freq);
	int start = 0, end = s1.size()-1;

	for(int i = start; i <= end; i++){
		char currChar = s2[i];
		if(s1Freq.count(currChar) > 0){
			s1Freq[currChar]--;
		}
	}
		
	if(match(s1Freq))
		return true;

	s1Freq_2 = s1Freq;

	while(end < s2.size()){

		if(match(s1Freq))
			return true;

		//Add s2[start] to s1Freq if it exists in s1Freq_2
		if(s1Freq_2.count(s2[start]) > 0) {
			s1Freq[s2[start]]++;
		}

		//Move window over
		start++;
		end++;

		//remove s2[end]
		if(s1Freq.count(s2[end]) > 0) {
			s1Freq[s2[end]]--;
		}
	}
	return false;
}

int main()
{
	cout<<boolalpha;
	cout<<checkInclusion("adc", "dcda")<<endl;
	cout<<checkInclusion("ab", "ab")<<endl;
	return 0;
}
