/*******************************************************************************
 *      file name: length_of_longest_fibonacci_subsequence.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/06/17-10:00:45                              
 *  modified time: 2019/06/17-10:00:45                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int cal(vector<int>& A, int a, int b) {
		int cnt = 0;
		bool first = true;
		int n = A.size();
		int c = a + b;
		while (c <= A[n-1])
		{
			 vector<int>::iterator result = find(A.begin(), A.end(), c);
			 if (result == A.end()) //没找到
			 {
				break;
			 }
		 	 else //找到
			 {
				if (first) 
                {
                    cnt = 3;
                    first = false;
                }
				else cnt++;
				a = b;
				b = c;
				c = a + b;
			 }
		}
		return cnt;
	}
    int lenLongestFibSubseq(vector<int>& A) {
		int max_f = 0;
		int n = A.size();
		for (int i = 0; i < n -2; i++)
		{
			for (int j = i+1; j < n -1; j++)
			{
				if (A[i] + A[j] > A[n-1]) continue;
				int temp = cal(A, A[i], A[j]);
				max_f = max(temp, max_f);
			}
		}
		return max_f;
    }
};
int main()
{}
