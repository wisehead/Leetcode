/*******************************************************************************
 *      file name: reverse_vowels_of_string.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/06- 1:01                                    
 *  modified time: 18/01/06- 1:01                                    
 *******************************************************************************/
#include <iostream>
//#include <algorithm>
using namespace std;
class Solution {
public:
	bool is_vowels(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	}
    string reverseVowels(string s) {
		int size = s.length();
		int left = 0, right = size - 1;
		while (left < right)
		{
			while (left < size && !is_vowels(s[left]))
			{
				left++;
			}
			while (right >= 0 && !is_vowels(s[right]))
			{
				right--;
			}
			if (left >= right)
				break;
			swap(s[left], s[right]);
			left++;right--;
		}
		return s;
    }
};
int main()
{
	Solution sol;
	string s ="leetcode";
	string out;
	out = sol.reverseVowels(s);
	cout<<"reverse stirng for "<<s<<" is:"<<out<<endl;
}
