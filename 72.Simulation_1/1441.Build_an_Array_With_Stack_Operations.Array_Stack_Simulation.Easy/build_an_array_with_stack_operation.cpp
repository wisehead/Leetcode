/*******************************************************************************
 *      file name: build_an_array_with_stack_operation.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/07/31-18:45:07                              
 *  modified time: 2021/07/31-18:45:07                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int j = 0;
        for (int i = 1; i <= n && j < target.size(); i++ ) {
            if (i == target[j]) {
                res.push_back("Push");
                j++;
            } else {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};
int main()
{}
