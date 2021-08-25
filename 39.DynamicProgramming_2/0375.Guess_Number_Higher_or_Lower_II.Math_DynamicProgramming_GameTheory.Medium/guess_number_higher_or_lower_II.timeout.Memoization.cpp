/*******************************************************************************
 *      file name: guess_number_higher_or_lower_II.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/25-11:17:35                              
 *  modified time: 2021/08/25-11:17:35                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int bt(int start, int end) {
        if (start>=end) return 0;
        vector<int> v;
        v.push_back(start);
        v.push_back(end);
        if (mp.count(v)) return mp[v];
        int ret = INT_MAX;
        int cost = 0;
        for (int i = start; i <= end; i++) {//guess i
            int max1 = INT_MIN;
            for (int j = start; j <= end; j++) {//target j
                if (j==i) 
                    cost = 0;//hit, do nothing
                if (j > i) {// target is bigger than guess
                    cost = i+bt(i+1,end);
                } else if (j < i) {
                    cost = i + bt(start, i-1);
                }
                //cout<<"start:"<<start<<",end:"<<end<<",cost:"<<cost<<endl;
                if (cost>max1) max1=cost;
            }
            if (max1 < ret) ret = max1;
        }
        mp[v] = ret;
        return ret;
    }    
    int getMoneyAmount(int n) {
        return bt(1,n);
    }
private:
    map<vector<int>, int> mp;
};
int main()
{}
