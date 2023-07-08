/*
678. Valid Parenthesis String
Medium

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "(*)"
Output: true

Example 3:

Input: s = "(*))"
Output: true

 

Constraints:

    1 <= s.length <= 100
    s[i] is '(', ')' or '*'.
*/    

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

void printVec(vector<string> inputVec){
	for(auto s : inputVec)
		cout<<s<<", ";
	cout<<endl;
}

bool linear_checkValidString(string s){
	//Go through string s, keep track of maximum and minimum balance of the substring
	//Balance = #'(' - #')' 
	//if balance == 0 -> substring has equal number of '(' and ')'
	int low = 0, high = 0;
	for(int i = 0; i < s.size(); i++){
		char currChar = s[i];
		if(currChar == '('){
			low += 1;
			high += 1;
		}
		else if (currChar == '*'){
			low -= 1; //'*' = ')'
			high += 1; //'*' = '('
		}
		else{//currChar == ')'
			low -= 1;
			high -= 1;
		}
		
		if(high < 0)
			break;
		low = (low < 0) ? 0 : low;
	}
	return low == 0;
}


bool recursiveHelper(int currIndex, int numOpenBrackets, string s){
	//cout<<"currIndex: " << currIndex<<" numOpenBrackets: " << numOpenBrackets << " s.size(): "<<s.size()<<endl;
	//base case: we have reached the end of the input string, check the number of open brackets
	if(currIndex >= s.size()){
		//If number of open brackets = 0, we have balanced brackets
		return numOpenBrackets == 0;
	}

	char currChar = s[currIndex];
	//cout<<"currChar: " << currChar<<endl;

	if(currChar == '('){
		return recursiveHelper(currIndex + 1, numOpenBrackets + 1, s);
	}
	else if (currChar == ')'){
		//In a case where the number of open brackets in prefix not enough to balance this close bracket
		if(numOpenBrackets == 0)
			return false;
		return recursiveHelper(currIndex + 1, numOpenBrackets - 1, s);
	}
	else{
		//wildcard case -> *
		return 
			recursiveHelper(currIndex + 1, numOpenBrackets + 1, s) /*substitute '*' for '('*/ ||
			recursiveHelper(currIndex + 1, numOpenBrackets, s) /*substitute '*' for ''*/ ||
			(numOpenBrackets > 0 ? recursiveHelper(currIndex + 1, numOpenBrackets - 1, s) : false);
	}
	
}

//recursive soln
bool TLE_recursive_checkValidString(string s) {
	return recursiveHelper(0, 0, s);
}

/*
( -> +1
) -> -1
* -> +1, -1, 0

			( * ) ) 
balance:    1,2 or 0 or 1, 1 or -1 or 0, 0 or -2 or -1 -> one ending value is 0 therefore one generated parenthesis is valid

minBalance: 1,0,-1,-2
maxBalance: 1,2,1,0

	((**

minBalance:1,2,1,0  
maxBalance:1,2,3,4

	(***
minBalance:1,0,-1,-2
maxBalance:1,2,3,4

	((*
minBalance:1,2,1
maxBalance:1,2,3

	(***)
minBalance:1,0,-1,-2,-3
maxBalance:1,2,3,4,3
(  ->  [1]
(* ->	[0, 1, 2] [(), (, ((]
(**->	[-1, 0, 1, 0, 1, 2, 1, 2, 3] -> [-1, 0, 1, 2, 3] -> [()),(), ()(,
															 (, ((, 
															 ((), (((] ->[(), ()(, (, ((, ((), (((]
		[0, 1, 2, 3]
(***->  [0, 1, 2, 3, 4]
(***) -> [0, 1, 2, 3]
*/
bool WIP_checkValidString(string s) {
	int minBalance = 0, maxBalance = 0;
	for(int i = 0; i < s.size(); i++){
		char currChar = s[i];
		if(currChar == '('){
			maxBalance++;
			minBalance++;
		}
		else if (currChar == ')'){
			maxBalance--;
			minBalance--;
		}
		else{
			//Wild card char - for minBalance assume it is a opening bracket ('(')
			//				   for maxBalance assume it is a closing bracket (')')
			maxBalance++;
			minBalance = max(0, minBalance - 1);
		}
		if(minBalance < 0 || maxBalance < 0)
			return false;
		cout<<minBalance<<" " << maxBalance<<endl;
	}

	if(minBalance == 0 || maxBalance == 0 || (minBalance < 0 && maxBalance > 0)){
		return true;	
	}
	return false;
    
}

//Generate all parenthesis strings - check each individually for balanced brackets
//TLE
bool TLE_checkValidString(string s) {
	//Generate all parenthesis strings by substituting in "*" for ")", "(" or ""
	bool res = false;
	vector<string> genStrings;
	genStrings.push_back("");

	for(int i = 0; i < s.size(); i++){
		vector<string> newStrings;
		for(auto & currString : genStrings){
			if(s[i] != '*')
				currString.push_back(s[i]);
			else{
				newStrings.push_back(currString + ")");
				newStrings.push_back(currString + "(");
			}		
		}
		if(!newStrings.empty()){
			for(auto newS : newStrings)
				genStrings.push_back(newS);
		}
	}

	for(auto genParen : genStrings){
		int balance = 0;
		for(int i = 0; i < genParen.size(); i++){
			if(genParen[i] == ')')
				balance += 1;
			else
				balance -= 1;
		}
		if (balance == 0)
			res |= true;		
	}
	//cout<<"Printing generated strings"<<endl;
	//printVec(genStrings);
	//cout<<"Done printing generated strings"<<endl;
	return res;    
}

bool checkValidString(string s) {
	//return TLE_checkValidString(s);
	//return WIP_checkValidString(s);
	//return TLE_recursive_checkValidString(s);
	return linear_checkValidString(s);
}

int main(){

	vector<string> testCases = {"(", "()", "(*)", "(*))", "******((((","(((()))())))*))())()(**(((())(()(*()((((())))*())(())*(*(()(*)))()*())**((()(()))())(*(*))*))())"};
	vector<bool> expectedRes = {false, true, true, true, false, false};
	assert(testCases.size() == expectedRes.size());
	cout<<boolalpha;
	for(int i = 0; i < testCases.size(); i++){
		cout<< "input: " << testCases[i] << ": "<< (checkValidString(testCases[i]) == expectedRes[i] ? "passed" : "failed") <<endl;	
	}

}


