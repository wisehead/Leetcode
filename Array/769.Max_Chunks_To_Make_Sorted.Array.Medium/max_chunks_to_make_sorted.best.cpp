/*******************************************************************************
 *      file name: max_chunks_to_make_sorted.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/22-09:44:01                              
 *  modified time: 2019/05/22-09:44:01                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        for (int i = 0, maxn = 0; i < arr.size(); i++) {
            maxn = max(arr[i], maxn);
            if (maxn == i) ans++;
        }
        return ans;
    }
};
int main()
{}
