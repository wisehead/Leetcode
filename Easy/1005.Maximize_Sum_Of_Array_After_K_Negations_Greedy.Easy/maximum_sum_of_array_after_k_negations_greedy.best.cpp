/*******************************************************************************
 *      file name: maximum_sum_of_array_after_k_negations_greedy.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/15-15:00:46                              
 *  modified time: 2020/09/15-15:00:46                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
Explanation
@codePower:
In case someone needs an explanation:
1- sort the numbers in ascending order
2- flip all the negative numbers, as long as k > 0
3- find the sum of the new array (with flipped numbers if any) and keep track of the minimum number
4- Now for the return statement

res is the total sum of the new array
K % 2 check if the remaining K is odd.

Because if it's even, it will have no effect
(we will flip a number and then get it back to the original)

If it's odd,
flip the minimum number and remove twice its value from the result
(twice because we already added it as positive in our sum operation)


Complexity
Time O(NlogN) for sorting.
Space O(1) extra space, in-place sort

Time can be easily improved to O(N),
by quick selecting the kth negative.
 */

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        for (int i = 0; K > 0 && i < A.size() && A[i] < 0; ++i, --K)
            A[i] = -A[i];
        return accumulate(A.begin(), A.end(), 0) - (K%2) * *min_element(A.begin(), A.end()) * 2;
    }
};

int main()
{}
