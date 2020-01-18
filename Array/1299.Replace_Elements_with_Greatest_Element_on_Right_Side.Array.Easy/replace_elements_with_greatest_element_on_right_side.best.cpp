/*******************************************************************************
 *      file name: replace_elements_with_greatest_element_on_right_side.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/18-14:18:56                              
 *  modified time: 2020/01/18-14:18:56                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& A, int mx = -1) {
        for (int i = A.size() - 1; i >= 0; --i)
		{
            int temp = A[i];
            A[i] = mx;
            mx = max(mx, temp);
		}
        return A;
    }
};

int main()
{}
