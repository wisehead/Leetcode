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
One obvious way to do this is to use a hash table mapping strings to counts. (e.g. H["AAAAAAAAAA"] represents the number of times we have seen AAAAAAAAAA. This will work in O(n) time, but its useful to discuss why this is not a good solution:

Runtime constant (from hashing): When using a hash table, there is a runtime hit for hashing the string. In this case, converting the string to a table index. That will presumably mean looking at each character of the string. Since each character is part of 10 different substrings (other than the end characters), that means 10n character reads. Still linear, but we can do better on the constant.
Memory (values): There isn't any reason to store a count. Each possible string has only 3 states we need to track: "never been seen", "been seen once", and "been seen more than once". This requires only two bits to track -- not the 4-8 bytes needed for aninteger.
Memory (keys): A hash table needs to store each key (to resolve collisions). At 10 bytes per key, thats 10*n bytes -- a potential problem if n is every large, and completely unnecessary.
Here is how we address the three problems:

Hashing: We compute the hash ourselves, but take advantage of the overlapping. We treat each letter as a two-bit number. (Arbitrarily, A=0, C=1, G=2, T=3.) We treat ten consecutive letters as a 20-bit integer. We can calculate the first one with:

    int val = 0;
    for (int i=0; i < 10; i++)
        val = (val << 2) | char2val(s[i]);
Now, to compute the next string:

   val = ((val << 2) & mask) | char2val(s[10]);
Where:

mask: 20 consecutive bits ((1 << 21) -1).
((val << 2) & mask: shift everything over two bits, and get rid of the most significant bits.
((val << 2) & mask) | char2val(s[10]): Replace the right-most two bits with the character code.
Much faster than looking at every character 10 times.

Hash table: We instead use two bit-sets. There are 2^{21}-1 possible strings. We need a bit in each set for each possible string. The first set (S1) tells us if the string has been seen once or not. The second set (S2) tell us whether the string has been seen more than once.
*/
class Solution {
public:
vector<string> findRepeatedDnaSequences(string s) {
    if (s.size() <= 10)
        return vector<string>();
        
    vector<string> R;
    bitset<1<<20> S1;
    bitset<1<<20> S2;
    
    int val = 0;
    for (int i=0; i < 10; i++)   // Calc. the has value for the first string.
        val = (val << 2) | char2val(s[i]);
    S1.set(val);
    
    int mask = (1 << 20) - 1;
    for (int i=10; i < s.size(); i++) {
        // Calc the hash value for the string ending at position i.
        val = ((val << 2) & mask) | char2val(s[i]);  
        if (S2[val])
            continue;
        if (S1[val]) {
            R.push_back(s.substr(i-10+1, 10));
            S2.set(val);
        }
        else
            S1.set(val);
    }
    return R;
}

int char2val(char c) {
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
    }
    return 0;
 }
};
int main()
{}
