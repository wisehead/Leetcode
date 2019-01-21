/*******************************************************************************
 *      file name: X_of_a_kind_in_a_deck_of_cards.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/21-15:14:07                              
 *  modified time: 2019/01/21-15:14:07                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        int res = 0;
        for (int i : deck) count[i]++;
        for (auto i : count) res = __gcd(i.second, res);
        return res > 1;
    }
};
int main()
{
	int arr[] = {1,2,3,4,4,3,2,1};
	vector<int> vec(arr, arr+8);
	Solution sol;
	bool ret = sol.hasGroupsSizeX(vec);
	cout<<"ret:"<<ret<<endl;
}
