/*******************************************************************************
 *      file name: unique_paths.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/15-14:24:35                              
 *  modified time: 2019/03/15-14:24:35                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n == 1 || m == 1) return 1;
        vector<int> v(n);// = {1, 2, 3, 4};
        for(int i = 0; i < n; i++){
            v[i] = i + 1;
        }
        int j = 0;
        for(int i = 1; i < (m - 1) * (n - 1); i++){
            if((j + 1) % n == 0) {
                j = 0;
            }
            v[j + 1] += v[j];
            j++;
        }

        return v[n - 1];
    }
};
int main()
{}
