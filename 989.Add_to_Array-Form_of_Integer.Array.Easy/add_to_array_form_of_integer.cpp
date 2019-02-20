/*******************************************************************************
 *      file name: add_to_array_form_of_integer.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/20-09:31:53                              
 *  modified time: 2019/02/20-09:31:53                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
		int i = 0;
		int size = A.size();
		reverse(A.begin(), A.end());
		bool carry = false;
		while (K > 0 || carry)
		{
			int tmp = K % 10;
			if (carry) tmp++;
			carry = false;
			if (i < size)
			{
                
				A[i] += tmp;
				if (A[i] > 9) 
				{
					A[i] -= 10;
					carry = true;
				}
			}
			else
			{
				if (tmp > 9) 
				{
					tmp -= 10;
					carry = true;
				}
				A.insert(A.end(), tmp);
			}
            K /= 10;
            i++;
		}
        reverse(A.begin(), A.end());
		return A;
    }
};
int main()
{}
