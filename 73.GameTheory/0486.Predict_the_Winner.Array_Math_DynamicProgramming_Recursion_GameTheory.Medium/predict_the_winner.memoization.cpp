/*******************************************************************************
 *      file name: predict_the_winner.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/09/30-11:06:52                              
 *  modified time: 2021/09/30-11:06:52                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        bool ret = false;
        int sum = 0;
        for (auto e : nums) sum += e;
        int v1 = f(nums, 0, nums.size()-1);
        if (v1 >= sum - v1) ret = true;
        return ret;
    }

    int f(vector<int>& vec, int start, int end) {
        //cout<<"start:"<<start<<",end:"<<end<<endl;
        if (start > end) return 0;
        if (start == end) return vec[start];
        if (end - start == 1) return max(vec[start], vec[end]);

        vector<int> v;
        v.push_back(start);
        v.push_back(end);
        if (mp.count(v)) return mp[v];
        int v1 = min(vec[start] + f(vec, start+1, end-1), vec[start] + f(vec, start+2, end));
        int v2 = min(vec[end]+ f(vec, start, end -2), vec[end]+f(vec, start+1, end-1));
        //cout<<"v1:"<<v1<<",v2:"<<v2<<endl;
        int ret = max(v1, v2);
        mp[v] = ret;
        return ret;
    }

private:
    map<vector<int>, int> mp;
};
int main()
{}
