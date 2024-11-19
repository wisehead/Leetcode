/*******************************************************************************
 *      file name: largest_substring_between_two_equal_characters.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/12-07:24:40                              
 *  modified time: 2022/01/12-07:24:40                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> start(27,-1);
        vector<int> end(27,-1);
        int N = s.length();
        for (int i = 0; i < N; i++) {
            int index = s[i] - 'a';
            if (start[index] == -1) start[index] = i;
            else end[index] = i;
        }
        
        int ret = -1;
        for (int i = 0; i < 27; i++) {
            if (start[i] != -1 && end[i] != -1) {
                int tmp = end[i] - start[i] - 1;
                if (tmp > ret) ret = tmp;
            }
        }
        return ret;
    }
};
int main()
{}
