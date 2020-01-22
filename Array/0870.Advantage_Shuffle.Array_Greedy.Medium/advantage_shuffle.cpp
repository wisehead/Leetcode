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
struct Unit 
{
    int key;
    int index;
};	
bool compare_unit(const Unit& a, const Unit& b) 
{
    return (a.key > b.key);
}
void printvec(vector<int>& vec)
{
    for (auto e: vec)
        cout<<e<<" ";
    cout<<endl;
}
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
		vector<int> res(A.size(), 0);
		sort(A.begin(), A.end());
		reverse(A.begin(), A.end());
		vector<Unit> C;
		for (int k = 0; k < B.size(); k++)
		{
			struct Unit u;
			u.key = B[k];
			u.index = k;
			C.push_back(u);
		}
		sort(C.begin(), C.end(), compare_unit);
		int i = 0, j = 0;
        int last = n-1; 
		while (i < A.size())
		{
			while (j < C.size())
			{
				if (A[i] > C[j].key)
				{
					res[C[j].index] = A[i];
					j++;
					break;
				}
				else//B[i] >= A[j]
                {
					res[C[j].index] = A[last--];
					j++;
                }
			}
			i++;
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
	res = sol.advantageCount(A, B);
}
