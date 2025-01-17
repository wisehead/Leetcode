/*******************************************************************************
 *      file name: repeated_DNA_sequences.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/11-09:14:46                              
 *  modified time: 2021/10/11-09:14:46                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
/*
The main idea is to store the substring as int in map to bypass the memory limits.

There are only four possible character A, C, G, and T, but I want to use 3 bits per letter instead of 2.

Why? It's easier to code.

A is 0x41, C is 0x43, G is 0x47, T is 0x54. Still don't see it? Let me write it in octal.

A is 0101, C is 0103, G is 0107, T is 0124. The last digit in octal are different for all four letters. That's all we need!

We can simply use s[i] & 7 to get the last digit which are just the last 3 bits, it's much easier than lookup table or switch or a bunch of if and else, right?

We don't really need to generate the substring from the int. While counting the number of occurrences, we can push the substring into result as soon as the count becomes 2, so there won't be any duplicates in the result.

vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> r;
    int t = 0, i = 0, ss = s.size();
    while (i < 9)
        t = t << 3 | s[i++] & 7;
    while (i < ss)
        if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
            r.push_back(s.substr(i - 10, 10));
    return r;
}
BTW, the OJ doesn't seems to have test cases which the given string length is smaller than 9, so I didn't check it to make the code simpler.

Any suggestions?

Update:

I realised that I can use s[i] >> 1 & 3 to get 2 bits, but then I won't be able to remove the first loop as 1337c0d3r suggested.
*/
class Solution {
public:
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> r;
    int t = 0, i = 0, ss = s.size();
    while (i < 9)
        t = t << 3 | s[i++] & 7;
    while (i < ss) {
        long long int x = (long long int)t;
        t = x << 3 & 0x3FFFFFFF | s[i++] & 7;
        if (m[t]++ == 1)
            r.push_back(s.substr(i - 10, 10));
    }
    return r;
}
};
int main()
{}
