/*******************************************************************************
 *      File Name: reverse_int.cpp                                               
 *         Author: Hui Chen. (c) 2017                             
 *           Mail: chenhui13@baidu.com                                        
 *   Created Time: 2017/09/12-12:02                                    
 * Modified Time: 2017/09/12-12:02                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
#define MAX_INT_LEN 12
class Solution {
public:
	Solution() 
	{
		bzero(_from_str, MAX_INT_LEN);
		bzero(_to_str, MAX_INT_LEN);
	}
	
	// range of int [-2147483648～2147483647]
    int reverse(int x) {
		int ret = 0;
		long ret_long = 0;
		bzero(_from_str, MAX_INT_LEN);
		bzero(_to_str, MAX_INT_LEN);
		string x_str = to_string(x);		
		cout<<"x_str is:"<<x_str<<endl;
	 	snprintf(_from_str, MAX_INT_LEN, "%s", x_str.c_str());	
		int len = strlen(_from_str);
		if (x > 0)
		{
			for (int i=0; i<len; i++)
			{
				_to_str[i] = _from_str[len - i - 1];
			}
		}
		else if (x < 0)
		{
			_to_str[0] = '-';
			for (int i=1; i<len; i++)
			{
				_to_str[i] = _from_str[len - i];
			}
		}
		else
		{
			ret = 0;
		}
		cout<<"_from_str"<<_from_str<<endl;
		cout<<"_to_str"<<_to_str<<endl;
		ret = atoi(_to_str);
		ret_long = atol(_to_str);
		if (ret != ret_long)
			ret = 0;
        return ret; 
    }
private:
	char _from_str[MAX_INT_LEN];
	char _to_str[MAX_INT_LEN];
};

int main()
{
	Solution solution;
	int input = 258;
	int output = 0;
	output = solution.reverse(input);
	cout<<"output is:"<<output<<endl;
	input = -258;
	output = solution.reverse(input);
	cout<<"output is:"<<output<<endl;
	input = 0;
	output = solution.reverse(input);
	cout<<"output is:"<<output<<endl;
	// range of int [-2147483648～2147483647]
	input = -1147483649;
	output = solution.reverse(input);
	cout<<"output is:"<<output<<endl;
	input = 2147483648;
	output = solution.reverse(input);
	cout<<"output is:"<<output<<endl;
	input = 200;
	output = solution.reverse(input);
	cout<<"output is:"<<output<<endl;
}
