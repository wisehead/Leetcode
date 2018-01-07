/*******************************************************************************
 *      file name: guess_num_higher_or_lower.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/07- 1:01                                    
 *  modified time: 18/01/07- 1:01                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
#define GUESS 1702766719 
int guess(int num) {
	if (num == GUESS)
		return 0;
	else if (num > GUESS)
		return -1;
	else 
		return 1;
}

class Solution {
public:
    int guessNumber(int n) {
		uint64_t left = 1, right = n, mid = (left+right)/2;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (guess(mid) == 0)
				return mid;
			if (guess(mid) == 1)
				left = mid + 1;
			else
				right = mid;
		}
		return left;
    }
};
int main()
{
	Solution sol;
	int ret = 0;
	ret = sol.guessNumber(2126753390);
	cout<<"ret is:"<<ret<<endl;
}
