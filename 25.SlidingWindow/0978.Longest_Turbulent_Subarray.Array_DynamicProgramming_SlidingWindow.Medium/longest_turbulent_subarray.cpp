/*******************************************************************************
 *      file name: longest_turbulent_subarray.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/08-09:59:09                              
 *  modified time: 2019/07/08-09:59:09                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool is_monotonic(vector<int>& A, int i) {
		if ((A[i] >= A[i-1] && A[i-1] >= A[i-2]) 
				|| (A[i] <= A[i-1] && A[i-1] <= A[i-2]) )
			return true;
		return false;
	}
    int maxTurbulenceSize(vector<int>& A) {
		int n = A.size();
        if (n <= 1) 
            return n;
        if (n == 2)
        {
            if (A[0] == A[1])
                return 1;
            return 2;
        }
		int cnt = 2;
        if (A[1] == A[0])
            cnt--;
		int max_cnt = cnt;
        
		for (int i = 2; i < n; i++)
		{
            //cout<<"A["<<i<<"]"<<A[i]<<endl;
			if (is_monotonic(A, i))
            {
                cnt = 2;
                if (A[i] == A[i-1])
                    cnt--;	
            }
			else
			{
				cnt++;
				max_cnt = max(max_cnt, cnt);
			}
            //cout<<"cnt:"<<cnt<<"    max_cnt:"<<max_cnt<<endl;
		}
		return max_cnt;
    }
};
int main()
{}
