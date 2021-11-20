/*******************************************************************************
 *      file name: sort_array_by_parity_II.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/23-14:03:53                              
 *  modified time: 2019/01/23-14:03:53                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
		int size = A.size();
        vector<int> B(A.begin(), A.end());
		int even = 0, odd = 1;
		for (int i =0; i < size; i++)
		{
			if (A[i] % 2 == 0) 
			{
				//swap(A[even], A[i]);
                B[even] = A[i];
				even += 2;
			}
			else
			{
				//swap(A[odd], A[i]);
				B[odd] = A[i];
                odd += 2;           
			}
            /*
            cout<<i;
            for (int j = 0; j < size; j++)
                cout<<"  B["<<j<<"]"<<B[j]<<" ";       
            cout<<endl;
            */
		}
		return B;
    }
};
int main()
{}
