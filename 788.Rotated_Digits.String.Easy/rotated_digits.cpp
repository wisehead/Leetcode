/*******************************************************************************
 *      file name: rotated_digits.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/06-09:49:40                              
 *  modified time: 2018/11/06-09:49:40                              
 *******************************************************************************/
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
public:
	bool is_valid(char x) {
		return (x == '2' || x == '5' || x == '6' || x == '9' || x == '0' || x == '1' || x == '8');
	}
	bool is_018(char x) {
		return (x == '0' || x == '1' || x == '8');
	}

	bool is_good_num(int x) {
		stringstream ss;
		ss<<x; 
		string s1 = ss.str();
		cout<<s1<<endl; // 30
		if (s1.length() == 0) return false;
		bool is_self_equal = true;
		for (int i=0; i < s1.length(); i++)
		{
			if (!is_valid(s1[i]))
				return false;
			is_self_equal = is_self_equal & is_018(s1[i]);
		}
		if (is_self_equal)
			return false;
		return true;
	}

    int rotatedDigits(int N) {
		int count = 0;
		for (int i=1; i <= N; i++)
		{
			if (is_good_num(i))
				count++;
		}
		return count;
    }
};
int main()
{}
