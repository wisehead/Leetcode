/*******************************************************************************
 *      file name: plus_one.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/10/30-10:10                                    
 * modified time: 17/10/30-10:10                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void print_vec(vector<int>& digits)
	{
		vector<int>::iterator it;
		for (it = digits.begin(); it != digits.end(); it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
    vector<int> plusOne(vector<int>& digits) {
		cout<<"input vec is: ";
		print_vec(digits);
		int len = digits.size();
		int carry_flag = 0;
		for (int i=len -1; i>=0 ; i--)
		{
			if (i == len - 1)
			{
				digits[i] = digits[i] + 1 + carry_flag;
			}
			else
			{
				digits[i] = digits[i] + carry_flag;
			}
			carry_flag = 0;
			if(digits[i] > 9) 
			{
				digits[i] -= 10;
				carry_flag = 1;
			}

		}
		if (carry_flag == 1)
		{
			digits.push_back(0);
			for (int i=len -1; i>=0 ; i--)
			{
				digits[i+1] = digits[i];
			}
			digits[0] = 1;
		}
		return digits;
    }
};
int main()
{
	Solution sol;
	vector<int> vec1;
	vector<int> vec2;
	vector<int> vec3;
	int array1[] = {0};
	vector<int> input1(array1, array1 + 1);
	int array2[] = {9,9,9};
	vector<int> input2(array2, array2 + 3);
	int array3[] = {};
	vector<int> input3;
	vec1 = sol.plusOne(input1);
	sol.print_vec(vec1);
	vec2 = sol.plusOne(input2);
	sol.print_vec(vec2);
	vec1 = sol.plusOne(input3);
	sol.print_vec(vec1);
}
