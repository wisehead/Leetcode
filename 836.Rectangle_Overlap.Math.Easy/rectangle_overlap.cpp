/*******************************************************************************
 *      file name: rectangle_overlap.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/10-15:11:03                              
 *  modified time: 2018/11/10-15:11:03                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool is_overlap(int rec1_start, int rec1_end, int rec2_start, int rec2_end) {
		return ((rec2_start > rec1_start && rec2_start < rec1_end) 
                || (rec2_end > rec1_start && rec2_end < rec1_end)
                || (rec1_start > rec2_start && rec1_start < rec2_end)
                || (rec1_end > rec2_start && rec1_end < rec2_end)
               );
	}
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		return (is_overlap(rec1[0], rec1[2], rec2[0], rec2[2]) && is_overlap(rec1[1], rec1[3], rec2[1], rec2[3]));
    }
};
int main()
{}
