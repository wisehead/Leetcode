/*******************************************************************************
 *      file name: min_index_of_two_lists.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/27-11:55:35                              
 *  modified time: 2018/08/27-11:55:35                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		int len1 = list1.size();
		int len2 = list2.size();
		int min = len1 + len2 - 2;
		vector<string> res;
		map<string, int> m;
		map<string, int>::iterator it;
		for (int i = 0; i < len1; i++)
		{
			m[list1[i]] = i;
		}
		for (int i = 0; i < len2; i++)
		{
			it = m.find(list2[i]);
			if (it != m.end())
			{
                //cout<<"i:"<<i<<"    string:"<<list2[i]<<"   index1:"<<it->second<<endl;
				m[list2[i]] += i;
                //cout<<"min:"<<min<<"    index_sum(m[list2[i]]):"<<m[list2[i]]<<endl;
				if (m[list2[i]] == min)
				{
					res.push_back(list2[i]);
				}
				else if (m[list2[i]] < min)
				{
                    min = m[list2[i]];
					res.clear();
					res.push_back(list2[i]);
				}
			}
		}
		return res;
    }
};
int main()
{}
