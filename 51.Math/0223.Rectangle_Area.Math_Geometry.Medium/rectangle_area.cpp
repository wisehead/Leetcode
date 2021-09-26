/*******************************************************************************
 *      file name: rectangle_area.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/10-10:20:58                              
 *  modified time: 2021/08/10-10:20:58                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int sum = (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1);
        if(by1 >= ay2 || by2 <= ay1 || bx1 >= ax2 || bx2 <= ax1 ) return sum;
        vector<int> vx = {ax1, ax2, bx1,bx2};
        vector<int> vy = {ay1, ay2, by1, by2};
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());   
        return sum-(vx[2] - vx[1])*(vy[2] - vy[1]);
    }
};
int main()
{}
