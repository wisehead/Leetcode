/*******************************************************************************
 *      file name: largest_palidrome.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/16-11:31:25                              
 *  modified time: 2018/08/16-11:31:25                              
 *******************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upper = pow(10, n) - 1;
        int lower = pow(10, n-1);
        for (int i = upper; i >= lower; i--) {
            long cand = buildPalindrome(i);
            for (long j = upper; j*j >= cand; j--) {
                if (cand % j == 0 && cand / j <= upper) {
                    return cand % 1337;
                }
            }
        }
        return -1;
    }
    
    long buildPalindrome(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stol(to_string(n) + s);
    }
};
int main()
{
	Solution sol;
	long ret = 0;
	//sol.largestPalindrome(2);
	//sol.largestPalindrome(3);
	//sol.largestPalindrome(4);
	ret = sol.largestPalindrome(5);
	cout<<"ret:"<<ret<<endl;
	//sol.largestPalindrome(6);
}
