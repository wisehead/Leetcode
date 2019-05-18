/*******************************************************************************
 *      file name: maximum_length_of_repeated_subarray.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/18-10:17:15                              
 *  modified time: 2019/05/18-10:17:15                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
	void printV(vector<int>& vec) {
		for (auto e:vec)
			cout<<e<<"	";
		cout<<endl;
	}
    int findLength(vector<int>& A, vector<int>& B) {
		int max_l = 0;
		for (auto e : A)
		{
			_ss.insert(e);
		}
		for (int i = 0; i < B.size(); i++)
		{
			int x = B[i];
			if (!_ss.count(x)) continue;
			vector<int> vec(B.begin() + i, B.end());
			if (!_mm.count(x))
			{
				vector<vector<int>> vv;
				vv.push_back(vec);
				_mm[x] = vv; 
			}
			else
			{
				_mm[x].push_back(vec);
			}
		}
		map<int, vector<vector<int> >>::iterator it;
		for (it = _mm.begin(); it != _mm.end(); it++)
		{
			vector<vector<int>> vv = it->second;
			vector<vector<int>>::iterator itvv;
			for (itvv = vv.begin(); itvv != vv.end(); itvv++)
			{
				printV(*itvv);
			}
		}
		// start matching 
		for (int i = 0; i < A.size(); i++)
		{
			int x = A[i];
			if (!_mm.count(x)) continue;
			vector<vector<int>> vv = _mm[x];
			for (int j = 0; j < vv.size(); j++)
			{
				vector<int> vec = vv[j];
				int k = 0;
				while (i+k < A.size() && k < vec.size() && vec[k] == A[i+k])
					k++;
				cout<<"k:"<<k<<endl;
                if (k==B.size()) return k;
				if (k > max_l) max_l = k;
			}
		}
		return max_l;
    }
private:
	map<int, vector<vector<int> >> _mm;
	set<int> _ss;
};
int main()
{
	Solution sol;
	//int arrA[] = {1,2,3,2,1};
	//int arrB[] = {3,2,1,4,7};
	int arrA[] = {0,0,0,0,0};
	int arrB[] = {0,0,0,0,0};
	vector<int> A(arrA, arrA+5);
	vector<int> B(arrB, arrB+5);
	sol.findLength(A, B);
}
