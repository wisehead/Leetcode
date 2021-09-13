/*******************************************************************************
 *      file name: count_largest_group.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/13-09:43:04                              
 *  modified time: 2021/09/13-09:43:04                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int> mp;
        int maxc = 0;
        for (int i = 1; i <=n ;i++) {
            int temp = i;
            int sum = 0;
            while (temp) {
                
                sum += (temp%10);
                temp = temp / 10;
            }
            if (mp.count(sum)) ++mp[sum];
            else mp[sum] = 1;
            if (mp[sum] > maxc) maxc = mp[sum];
        }
        map<int,int>::iterator it;
        int cnt = 0;
        for (it = mp.begin(); it != mp.end(); it++) {
            if (it->second == maxc) cnt++;
        }
        return cnt;
    }
};
int main()
{}
