/*50. Pow(x, n)
Medium
6.1K
6.6K
company
Facebook
company
Amazon
company
Apple
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
-104 <= xn <= 104*/

#include <iostream>
#include <map>

using namespace std;

double recursiveMyPow(double x, long long n, map<int, double>& memo){
//2^8=256
//memo[2]=4
//memo[4]=16
//memo[8]=256
  if(n == 0)
    return 1;
  if(n == 1)
     return x;
  if(memo.count(n) > 0)
    return memo[n];

  if(n%2 != 0){
    double ans = x * recursiveMyPow(x, n-1, memo);
    memo[n] = ans;
    return memo[n];
  }
  else{
    double ans = recursiveMyPow(x, n/2, memo);
    memo[n] = ans*ans;
    return memo[n];
  }
}
double myPow(double x, int n) {
    if(x == 1)
        return 1;
    long long power = n;
  //Key: power value, value: x^n
  map<int,double> memo;
  if (power<0){
    x=1/x;
    power*=-1;
  }
  return recursiveMyPow(x,power,memo);

}

int main()
{
  //cout<<myPow(2,8)<<endl;
  //cout<<myPow(2,-5)<<endl;
  //cout<<myPow(2.1,3)<<endl;
  cout<<myPow(2.0,-1 * (INT_MAX) - 1)<<endl;
    std::cout << "Practice makes Perfect!" << std::endl;
    return 0;
}

