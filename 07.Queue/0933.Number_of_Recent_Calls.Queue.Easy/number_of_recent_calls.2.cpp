/*******************************************************************************
 *      file name: number_of_recent_calls.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/28-10:21:45                              
 *  modified time: 2019/01/28-10:21:45                              
 *******************************************************************************/
#include <iostream>
#include <queue>
using namespace std;
class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while (q.size() > 0 && (q.front() < t - 3000)) q.pop();
        return q.size();
    }
private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main()
{}
