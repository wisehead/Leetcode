/*******************************************************************************
 *      file name: available_captures_for_rook.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/08-12:27:18                              
 *  modified time: 2019/07/08-12:27:18                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
Search for the rock. From the rock, trace empty spaces in four directions. Return 1 if we hit a pawn, zero otherwise.

Count and return captured pawns.
 */
class Solution {
public:
	int cap(vector<vector<char>>& b, int x, int y, int dx, int dy) {
	  while (x >= 0 && x < b.size() && y >= 0 && y < b[x].size() && b[x][y] != 'B') {
	    if (b[x][y] == 'p') return 1;
	    x += dx, y += dy;
	  }
	  return 0;
	}
	int numRookCaptures(vector<vector<char>>& b) {
	  for (auto i = 0; i < b.size(); ++i)
	    for (auto j = 0; j < b[i].size(); ++j)
	      if (b[i][j] == 'R') return cap(b,i,j,0,1)+cap(b,i,j,0,-1)+cap(b,i,j,1,0)+cap(b,i,j,-1,0);
	  return 0;
	}
};
int main()
{}
