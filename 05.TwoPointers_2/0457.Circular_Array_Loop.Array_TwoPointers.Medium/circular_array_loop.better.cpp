/*******************************************************************************
 *      file name: circular_array_loop.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/22-09:55:42                              
 *  modified time: 2019/04/22-09:55:42                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        set<int> ss;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!ss.count(i))
            {
                map<int, int> mm;
                if (cal(nums, i, mm)) return true; 
                map<int,int>::iterator it;
                for (it = mm.begin(); it != mm.end(); it++)
                    ss.insert(it->first);
            }
        }
        return false;
    }
    bool cal(vector<int>& nums, int start, map<int, int>& mm) {
        vector<int> trace;
        int n = nums.size();
        if (!n) return false;
        int i = start, moves = 0;
        mm[i] = moves; 
        while (1)
        {
            int steps = nums[i];
            trace.push_back(steps);
            if (steps < 0)
            {
                int x = (-steps)/n;
                i += n*x;
            }
            
            i = (i + steps + n)%n;
            moves++;

            if (mm.count(i))
            {
                int x = moves - mm[i];
                if (x > 1)
                {
                    while(x > 1)
                    {
                        if (trace[moves-x]*trace[moves-x+1] < 0)
                            return false;
                        x--;
                    }
                    return true;
                }
                else 
                    break;
            }
            mm[i] = moves;
        }
        return false;
    }
};
int main()
{}
