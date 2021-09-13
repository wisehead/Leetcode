/*******************************************************************************
 *      file name: find_lucky_integer_in_an_array.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/13-09:12:57                              
 *  modified time: 2021/09/13-09:12:57                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> vec(501,0);
        for (auto e: arr) {
            vec[e]++;
        }
        
        for (int i = 500; i > 0; i--) {
            if (vec[i] == i) return i;
        }
        return -1;
    }
};
int main()
{}
