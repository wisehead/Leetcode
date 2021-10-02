/*******************************************************************************
 *      file name: length_of_longest_fibonacci_subsequence.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/06/17-10:00:45                              
 *  modified time: 2019/06/17-10:00:45                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
	int cal(vector<int>& A, set<int>& S, map<vector<int>, int>&  M, int a, int b) {
		int cnt = 0;
		bool first = true;
		int n = A.size();
		int c = a + b;
		while (c <= A[n-1])
		{
			vector<int> vec(2, 0);
			vec[0] = a; vec[1] = b;
			if (M.count(vec))
				return cnt + M[vec];
			 if (!S.count(c)) //没找到
				break;
		 	 else //找到
			 {
				if (first) 
                {
                    cnt = 3;
                    first = false;
                }
				else cnt++;
				M[vec] = cnt;
				a = b;
				b = c;
				c = a + b;
			 }
		}
		return cnt;
	}
    int lenLongestFibSubseq(vector<int>& A) {
		map<vector<int>, int> m;
		int max_f = 0;
		int n = A.size();
		set<int> s;
		for (int i = 0; i < n; i++)
			s.insert(A[i]);
		for (int i = 0; i < n -2; i++)
		{
			for (int j = i+1; j < n -1; j++)
			{
				if (A[i] + A[j] > A[n-1]) continue;
				int temp = cal(A, s, m, A[i], A[j]);
				max_f = max(temp, max_f);
			}
		}
		return max_f;
    }
};
int main()
{}
