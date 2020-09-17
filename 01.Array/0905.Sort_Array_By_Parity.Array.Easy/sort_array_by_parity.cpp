/*******************************************************************************
 *      file name: sort_array_by_parity.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/17-10:53:23                              
 *  modified time: 2019/01/17-10:53:23                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
		vector<int> even;
		vector<int> odd;
		int size = A.size();
		for (int i=0; i<size; i++)
		{
			int temp = A[i];
			if (temp % 2 == 0)
				even.push_back(temp);
			else
				odd.push_back(temp);
		}
		even.insert(even.end(), odd.begin(), odd.end());
		return even;
    }
};
int main()
{}
