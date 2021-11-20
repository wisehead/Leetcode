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
/*
Instead of checking whether the rectangles overlap, I max right with left (and top with bottom). Haven't seen that in other solutions.
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E), right = max(min(C,G), left);
        int bottom = max(B,F), top = max(min(D,H), bottom);
        return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
    }
};

int main()
{}
