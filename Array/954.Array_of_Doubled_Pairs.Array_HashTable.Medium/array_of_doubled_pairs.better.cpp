/*******************************************************************************
 *      file name: array_of_doubled_pairs.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/06-21:40:22                              
 *  modified time: 2019/07/06-21:40:22                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;
/*
Intuition
Let's see a simple case
Assume all interger are positive, for example [2,4,4,8].
We have one x = 2, we need to match it with one 2x = 4.
Then one 4 is gone, we have the other x = 4.
We need to match it with one 2x = 8.
Finaly no number left.

Why we start from 2?
Because it's the smallest and we no there is no x/2 left.
So we know we need to find 2x

What if the case negative?
One way is that start from the biggest (with abosolute value smallest),
and we aplly same logic.

Another way is that start from the smallest (with abosolute value biggest),
and we try to find x/2 each turn.


Explanation
Count all numbers.
Loop all numbers on the order of its absolute.
We have counter[x] of x, so we need the same amount of 2x wo match them.
If c[x] > c[2 * x], then we return false
If c[x] <= c[2 * x], then we do c[2 * x] -= c[x] to remove matched 2x.
Don't worry about 0, it doesn't fit the logic above but it won't break our algorithme.

In case count[0] is odd, it won't get matched in the end.
(Anyway you can return false earlier here)

In case count[0] is even, we still have c[0] <= c[2 * 0].
And we still need to check all other numbers.
 */
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> c;
        for (int a : A) c[a]++;
        vector<int> keys;
        for (auto it : c)
            keys.push_back(it.first);
        sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        for (int x : keys) {
            if (c[x] > c[2 * x])
                return false;
            c[2 * x] -= c[x];
        }
        return true;
    }
};
int main()
{}
