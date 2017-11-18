/*******************************************************************************
 *      file name: pascal_triangle_2.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/11/18-11:11                                    
 * modified time: 17/11/18-11:11                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec_ping;
        vector<int> vec_pong;
        if (rowIndex < 0)
            return vec_ping;
        vec_ping.push_back(1);
        if (rowIndex == 0)
            return vec_ping;

        int count = 0;
        while (count < rowIndex)
        {
            vec_pong.clear();
            for (int i = 0; i<=vec_ping.size(); i++)
            {
                if (i == 0 || i == vec_ping.size())
                    vec_pong.push_back(1);
                else
                    vec_pong.push_back(vec_ping[i] + vec_ping[i-1]);
            }
            vec_ping.clear();
            vec_ping.assign(vec_pong.begin(), vec_pong.end());
            count++;
        }
        return vec_ping;
    }
};
int main()
{}
