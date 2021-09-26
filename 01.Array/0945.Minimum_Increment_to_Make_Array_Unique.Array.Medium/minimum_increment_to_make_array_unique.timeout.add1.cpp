/*******************************************************************************
 *      file name: minimum_increment_to_make_array_unique.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/02-19:07:36                              
 *  modified time: 2019/07/02-19:07:36                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void printv(vector<int> & vec) {
        for (auto e: vec)
            cout<<" "<<e;
        cout<<endl;
    }
    int minIncrementForUnique(vector<int>& A) {
		int n = A.size();
		int steps = 0;
		sort(A.begin(), A.end());
		int i = 0;
		while (i < n - 1)
		{
			int guard = A[i];
            int index = i;
			while (i < n - 1 && A[i+1] == guard)
			{
				steps++;
				A[i+1]++;
				i++;
			}
            i = index + 1;
		}
		return steps;
    }
};
int main()
{}
