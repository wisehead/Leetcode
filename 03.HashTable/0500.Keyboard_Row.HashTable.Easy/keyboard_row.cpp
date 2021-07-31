/*******************************************************************************
 *      file name: keyboard_row.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/20-09:49:59                              
 *  modified time: 2018/08/20-09:49:59                              
 *******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef map<char, int> UDT_MAP_CHAR_INT; 
class Solution {
public:
	Solution() {
		my_map['Q'] = 1;
		my_map['q'] = 1;
		my_map['W'] = 1;
		my_map['w'] = 1;
		my_map['E'] = 1;
		my_map['e'] = 1;
		my_map['R'] = 1;
		my_map['r'] = 1;
		my_map['T'] = 1;
		my_map['t'] = 1;
		my_map['Y'] = 1;
		my_map['y'] = 1;
		my_map['U'] = 1;
		my_map['u'] = 1;
		my_map['I'] = 1;
		my_map['i'] = 1;
		my_map['O'] = 1;
		my_map['o'] = 1;
		my_map['P'] = 1;
		my_map['p'] = 1;

		//2nd row
		//ASDFGHJKL
		my_map['A'] = 2;
		my_map['a'] = 2;
		my_map['S'] = 2;
		my_map['s'] = 2;
		my_map['D'] = 2;
		my_map['d'] = 2;
		my_map['F'] = 2;
		my_map['f'] = 2;
		my_map['G'] = 2;
		my_map['g'] = 2;
		my_map['H'] = 2;
		my_map['h'] = 2;
		my_map['J'] = 2;
		my_map['j'] = 2;
		my_map['K'] = 2;
		my_map['k'] = 2;
		my_map['L'] = 2;
		my_map['l'] = 2;

		//3nd row
		//ZXZCVBNM
		my_map['Z'] = 3;
		my_map['z'] = 3;
		my_map['X'] = 3;
		my_map['x'] = 3;
		my_map['C'] = 3;
		my_map['c'] = 3;
		my_map['V'] = 3;
		my_map['v'] = 3;
		my_map['B'] = 3;
		my_map['b'] = 3;
		my_map['N'] = 3;
		my_map['n'] = 3;
		my_map['M'] = 3;
		my_map['m'] = 3;
	}

	bool is_one_row(string str) {
		int len = str.length();
		if (len == 0)
			return false;
		int result = my_map[str[0]];
		for (int i=1; i < len; i++)
		{
			if (my_map[str[i]] != result)
				return false;
		}
		return true;
	}

    vector<string> findWords(vector<string>& words) {
		vector<string> res;
		vector<string>::iterator it;
		for (it = words.begin(); it != words.end(); it++)
		{
			if(is_one_row(*it))
				res.push_back(*it);
		}
		return res;
    }
private:
	UDT_MAP_CHAR_INT my_map;
};
int main()
{}
