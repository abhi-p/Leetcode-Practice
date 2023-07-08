/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

 

Constraints:

    1 <= coins.length <= 12
    1 <= coins[i] <= 231 - 1
    0 <= amount <= 104
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*void coinChangeRecursiveHelper(vector<int>& coins, int amount, int& numCoins){
  //base case
  if(amount == 0){
    return;
  }
  else if (amount < 0){
    numCoins = -1;
    return;
  }
  
  for(int i = coins.size() - 1; i >= 0; i--){
    if(coins[i] < amount){
      numCoins++;
      coinChangeRecursiveHelper(coins, amount - coins[i], numCoins);
    }
  }
  if(amount != 0){
    numCoins = -1;
  }
  return;
}*/

void coinChangeRecursiveHelper(vector<int>& coins, int amount, int numCoins, int& leastNumCoins){
  //cout << "amount: " << amount << " numCoins: " << numCoins << " leastNumCoins: "<< leastNumCoins << endl;
  //base case
  if(amount == 0){
    if(numCoins < leastNumCoins){
      leastNumCoins = numCoins;
    }
    return;
  }
  else if (amount < 0){
    return;
  }
  
  for(const int & coinDenom : coins){
		numCoins +=1;
		amount -= coinDenom;
    coinChangeRecursiveHelper(coins, amount, numCoins, leastNumCoins);
		numCoins -=1;
		amount += coinDenom;
  }

  return;
}

int coinChange(vector<int>& coins, int amount) {
  int returnVal = INT_MAX;
  
  coinChangeRecursiveHelper(coins, amount, 0, returnVal);

	//No possible coin combination sums up to input amount
	if (returnVal == INT_MAX)
		returnVal = -1;
  
  return returnVal;
}

int main() {

  vector<int> input1 = {1,2,5};
  int amount1 = 3;
  
  cout<<"numCoins: " << coinChange(input1, amount1) <<endl<<endl;
  
  input1 = {1,2,5};
  amount1 = 11;
  
  cout<<"numCoins: " << coinChange(input1, amount1) <<endl<<endl;

  input1 = {2,5};
  amount1 = 1;
  
  cout<<"numCoins: " << coinChange(input1, amount1) <<endl<<endl;

  input1 = {1,2,5};
  amount1 = 100;
  
  cout<<"numCoins: " << coinChange(input1, amount1) <<endl<<endl;
  
}
