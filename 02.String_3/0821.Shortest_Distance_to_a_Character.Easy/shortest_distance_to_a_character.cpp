/*******************************************************************************
 *      file name: shortest_distance_to_a_character.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/10-11:36:08                              
 *  modified time: 2018/11/10-11:36:08                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
		int len = S.length();
		vector<int> res;
		for (int i=0; i < len; i++)
		{
			if (S[i] == C) res.push_back(0);
			else
			{
				int min_dis = INT_MAX;
				int right_pos = S.find(C, i);
				if (right_pos != string::npos)
				{
					int right_dis = right_pos - i;
					cout<<"right_dis:"<<right_dis<<endl;
					min_dis = min(min_dis, right_dis);
				}
				int left_pos = S.rfind(C, i);
				if (left_pos != string::npos)
				{
					int left_dis = i - left_pos;
					cout<<"left_dis:"<<left_dis<<endl;
					min_dis = min(min_dis, left_dis);
				}
				cout<<"min_dis:"<<min_dis<<endl;
				res.push_back(min_dis);
			}
		}
		return res;
    }
};
int main()
{}
