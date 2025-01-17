/*******************************************************************************
 *      file name: convert_1D_array_into_2D_array.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/25- 9:09                                    
 * modified time: 24/09/25- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    static vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        const int sz=original.size();
        if (sz!=m*n) return {};
        vector<vector<int>> ans(m);
        for(int i=0; i<m; i++){
            ans[i].assign(original.begin()+i*n, original.begin()+(i+1)*n);
        }
        return ans;
    }
};



auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
