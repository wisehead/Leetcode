/*******************************************************************************
 *      file name: crawler_log_folder.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/04-19:50:33                              
 *  modified time: 2022/01/04-19:50:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for (auto log : logs) {
            if (log == "./") {
                //
            } else if (log == "../") {
                if (cnt) --cnt;
            } else {
                ++cnt;
            }
        }
        return cnt;
    }
};
int main()
{}
