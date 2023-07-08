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

using namespace std;

void printVec(vector<string> inputVec){
	for(auto s : inputVec)
		cout<<s<<", ";
	cout<<endl;
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
bool checkValidString(string s) {
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

int main(){

	//vector<string> testCases = {"()", "(*)", "(*))", "(((((*(()(***********", "(((((*(()(**", "(((((*(((((*((**(((*)*((((**))*)*)))))))))((*(((((*()*(**)", "(***)"};
	vector<string> testCases = {"******((((","(((()))())))*))())()(**(((())(()(*()((((())))*())(())*(*(()(*)))()*())**((()(()))())(*(*))*))())"};
	
	
		

	for(auto test : testCases){
		cout<< "test: " << test << ": "<< checkValidString(test)<<endl;	
	}

}


