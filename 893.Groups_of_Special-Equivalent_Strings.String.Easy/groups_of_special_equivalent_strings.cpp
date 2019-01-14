/*******************************************************************************
 *      file name: groups_of_special_equivalent_strings.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/14-11:17:38                              
 *  modified time: 2019/01/14-11:17:38                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
	bool is_eq(string A, string B) {
		cout<<"start A:"<<A<<"	B:"<<B<<endl;
		if (A.length() != B.length()) return false;
		string pingA, pongA;
		for (int i=0; i<A.length(); i++)
		{
			if (i%2 == 0)
				pingA = pingA.append(1, A[i]);
			else
				pongA = pongA.append(1, A[i]);
		}
		string pingB, pongB;
		for (int i=0; i<B.length(); i++)
		{
			if (i%2 == 0)
				pingB = pingB.append(1, B[i]);
			else
				pongB = pongB.append(1, B[i]);
		}
		cout<<"MID A:"<<A<<"	B:"<<B<<"	pingA:"<<pingA<<"	pingB:"<<pingB<<"	pongA:"<<pongA<<"	pongB:"<<pongB<<endl;
		sort(pingA.begin(), pingA.end());
		sort(pingB.begin(), pingB.end());
		sort(pongA.begin(), pongA.end());
		sort(pongB.begin(), pongB.end());
		cout<<"END A:"<<A<<"	B:"<<B<<"	pingA:"<<pingA<<"	pingB:"<<pingB<<"	pongA:"<<pongA<<"	pongB:"<<pongB<<endl;
		return (pingA.compare(pingB) == 0 && pongA.compare(pongB) == 0);
	}
    int numSpecialEquivGroups(vector<string>& A) {
		int count = 0;
		map<int, vector<string> > mm;
		int size = A.size();
		for (int i=0; i<size; i++)
		{
			string temp = A[i];
			int len = temp.length();
			cout<<"i:"<<i<<"	temp:"<<temp<<"	len:"<<len<<endl;
			if (!mm.count(len))
			{
				vector<string> vec;
				vec.push_back(temp);
				mm[len] = vec; 
				count++;
				cout<<"len:"<<len<<" does not exist. count:"<<count<<endl;
			}
			else
			{
				vector<string> vec = mm[len]; 
				int k = 0;
				for (k=0; k<vec.size(); k++)
				{
					cout<<"vec["<<k<<"]:"<<vec[k]<<endl;
					if (is_eq(vec[k], temp))
						break;
				}
				if (k == vec.size())
				{
					vec.push_back(temp);
					mm[len] = vec; 
					count++;
					cout<<"string:"<<temp<<" does not exist. count:"<<count<<endl;
				}

			}
		}
		return count;
    }
};
int main()
{
	Solution sol;
	string arr[] = {"a","b","c","a","c","c"};
	vector<string> vec(arr, arr+6);
	/*
	string arr[] = {"aa","bb","ab","ba"};
	vector<string> vec(arr, arr+4);
	*/
	/*
	string arr[] = {"abcd","cdab","adcb","cbad"};
	vector<string> vec(arr, arr+4);
	*/
	/*
	string arr[] = {"abc","acb","bac","bca","cab","cba"};
	vector<string> vec(arr, arr+6);
	*/
	int ret = sol.numSpecialEquivGroups(vec);
	cout<<"count:"<<ret<<endl;
}

