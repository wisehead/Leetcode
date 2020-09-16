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
#include <map>
using namespace std;
/*
Solution 2: Keep existing books sorted and only check 2 books start right before & after the new book starts
Another way to check overlap of 2 intervals is a started with b, or, b started within a.

Keep the intervals sorted,
if the interval started right before the new interval contains the start, or
if the interval started right after the new interval started within the new interval.

   floor      ceiling
... |----| ... |----| ...
       |---------|
      s         e
if s < floor.end or e > ceiling.start, there is an overlap.

Another way to think of it:
If there is an interval start within the new book (must be the ceilingEntry) at all, or
books: |----|   |--|
            s |------| e

books: |----|   |----|
            s |----| e
If the new book start within an interval (must be the floorEntry) at all
books: |-------|   |--|
       s |---| e

books: |----|   |----|
        s |----| e
There is a overlap 
 */
class MyCalendar {
    map<int, int> books;
public:
    bool book(int s, int e) {
        auto next = books.lower_bound(s); // first element with key not go before k (i.e., either it is equivalent or goes after).
        if (next != books.end() && next->first < e) return false; // a existing book started within the new book (next)
        if (next != books.begin() && s < (--next)->second) return false; // new book started within a existing book (prev)
        books[s] = e;
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
