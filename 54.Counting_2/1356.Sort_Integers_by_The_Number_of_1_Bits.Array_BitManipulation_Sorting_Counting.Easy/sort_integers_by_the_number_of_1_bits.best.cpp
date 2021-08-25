/*******************************************************************************
 *      file name: sort_integers_by_the_number_of_1_bits.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/25-09:22:54                              
 *  modified time: 2021/08/25-09:22:54                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:

    static bool customCompare(const int& a, const int& b)
    {
        int x = bitset<32>(a).count();
        int y = bitset<32>(b).count();
        if(x != y)
            return x < y;
        return a < b;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(),customCompare);
        return arr;
    }
};
int main()
{}
