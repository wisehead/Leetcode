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
			int cnt = 0; int last_k = 0;
			for (int j = 0; j < min(i+1,na); j++)
			{
                for (int k = last_k; k <= i; k++)
                {
			    	if (A[j] == B[k])
				    {
                        cout<<"i:"<<i<<"    j:"<<j<<"   k:"<<k<<endl;
				    	cnt++; 
                        cout<<"equal cnt:"<<cnt<<endl;
                        last_k = k+1;
                        break;
				    }
	
                }
			}

			ret = max(ret, cnt);
			cnt = 0; 
            int last_j = 0;
            for (int k = 0; k <= i; k++)
			{
                for (int j = last_j; j < min(i+1,na); j++)
                {
			    	if (A[j] == B[k])
				    {
                        cout<<"i:"<<i<<"    j:"<<j<<"   k:"<<k<<endl;
				    	cnt++; 
                        cout<<"equal   cnt:"<<cnt<<endl;
                        last_j = j+1;
                        break;
				    }
                }
			}
			ret = max(ret, cnt);
		}
		return ret;
    }
};
int main()
{}
