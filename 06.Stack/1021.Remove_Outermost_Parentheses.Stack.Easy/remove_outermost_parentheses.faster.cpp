/*******************************************************************************
 *      file name: remove_outermost_parentheses.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/17-09:47:11                              
 *  modified time: 2020/09/17-09:47:11                              
 *******************************************************************************/
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string S) {
		stack<char> mystack1;
		stack<char> mystack2;
		string res;
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] == '(' ) {
			  if (mystack1.empty())
				mystack1.push(S[i]);
			  else {
                  res.append(1, S[i]);
				  mystack2.push(S[i]);
              }
			} else {//(S[i] == ')' ) 
				if (!mystack2.empty()) {
					mystack2.pop();
					res.append(1, S[i]);
				} else if (!mystack1.empty()) {
					mystack1.pop();
				}
			}	
		}
		return res;
    }
};
int main()
{}
