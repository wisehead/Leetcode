/*******************************************************************************
 *      file name: partition_array_into_three_parts_with_euqal_sum.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/14-15:58:33                              
 *  modified time: 2019/07/14-15:58:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
bool canThreePartsEqualSum(vector<int>& A, int parts = 0) {
  auto total = accumulate(begin(A), end(A), 0);
  if (total % 3 != 0) return false;
  for (auto i = 0, sum = 0; i < A.size() && parts < 3; ++i) {
    sum += A[i];
    if (sum == total / 3) ++parts, sum = 0;
  }
  return parts == 3;
}
};int main()
{}
