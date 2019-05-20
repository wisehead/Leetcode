/*******************************************************************************
 *      file name: mycalendar_I.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/20-09:53:04                              
 *  modified time: 2019/05/20-09:53:04                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Solution 1: Check every existed book for overlap
overlap of 2 interval a b is (max(a0, b0), min(a1, b1))
detail is in: https://discuss.leetcode.com/topic/111198
 */
class MyCalendar {
    vector<pair<int, int>> books;
public:    
    bool book(int start, int end) {
        for (pair<int, int> p : books)
            if (max(p.first, start) < min(end, p.second)) return false;
        books.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
int main()
{}
