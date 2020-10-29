/*******************************************************************************
 *      file name: n_repeated_element_in_size_2n_array.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/04-11:39:37                              
 *  modified time: 2019/02/04-11:39:37                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
		map<char, int> mm;
		for (auto &e : A)
		{
			if(mm.count(e)) return e; 
			mm[e] = 1;
		}
		return 0;
    }
};
int main()
{}
