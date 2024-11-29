/*******************************************************************************
 *      file name: number_of_subarrays_with_bounded_maximum.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/29-09:46:48                              
 *  modified time: 2019/05/29-09:46:48                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	/*(
	bool is_valid(int x) {
		return (x >= L && x <= R);
	}
	*/

    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		int ret = 0;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] >= L && A[i] <= R)
			{
				int left_n = 0;
				int j = i-1;
				while (j >= 0 && A[j] < L )
				{
					left_n++;
					j--;
				}
				int right_n = 0;
				j = i + 1;
				while (j < A.size() && A[j] <= R )
				{
					right_n++;
					j++;
				}
                int sum = (left_n + 1)* (right_n+1);
				ret += sum;
                cout<<"A["<<i<<"]:"<<A[i]<<"  sum:"<<sum<<" ret:"<<ret<<endl;
			}
		}
		return ret;

    }
};
int main()
{}
