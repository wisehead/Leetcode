/*******************************************************************************
 *      file name: reorder_log_files.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/29-09:45:04                              
 *  modified time: 2019/01/29-09:45:04                              
 *******************************************************************************/
#include <iostream>
#include <ctype.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> digits;
		vector<string> alphas;
		vector<string> res;
		for ( auto& e: logs)
		{
			auto pivot = e.find_first_of(' '); auto key = e.substr( 0, pivot ), value = e.substr( pivot+1 );
			if (isdigit(value[0])) 
                digits.push_back(e);
			else
				alphas.push_back(value + " " + key);
		}
		sort(alphas.begin(), alphas.end());
		for ( auto& e: alphas)
		{
			auto pivot = e.find_last_of(' '); auto value = e.substr( 0, pivot ), key = e.substr( pivot+1 );
			res.push_back(key + " " + value);
		}
        res.insert(res.end(), digits.begin(), digits.end());
		return res;
    }
};
int main()
{}
