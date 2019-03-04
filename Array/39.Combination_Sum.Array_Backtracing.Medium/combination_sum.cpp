/*******************************************************************************
 *      file name: combination_sum.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/04-09:51:47                              
 *  modified time: 2019/03/04-09:51:47                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > csr(vector<int>& candidates, int M, int target) {
		vector<vector<int> > res;
		set<vector<int> > s1;
        if (candidates.size() == 0 || candidates[0] > target) return res;

        int i = 0;
        for (i = M; i >= 0; i--)
        {
            if (target == candidates[i])
		    {
			    vector<int> vec;
			    vec.push_back(target);
			    s1.insert(vec);
		    }
            else if (target >  candidates[i])
                break;
            else
                continue;
        }
        M = i;
		for (i = 0; i < candidates.size(); i++)
		{
			vector<vector<int> > vv = csr(candidates, M, target - candidates[i]);
			for (int j = 0; j < vv.size(); j++)
			{
				vector<int> v = vv[j];
                v.push_back(candidates[i]);
                /*
                cout<<"i:"<<i<<"    j:"<<j<<endl;
                for (int k=0; k<v.size(); k++)
                    cout<<"v["<<k<<"]"<<v[k];
                cout<<endl;
                */
                sort(v.begin(), v.end());
				s1.insert(v);
			}
		}
		res.assign(s1.begin(), s1.end());
		return res;
	}
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > res = csr(candidates, candidates.size() - 1, target);
		return res;
    }
};
int main()
{}
