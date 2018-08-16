/*******************************************************************************
 *      file name: largest_palidrome.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/16-11:31:25                              
 *  modified time: 2018/08/16-11:31:25                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int64_t x) 
	{
		bool ret = false;
		//int (-2147483648 ~ 2147483647)
		//     -2147447412
		char num_str[32];
		bzero(num_str, 32);
		snprintf(num_str, 32, "%lld", x);
		if (x < 10)
		{
			if (x >= 0)
			{
				ret = true;
			} 
			std::cout<<"input: "<<x<<" output:"<<ret<<std::endl;
			return ret;
		}
		char* ptr = num_str;
		int num_len = strlen(ptr);
		ret = true;
		for (int i = 0; i < num_len/2; i++)
		{
			if (ptr[i] != ptr[num_len + -1 - i])
			{
				ret = false;
				break;
			}
		}
		//std::cout<<"input: "<<x<<" output:"<<ret<<std::endl;
		return ret;
	}
    int largestPalindrome(int n) {
		int high = 1;
		for (int k = 0; k < n; k++)
			high = high * 10;

		int64_t max_palindrome = 0;
		for (int64_t i = high*high; i > high*high/100; i-- )
		{
			if (isPalindrome(i))
			{
				for (int j = high; j*j >i ; j--)
				{
					if (i % j ==0 && i/j <= high)
					{
						max_palindrome = i;
						cout<<"max_palindrome is:"<<max_palindrome<<endl;
						return (max_palindrome % 1337);
					}
				}
			}
		}
		cout<<"max_palindrome is:"<<max_palindrome<<endl;
		return (max_palindrome % 1337);
    }
};
int main()
{
	Solution sol;
	//sol.largestPalindrome(2);
	//sol.largestPalindrome(3);
	//sol.largestPalindrome(4);
	sol.largestPalindrome(5);
	//sol.largestPalindrome(6);
}
