/*******************************************************************************
 *      file name: advantage_shuffle.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/06/15-16:03:16                              
 *  modified time: 2019/06/15-16:03:16                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> advantageCount(vector<int> A, vector<int> B) {
        map<int, int> m;
        for (int i : A) m[i]++;
        map<int,int>::iterator it;
        vector<int> res;
        for (int i : B) {
            it = m.upper_bound(i);
            int x = it != m.end() ? it->first : m.begin()->first;
            if (--m[x] == 0) m.erase(x);
            res.push_back(x);
        }
        return res;
    }
};
int main()
{
	Solution sol;
	int arrA[] = {12,24,8,32};
	int arrB[] = {13,25,32,11};
	vector<int> A(arrA, arrA+4);
	vector<int> B(arrB, arrB+4);
	vector<int> res;
	//res = sol.advantageCount(A, B);
}
