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
		count = 0;
    }
    
    int ping(int t) {
		q1.push(t);
		while (!q1.empty() && (q1.front() < t - 3000))
			q1.pop();
		return q1.size();
    }
private:
	queue<int> q1;
	int count;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
int main()
{}
