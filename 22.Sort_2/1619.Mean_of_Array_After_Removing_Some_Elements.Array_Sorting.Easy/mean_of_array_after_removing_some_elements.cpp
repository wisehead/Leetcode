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
        sort(arr.begin(), arr.end());
        int N = arr.size();
        int cnt = N /20;
        double sum = 0;
        for (int i = cnt; i < N-cnt; i++) sum += arr[i];
        double ret = sum/(N-2*cnt);
        return ret;
    }
};
int main()
{}
