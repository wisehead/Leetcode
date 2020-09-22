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
        if (rowIndex < 0)
            return vec_ping;
        vec_ping.push_back(1);
        if (rowIndex == 0)
            return vec_ping;

        int count = 0;
        while (count < rowIndex)
        {
            for (int i = vec_ping.size(); i>=0; i--)
            {
                if (i == vec_ping.size())
                    vec_ping.push_back(1);
				else if (i== 0)
				{
					//do nothing
				}
                else
					vec_ping[i] = vec_ping[i] + vec_ping[i-1];
            }
            count++;
        }
        return vec_ping;
    }
};
int main()
{}
