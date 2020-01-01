/*******************************************************************************
 *      file name: find_the_town_judge.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/12/31-22:07:44                              
 *  modified time: 2019/12/31-22:07:44                              
 *******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (trust.empty() && N ==1) return 1;
		map<int, int> mm;
		set<int> ss;
		set<int> rs;
		for (int i = 0; i < trust.size(); i++) {
			vector<int> &vec = trust[i];
			rs.insert(vec[0]);
			if (mm.count(vec[1]))
				mm[vec[1]]++;
			else
				mm[vec[1]] = 1;
			if (mm[vec[1]] == N - 1)
				ss.insert(vec[1]);
		}
        
        for (auto e: ss)
        {
            if (rs.count(e)) ss.erase(e);
        }
		if (ss.size() == 1)
			return *ss.begin();
		return -1;
    }
};
int main()
{}
