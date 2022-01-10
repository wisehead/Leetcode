/*******************************************************************************
 *      file name: mean_of_array_after_removing_some_elements.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/10-11:30:18                              
 *  modified time: 2022/01/10-11:30:18                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double trimMean(vector<int>& arr) {
        auto sz = arr.size(), skip = sz / 20;
        nth_element(begin(arr), begin(arr) + skip, end(arr));
        nth_element(begin(arr) + skip, begin(arr) + sz - skip, end(arr));
        return (double)accumulate(begin(arr) + skip, begin(arr) + sz - skip, 0) / (sz - skip * 2);
    }
};
int main()
{}
