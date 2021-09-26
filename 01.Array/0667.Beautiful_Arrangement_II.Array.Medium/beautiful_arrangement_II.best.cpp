/*******************************************************************************
 *      file name: beautiful_arrangement_II.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/29-21:49:30                              
 *  modified time: 2019/04/29-21:49:30                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
/*
	if you have n number, the maximum k can be n - 1;
if n is 9, max k is 8.
This can be done by picking numbers interleavingly from head and tail,

// start from i = 1, j = n;
// i++, j--, i++, j--, i++, j--

i: 1   2   3   4   5
j:   9   8   7   6
out: 1 9 2 8 3 7 4 6 5
dif:  8 7 6 5 4 3 2 1
Above is a case where k is exactly n - 1
When k is less than that, simply lay out the rest (i, j) in incremental
order(all diff is 1). Say if k is 5:

     i++ j-- i++ j--  i++ i++ i++ ...
out: 1   9   2   8    3   4   5   6   7
dif:   8   7   6   5    1   1   1   1 
*/
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for (int i = 1, j = n; i <= j; ) {
            if (k > 1) {
                res.push_back(k-- % 2 ? i++ : j--);
            }
            else {
                res.push_back(i++);
            }
        }

        return res;
    }
};
int main()
{}
