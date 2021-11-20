/*******************************************************************************
 *      file name: increasing_decreasing_string.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/31-10:32:24                              
 *  modified time: 2021/08/31-10:32:24                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string sortString(string s) {
        string res;
        int arr[26] = {0};
        int cnt = 0;
        for (auto e : s) {
            arr[e-'a']++;
            cnt++;
        }
        while (cnt) {
            for (int i = 0; i < 26; i++) {
                if (arr[i]) {
                    res.append(1,'a'+ i);
                    arr[i]--;
                    cnt--;
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (arr[i]) {
                    res.append(1,'a'+ i);
                    arr[i]--;
                    cnt--;
                }
            }            
        }
        return res;
    }
};
int main()
{}
