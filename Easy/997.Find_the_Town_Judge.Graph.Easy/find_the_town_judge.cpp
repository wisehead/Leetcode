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
#include <set>
using namespace std;
class Solution {
public:
    void print_set(set<int>& s)
    {
        set<int>::iterator it;
        cout << "the results is:"<< endl;
        for (it = s.begin(); it != s.end(); it++)
        {
            cout << *it << " ";
        }
        cout<<endl;
    }

    int findJudge(int N, vector<vector<int>>& trust) {
        if (trust.empty() && N ==1) return 1;
		set<int> ss;
        set<int> s;
		int index = 0;
		sort(trust.begin(), trust.end());
		for (int i = 0; i < trust.size(); i++)
		{
			if (trust[i][0] == trust[0][0])
				ss.insert(trust[i][1]);
		}
		for (int i = 0; i < trust.size(); i++) {
			
		    //vector<int> c;
			vector<int> vec = trust[i];
			if (i == 0) index = vec[0];
			if (vec[0] == index)
			{
				if (ss.count(vec[1]))
					s.insert(vec[1]);
			}
			else
			{
				index = vec[0];
                if (s.empty()) return -1;
				ss.swap(s);
                s.clear();
                if (ss.count(vec[1]))
					s.insert(vec[1]);
            
			}
			if (i == trust.size() - 1)
            {
                if (s.empty()) return -1;
                ss.swap(s);
            }
				
            //cout<<"i:"<<i<<"    ss is:"<<endl;
			//print_set(ss);
            //cout<<"s is:"<<endl;
            //print_set(s);
		}
		if (ss.size() == 1)
			return *ss.begin();
		return -1;
    }
};
int main()
{}
