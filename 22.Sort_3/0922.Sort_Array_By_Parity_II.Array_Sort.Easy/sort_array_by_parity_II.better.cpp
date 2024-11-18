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
		int even = 0, odd = 1;
		for (int i =0; i < size; i++)
		{
			if (A[i] % 2 == 0) 
			{
                if (i % 2 == 0)
                    continue;
                while (A[even] % 2 == 0)
                    even += 2;
				swap(A[even], A[i]);
				even += 2;
			}
			else
			{
                if (i % 2 == 1)
                    continue;
                while (A[odd] % 2 == 1)
                    odd += 2;
			    swap(A[odd], A[i]);
                odd += 2;           
			}
            /*
            cout<<i;
            for (int j = 0; j < size; j++)
                cout<<"  A["<<j<<"]"<<A[j]<<" ";       
            cout<<endl;
            */
		}
		return A;
    }
};
int main()
{}
