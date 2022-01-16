/*******************************************************************************
 *      file name: slowest_key.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/16-19:44:03                              
 *  modified time: 2022/01/16-19:44:03                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char res = keysPressed[0];
        int maxv = releaseTimes[0];
        int N = releaseTimes.size();
        for (int i = 1; i < N; i++) {
            int tmp = releaseTimes[i] - releaseTimes[i-1];
            if (tmp > maxv) { 
                maxv = tmp;
                res = keysPressed[i];
            } else if (tmp == maxv && keysPressed[i] > res) {
                res = keysPressed[i];
            }
        }
        return res;
    }
};
int main()
{}
