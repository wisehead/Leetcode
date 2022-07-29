/*******************************************************************************
 *      file name: richest_customer_wealth.cpp                                               
 *         author: hui chen. (c) 22                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 22/07/29- 7:07                                    
 * modified time: 22/07/29- 7:07                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int> >& accounts) {
        int ret = 0;
        for (auto vec : accounts) {
            int sum = accumulate(vec.begin(),vec.end(),0);
            if (sum > ret) ret = sum;
        }
        return ret;
    }
};

int main() {}
