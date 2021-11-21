/*******************************************************************************
 *      file name: make_two_arrays_equal_by_reversing_sub_arrays.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/21-09:11:29                              
 *  modified time: 2021/11/21-09:11:29                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
            if (target[i] != arr[i]) return false;
        return true;
    }
};
int main()
{}
