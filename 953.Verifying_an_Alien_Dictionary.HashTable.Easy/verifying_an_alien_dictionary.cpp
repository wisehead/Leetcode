/*******************************************************************************
 *      file name: verifying_an_alien_dictionary.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/03-20:33:29                              
 *  modified time: 2019/02/03-20:33:29                              
 *******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
	bool is_order(string A, string B) {
		for (int i=0; i < A.length(); i++)
		{
			if (_mm[A[i]] < _mm[B[i]]) return true;
            if (_mm[A[i]] > _mm[B[i]]) return false;
		}
		return false;
	}

    bool isAlienSorted(vector<string>& words, string order) {
		for (int i = 0; i < order.length(); i++)
		{
			_mm[order[i]] = i;
		}
		for (int i = 0; i < words.size() - 1; i++)
		{
			if (!is_order(words[i], words[i+1])) return false;
		}
		return true;
    }
private:
	map<char, int> _mm;
};
int main()
{}
