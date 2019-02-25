/*******************************************************************************
 *      file name: 3sum.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/24-08:46:52                              
 *  modified time: 2019/02/24-08:46:52                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > res;
		std::sort(num.begin(), num.end());
		for (int i = 0; i < num.size(); i++) {
			int target = -num[i];
			int front = i + 1;
			int back = num.size() - 1;
			while (front < back) {
				int sum = num[front] + num[back];
				// Finding answer which start from number num[i]
				if (sum < target)
					front++;
				else if (sum > target)
					back--;
				else {
					vector<int> triplet(3, 0);
					triplet[0] = num[i];
					triplet[1] = num[front];
					triplet[2] = num[back];
					res.push_back(triplet);
					// Processing duplicates of Number 2
					// Rolling the front pointer to the next different number forwards
					while (front < back && num[front] == triplet[1]) front++;
					// Processing duplicates of Number 3
					// Rolling the back pointer to the next different number backwards
					while (front < back && num[back] == triplet[2]) back--;
				}
			}
			// Processing duplicates of Number 1
			while (i + 1 < num.size() && num[i + 1] == num[i]) 
				i++;
		}
		return res;
	}
};
int main()
{}
