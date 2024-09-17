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
	int mul(vector<int>& A, vector<int>& B) {
		int na = A.size();
		int nb = B.size();
		int ret = 0;
		for (int start = 0; start < na; start++)
		{
			int cnt = 0, last_k = 0;
			for (int j = start; j < na; j++)
			{
                for (int k = last_k; k < nb; k++)
                {
			    	if (A[j] == B[k])
				    {
                        //cout<<"i:"<<i<<"    j:"<<j<<"   k:"<<k<<endl;
				    	cnt++; 
                        //cout<<"equal cnt:"<<cnt<<endl;
                        last_k = k+1;
                        break;
				    }
	
                }
			}
			ret = max(ret, cnt);
		}
		return ret;
	}
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		int ret = 0;
		int r1 = 0;
		r1 = mul(A, B);
		ret = max(ret, r1);
		r1 = mul(B, A);
		ret = max(ret, r1);
		reverse(A.begin(), A.end());
		reverse(B.begin(), B.end());
		r1 = mul(A, B);
		ret = max(ret, r1);
		r1 = mul(B, A);
		ret = max(ret, r1);
		return ret;
    }
};
int main()
{}
