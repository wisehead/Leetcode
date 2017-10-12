/*******************************************************************************
 *      File Name: valid_par.cpp                                               
 *         Author: Hui Chen. (c) 2017                             
 *           Mail: chenhui13@baidu.com                                        
 *   Created Time: 2017/10/12-22:06                                    
 * Modified Time: 2017/10/12-22:06                                    
 *******************************************************************************/
#include <iostream>
#include<stack>
using namespace std;
class Solution {
public:
	bool isLeft(char c_in)
	{
		if (c_in == '(' || c_in == '[' || c_in == '{' )
			return true;
		return false;
	}
	bool isRight(char c_in)
	{
		if (c_in == ')' || c_in == ']' || c_in == '}' )
			return true;
		return false;
	}
	bool isMatch(char c_1, char c_2)
	{
		if ((c_1 == '(' &&  c_2 == ')')
				|| (c_1 == ')' &&  c_2 == '(')
			   	|| (c_1 == '[' &&  c_2 == ']')
				|| (c_1 == ']' &&  c_2 == '[')
			   	|| (c_1 == '{' &&  c_2 == '}') 
				|| (c_1 == '}' &&  c_2 == '{'))
			return true;
		return false;
	}
	bool isValid(string s) {
		cout<<"input s is: "<<s<<endl;
		bool ret = true;
		if (s.empty())
		{
			ret = false;
			cout<<"The result is: "<<ret<<endl;
			return ret;
		}
		int len = s.length();
		if (len % 2 == 1)
		{
			ret = false;
			cout<<"The result is: "<<ret<<endl;
			return ret;
		}
		char *p_array = new char[len + 1];
		bzero(p_array, len + 1);
		snprintf(p_array, len+1, "%s", s.c_str());
		while (!_m_stack.empty())
			_m_stack.pop();
		char *ptr = p_array;
		for(;*ptr != 0; ptr++)
		{
			if (isLeft(*ptr))
				_m_stack.push(*ptr);
			else if (isRight(*ptr) && !_m_stack.empty() && isMatch(*ptr, _m_stack.top()) )
			{
				_m_stack.pop();
				continue;
			}
			else
			{
				// ]/}/) can't match
				ret = false;
				break;
			}
		}
		
		if (p_array)
		{
			delete [] p_array;
			p_array = NULL;
		}
		if (!_m_stack.empty())
			ret = false;
		cout<<"The result is: "<<ret<<endl;
		return ret;
	}
private:
	stack<char> _m_stack;
};

int main()
{
	Solution sol;
	sol.isValid("");
	sol.isValid("[(){}]");
	sol.isValid("[([]){}]");
	sol.isValid("[(h]){}]");
	sol.isValid("(h]){}]");
	sol.isValid("((");
	sol.isValid("))");
}
