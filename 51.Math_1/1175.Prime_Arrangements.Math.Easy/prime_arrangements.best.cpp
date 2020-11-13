/*******************************************************************************
 *      file name: prime_arrangements.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/13-16:29:11                              
 *  modified time: 2020/11/13-16:29:11                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
Algorithm is simple (Upvotes are appreciated):

Calculate how many numbers [1..n] are prime numbers
Since indexes are counted from 1 then all prime numbers are initially on their prime indexes.
Meaning, number of prime numbers == number of prime indexes.
Calculate how many not prime numbers: n - count_of_prime_numbers.
Result would be: permutations_of_all_prime_numbers_on_their_positions * permutations_of_all_not_prime_numbers_on_their_positions.
Formula for permutations count is simple, it's Factorial.
So if a is count of all prime numbers and b count of other numbers, then the result is:

return factorial(a) * factorial(b) % mod;
// by init conditions mod == 10^9 + 7  == 1000000007
The problem with the task is that max factorial we need to count is 75! and it's waaaaay bigger than ULONG_MAX. What to do?

Remember that (a * b) mod c is the same as ((a mod c) * (b mod c)) mod c ? (check out Properties of Modular Arithmetics)

We can use this rule to calculate Factorial: if value becomes bigger than 1000000007 we get the rest of devision on 1000000007.

That's it!

But if we want to achieve 0ms runtime than we need to think that we calculate Factorial for 2 numbers and most likely one number is less than another.
We can calculate Factorial for smaller number and then calculate Factorial for second one, but starting with already calculated previous value and not from 1 again.

Check out my code:
*/

class Solution {
    const long mod = 1000000007;
    long factorial(int n, int prime = 2, long start = 1) {
        long a = start;
        for (int i = prime; i <= n; i++) {
            a *= i;
            if (a >= mod) a %= mod;
        }
        return a;
    }
public:
    int numPrimeArrangements(int n) {
        int primes[] {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        int i = 0;
        for (; i < 25 && primes[i] <= n; i++);
        int minNum = i, rest = n - i;
        if (n < (i << 1)) swap(minNum, rest);
        
        long a = factorial(minNum), b = factorial(rest, minNum + 1, a);
        return (int)(a * b % mod);
    }
};

int main() {
	Solution sol;
	sol.numPrimeArrangements(5);
}

