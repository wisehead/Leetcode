/*******************************************************************************
 *      file name: jump_game.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/11-11:25:20                              
 *  modified time: 2019/03/11-11:25:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool f(vector<int>& nums, int n, map<int,int>& mymap) {
        //cout<<"enter:"<<n<<endl;
        bool ret = false;
        if (mymap.count(n)) return mymap[n];
        if (n == 0)
        {       
            if ( (nums.size() == 1) || (n == 0 && nums[0] > 0)) 
            {
                //cout<<"exit:"<<n<<endl;
                mymap[n] = 1;
                return true;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            //cout<<"i:"<<i<<"nums["<<n-i<<"]"<<nums[n-i]<<endl;
            if (nums[n-i] >= i) 
                ret = f(nums, n-i, mymap);
            if (ret)
            {
                mymap[n] = 1;
                return true;
                //cout<<"exit:"<<n<<endl;
            }
        }
        //cout<<"exit:"<<n<<endl;
        mymap[n] = 0;
        return ret;
    }
    bool canJump(vector<int>& nums) {
        map<int,int> mymap;
        return f(nums, nums.size()-1, mymap);
    }
};
int main()
{}
