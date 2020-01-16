/*******************************************************************************
 *      file name: element_appearing_more_than_25%_in_sorted_array.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/16-20:26:20                              
 *  modified time: 2020/01/16-20:26:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
		int n = arr.size();
		int cnt = 1;
		int limit = n / 4;
        if (n == 1) return arr[0];
		for(int i = 0; i < n-1; i++)
		{
			if (arr[i+1] == arr[i])
                if (++cnt > limit) return arr[i];
			else
				cnt = 1;
            
		}
		return 0;
    }
};
int main()
{}
