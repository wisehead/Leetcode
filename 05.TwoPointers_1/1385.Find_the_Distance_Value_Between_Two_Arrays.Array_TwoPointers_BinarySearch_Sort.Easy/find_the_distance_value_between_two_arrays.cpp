/*******************************************************************************
 *      file name: find_the_distance_value_between_two_arrays.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/06-10:18:46                              
 *  modified time: 2021/09/06-10:18:46                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for (auto e : arr1) {
            int i = 0;
            for (; i < arr2.size(); i++) {
                if (abs(e - arr2[i]) <= d) break;
            }
            if (i == arr2.size()) cnt++;
        }
        return cnt;
    }
};
int main()
{}
