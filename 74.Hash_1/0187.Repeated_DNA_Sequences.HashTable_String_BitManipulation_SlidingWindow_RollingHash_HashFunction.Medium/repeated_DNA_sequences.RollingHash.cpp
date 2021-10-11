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
