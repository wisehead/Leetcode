/*******************************************************************************
 *      file name: kids_with_the_greatest_number_of_candies.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/10/13-09:38:18                              
 *  modified time: 2021/10/13-09:38:18                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max1 = 0;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > max1) 
                max1 = candies[i];
        }
        vector<bool> res;
        for (auto e : candies) {
            if (e == max1) res.push_back(true);
            else 
                res.push_back( (bool)(e + extraCandies >= max1));
        }
        return res;
    }
};
int main()
{}
