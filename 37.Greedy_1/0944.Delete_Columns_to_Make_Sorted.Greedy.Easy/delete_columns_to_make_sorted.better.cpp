/*******************************************************************************
 *      file name: delete_columns_to_make_sorted.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/01-09:19:19                              
 *  modified time: 2019/02/01-09:19:19                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
		int count = 0;
		for (int i = 0; i < A[0].length(); i++)
		{
			for (int j = 0; j < A.size() - 1; j++)
			{
				if (A[j+1][i] < A[j][i])
				{
					count++;
					break;
				}
			}
		}
		return count;
    }
};
int main()
{}
