/*******************************************************************************
 *      file name: cells_with_odd_values_in_a_matrix.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/26-10:04:13                              
 *  modified time: 2020/11/26-10:04:13                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
/*
This can be done in O(m+n) time and O(m+n) space
Firstly notice that the order in which we add 1 does not matter. You could add 1 to all rows and then proceed to adding 1 to all columns.

Now suppose you add 1 to the same row twice, the resultant elements in that row are even. So applying the operation to the same row/col is as good as not applying anything there.

Applying operation to a same row/col any odd number of times is as good as applying the operation only once.

So now suppose there are r such rows where you apply the operation odd number of times. And c such cols where you apply operation odd number of times.

Then

All m elements in each row are odd => r*m
All n elements in each row are odd => c*n
You double count r*c elements => -1 * r * c
Also, these r*c elements are even => -1 * r * c
So total odd elements is r*m + c*n - 2*r*c
 */
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<bool> N(n, false);
        vector<bool> M(m, false);
        
        for(int i=0; i<indices.size(); i++) {
            N[indices[i][0]] = N[indices[i][0]]^true;
            M[indices[i][1]] = M[indices[i][1]]^true;
        }
        
        int r = 0;
        int c = 0;
        
        for(int i=0; i<n; i++) {
            if(N[i])
                r++;
        }
        
        for(int j=0; j<m; j++) {
            if(M[j])
                c++;
        }
        
        return  r*m + c*n - 2*r*c;
    }
};
int main()
{}
