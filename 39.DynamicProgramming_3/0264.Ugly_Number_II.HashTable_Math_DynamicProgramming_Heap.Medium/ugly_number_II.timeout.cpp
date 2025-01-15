/*******************************************************************************
 *      file name: ugly_number_II.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/04-18:07:58                              
 *  modified time: 2021/10/04-18:07:58                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        //vector<int> vec;
        int x = 1;
        int cnt = 0;
        while (cnt < n) {
            if (is_ugly(x)) cnt++;
            x++;
        }
        return x-1;
    }
    
    bool is_ugly(int n) {
        while (n % 2 == 0) {
            n /= 2;
        }
        
        while (n % 3 == 0) {
            n /= 3;
        }    
        while (n % 5 == 0) {
            n /= 5;
        }      
        if (n == 1) return true;
        return false;
    }
};
int main()
{}
