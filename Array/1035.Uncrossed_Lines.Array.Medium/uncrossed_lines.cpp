/*******************************************************************************
 *      file name: uncrossed_lines.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/20-14:18:42                              
 *  modified time: 2019/07/20-14:18:42                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		if (A.size() > B.size())
			A.swap(B);
		int na = A.size();
		int nb = B.size();
		int ret = 0;
		for (int i = 0; i < nb; i++)
		{
			int cnt = 0;
			for (int j = 0, k = 0; j < min(i+1,na) && k <= i; )
			{
				if (A[j] == B[k])
				{
					cnt++; j++; k++;
				}
				else
					k++;
			}
			ret = max(ret, cnt);
			cnt = 0;
			for (int j = 0, k = 0; j < min(i+1,na) && k <= i; )
			{
				if (A[j] == B[k])
				{
					cnt++; j++; k++;
				}
				else
					j++;
			}
			ret = max(ret, cnt);
		}
		return 0;
    }
};
int main()
{}
