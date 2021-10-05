/*******************************************************************************
 *      file name: maximum_product_of_two_elements.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/04-07:36:13                              
 *  modified time: 2021/08/04-07:36:13                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for (auto e : nums) pq.push(e);
        int v1 = pq.top();
        pq.pop();
        int v2 = pq.top();
        return (v1-1)*(v2-1);
    }
};
int main()
{}
