/*******************************************************************************
 *      file name: kth_smallest_element_in_a_sorted_matrix.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/31-12:06:51                              
 *  modified time: 2020/10/31-12:06:51                              
 *******************************************************************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    
  struct numCompare {
    bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
      return x.first > y.first;
    }
  };

   int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare> minHeap;

    // put the 1st element of each row in the min heap
    // we don't need to push more than 'k' elements in the heap
    for (int i = 0; i < n && i < k; i++) {
      minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
    }

    // take the smallest element form the min heap, if the running count is equal to k return the number
    // if the row of the top element has more elements, add the next element to the heap
    int numberCount = 0, result = 0;
    while (!minHeap.empty()) {
      auto heapTop = minHeap.top();
      minHeap.pop();
      result = heapTop.first;
      if (++numberCount == k) {
        break;
      }

      heapTop.second.second++;
      if (n > heapTop.second.second) {
        heapTop.first = matrix[heapTop.second.first][heapTop.second.second];
        minHeap.push(heapTop);
      }
    }
    return result;
  }    
};
int main()
{}
