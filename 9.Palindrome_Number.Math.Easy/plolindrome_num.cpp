/*******************************************************************************
 *      File Name: plolindrome_num.cpp                                               
 *         Author: Hui Chen. (c) 2017                             
 *           Mail: chenhui13@baidu.com                                        
 *   Created Time: 2017/09/30-23:27                                    
 * Modified Time: 2017/09/30-23:27                                    
 *******************************************************************************/
#include <iostream>
#include <stdio.h>
//using namespace std;
class Solution {
public:
	bool isPalindrome(int x) 
	{
		bool ret = false;
		//int (-2147483648 ~ 2147483647)
		//     -2147447412
		char num_str[32];
		bzero(num_str, 32);
		snprintf(num_str, 32, "%d", x);
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
		std::cout<<"input: "<<x<<" output:"<<ret<<std::endl;
		return ret;
	}
};

int main()
{
	//121
	//123
	//12
	//11
	//-11
	//-121
	//0
	//-9
	//9
	//-123454321
	//123454321
	std::cout<<"Start testing:"<<std::endl;
	Solution sol;
	sol.isPalindrome(121);
	sol.isPalindrome(123);
	sol.isPalindrome(12);
	sol.isPalindrome(11);
	sol.isPalindrome(-11);
	sol.isPalindrome(-121);
	sol.isPalindrome(-1221);
	sol.isPalindrome(0);
	sol.isPalindrome(-9);
	sol.isPalindrome(9);
	sol.isPalindrome(-123454321);
	sol.isPalindrome(123454321);
	sol.isPalindrome(-2147447412);
	std::cout<<"End testing:"<<std::endl;
}
