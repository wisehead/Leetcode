/*******************************************************************************
 *      file name: make_two_arrays_equal_by_reversing_sub_arrays.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/21-09:11:29                              
 *  modified time: 2021/11/21-09:11:29                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_multiset<int> m1(target.begin(), target.end());
        unordered_multiset<int> m2(arr.begin(), arr.end());
        return m1 == m2;
    }
};
int main()
{}
