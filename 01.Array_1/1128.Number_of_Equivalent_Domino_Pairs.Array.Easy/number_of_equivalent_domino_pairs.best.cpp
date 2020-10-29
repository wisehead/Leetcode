/*******************************************************************************
 *      file name: number_of_equivalent_domino_pairs.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/18-11:42:50                              
 *  modified time: 2020/01/18-11:42:50                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Intuition
Just count the number of different dominoes.


Explanation
You need to distinguish the different dominoes and count the same.

I did it in this way:
f(domino) = min(d[0], d[1]) * 10 + max(d[0], d[1])
For each domino d, calculate min(d[0], d[1]) * 10 + max(d[0], d[1])
This will put the smaller number on the left and bigger one on the right (in decimal).
So same number same domino, different number different domino.

Take the example from the problem:
dominoes = [[1,2],[2,1],[3,4],[5,6]]
now we transform it into [12,12,34,56].

@sendAsync also suggest other intersting ways to do that:

Use the product of primes
primes = [2,3,5,7,11,13,17,19,23,29]
f(domino) = primes[d[0]] * primes[d[1]]
(though primes[0] is not used)

Use the bit manipulation.
primes = [2,3,5,7,11,13,17,19,23,29]
f(domino) = 1 << d[0]| 1 << d[1];

Personaly I like the second more.


Complexity
Time O(N)
Space O(N)


Solution 1
We sum up the pair in the end after the loop,
using the guass formula sum = v * (v + 1) / 2,
where v is the number of count.

Solution 2
We sum up the pairs right away during the loop.
count[domino] is the number of same dominoes that we have seen.
 */
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int res = 0;
        for (auto& d : dominoes) {
            res += count[min(d[0], d[1]) * 10 + max(d[0], d[1])]++;
        }
        return res;
    }
};
int main()
{}
