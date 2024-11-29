/*******************************************************************************
 *      file name: shuffle_string.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/01-09:37:18                              
 *  modified time: 2021/12/01-09:37:18                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int N = indices.size();
        char vec[N+1];
        vec[N] = 0;
        for (int i = 0; i < N; i++) {
            int index = indices[i];
            vec[index] = s[i];
        }
        return string(vec);
    }
};
int main()
{}
