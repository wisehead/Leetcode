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
        int i = 0, cnt = 0;
        while (candies > cnt) {
            vec[i] += cnt+1;
            candies = candies - (cnt+1);
            cnt++;
            i = (i+1)%num_people;
        }
        if (candies > 0) vec[i] += candies;
        return vec;
    }
};
int main()
{}
