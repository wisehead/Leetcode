/*******************************************************************************
 *      file name: elimination_game.best.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/21-11:11                                    
 * modified time: 24/11/21-11:11                                    
 *******************************************************************************/
#include <iostream>
/*
The last element remaining in the array after performing these eliminations is the required answer.

Some Observations
After, the first iteration, all odd elements are removed.
1 2 3 4 5 6 => 2 4 6
Left to right elimination of elements n, n-1, ... 1 is same as right to left elimination of 1, 2, ... n.
l to r : 6 5 4 3 2 1 => 5 3 1
r to l : 1 2 3 4 5 6 => 1 3 5
Approach
let f(n, left) be a function for left to right elimination
let f(n, right) be a function for right to left elimination

These eliminations are done alternately starting with left to right elimination.

After the first iteration, all odd elements are removed and only even elements remain which can be written as 2 * array conataining elements 1 to n/2.

 1 2 3 4 5 6 => 2 4 6 = 2 * (1 2 3)
Example:

for n = 6,
arr = 1 2 3 4 5 6
after first elimination,
arr = 2 4 6 = 2*(1 2 3)
Therefore,
f(6, left) = 2 * f(3, right)
So, f(n, left) = 2 * f(n/2, right)

Then, Second iteration (right to left elimination) is done on elements 2 * (1, 2, ... n/2)

So, f(n, left) = 2 * f(n/2, right)

let f((1,2,...,n), left) = f((n), left) = k
now replace each value 1, 2, ... with (n + 1 - oldValue)

f((n, n-1, ..., 1), left) = n+1 - k
f(n, right) = n + 1 - f(n, left) (from second observation)
f(n, left) + f(n, right) = n+1
Using the above equations,

f(n, left) = 2 * f(n/2, right)
f(n, left) = 2 * (n/2 + 1 - f(n/2, left))
So, we can compute the result recursively using the above equation
*/
class Solution {
public:
    int lastRemaining(int n) {
        if (n ==1) return 1;
        return 2* (n/2 + 1 -lastRemaining(n/2));
    }
};
