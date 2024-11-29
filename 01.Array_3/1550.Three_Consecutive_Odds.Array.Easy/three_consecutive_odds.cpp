/*******************************************************************************
 *      file name: three_consecutive_odds.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/05-20:05:42                              
 *  modified time: 2021/12/05-20:05:42                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int N = arr.size();
        for(int i = 0; i < N-2; i++) {
            if (arr[i]%2 && arr[i+1]%2 && arr[i+2]%2) return true;
        } 
        return false;
    }
};
int main()
{}
