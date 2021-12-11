/*******************************************************************************
 *      file name: k-th_symbol_in_grammer.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/11-17:59:09                              
 *  modified time: 2021/12/11-17:59:09                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
Updates: (all index discussed below are 0-based)
Observation 1: N does not matter as long as "K will be an integer in the range [1, 2^(N-1)]". We can ignore N.

Observation 2: let f(k) be the value of kth position (0-based), then:
f(2 * k) = 0 {if f(k) = 0} or, 1 {if f(k) = 1} => f(2 * k) = f(k) xor 0
f(2 * k + 1) = 0 {if f(k) = 1} or 1 {if f(k) = 0} => f(2 * k + 1) = f(k) xor 1

Obervation 3: if binary string of k is used, let k = 1001010, then we have:
f(1001010) = f(100101) ^ 0 = f(10010) ^ 1 ^ 0 = f(1001) ^ 0 ^ 1 ^ 0 = ... = f(0) ^ 1 ^ 0 ^ 0 ^1 ^ 0 ^ 1 ^ 0 = 1 ^ 0 ^ 0 ^1 ^ 0 ^ 1 ^ 0
So, the result is the xor operation on all bits of k. Since 0 does not change xor result, we can ignore all 0s.
f(1001010) = 1 ^ 1 ^ 1 = (1^1) ^ 1 = 0 ^ 1 = 1
f(11110011) = 1 ^ 1^ 1 ^ 1 ^ 1 ^1 = (1 ^ 1) ^ (1 ^ 1) ^ (1 ^1) = 0
Now, it's easy to tell f(k) = 0 if k has even number of 1s in binary representation, and f(k) = 1 when k has odd number of 1s
*/
class Solution {
public:
    int kthGrammar(int N, int K) {
        int n;
        for (n = 0, K -= 1; K ; K &= (K - 1)) n++;
        return n & 1;
    }

    //string f(string )
};
