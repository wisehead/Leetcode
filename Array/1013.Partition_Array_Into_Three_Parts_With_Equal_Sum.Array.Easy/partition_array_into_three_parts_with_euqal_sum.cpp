/*******************************************************************************
 *      file name: partition_array_into_three_parts_with_euqal_sum.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/14-15:58:33                              
 *  modified time: 2019/07/14-15:58:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
		int n = A.size();
		vector<int> sumvec(n, 0);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += A[i];
			sumvec[i] = sum;
		}
		sum = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			sum += A[i];
			vector<int>::iterator it = find(sumvec.begin(), sumvec.end(), sum);
			while (it != sumvec.end())
			{
				int pos = it - sumvec.begin();
				if (pos >= i - 1) break;
				int third = sumvec[i-1] - sumvec[pos];
				if (third == sum) return true;
                it = find(it+1, sumvec.end(), sum);
			}
		}
		return false;
    }
};
int main()
{}
