/*******************************************************************************
 *      file name: rotate_image.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/06-10:23:15                              
 *  modified time: 2019/03/06-10:23:15                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
    }
};

int main()
{}
