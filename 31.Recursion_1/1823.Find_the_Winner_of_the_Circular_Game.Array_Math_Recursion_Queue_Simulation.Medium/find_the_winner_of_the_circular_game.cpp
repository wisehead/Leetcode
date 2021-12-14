/*******************************************************************************
 *      file name: find_the_winner_of_the_circular_game.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/14-09:50:52                              
 *  modified time: 2021/12/14-09:50:52                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> vec(n,0);
        for (int i = 0; i < n; i++) vec[i] = i+1;
        return fun(vec, 0, k);
    }
    
    int fun(vector<int>& vec, int start, int k) {
        int N = vec.size();
        if (N == 1) return vec[0];
        int end = (start + k -1)%N;
        vec.erase(vec.begin()+end);
        return fun(vec, end, k);
    }
};
int main()
{}
