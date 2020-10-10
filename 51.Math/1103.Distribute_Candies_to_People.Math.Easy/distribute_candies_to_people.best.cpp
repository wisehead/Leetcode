/*******************************************************************************
 *      file name: distribute_candies_to_people.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/10-09:44:10                              
 *  modified time: 2020/10/10-09:44:10                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> vec(num_people, 0);
        int i = 0;
        while (candies > i) {
            vec[i%num_people] += i+1;
            candies -= (i+1);
            ++i;
        }
        vec[i%num_people] += candies;
        return vec;
    }
};
int main()
{}
