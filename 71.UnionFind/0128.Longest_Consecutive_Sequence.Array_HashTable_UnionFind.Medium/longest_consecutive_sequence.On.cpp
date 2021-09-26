/*******************************************************************************
 *      file name: longest_consecutive_sequence.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/10-19:48:28                              
 *  modified time: 2021/08/10-19:48:28                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.size() == 0) return 0;
        unordered_set<int> record(num.begin(),num.end());
        int res = 1;
        for(int n : num){
            if(record.find(n)==record.end()) continue;
            record.erase(n);
            int prev = n-1,next = n+1;
            while(record.find(prev)!=record.end()) record.erase(prev--);
            while(record.find(next)!=record.end()) record.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }
};
int main()
{}
