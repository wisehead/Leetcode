/*******************************************************************************
 *      file name: count_square_sum_triples.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/09/23- 9:09                                    
 * modified time: 24/09/23- 9:09                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int countTriples(int n) {
        int ret = 0;
        for (int k = 1; k <= n; k++) {
            ret += isSumOfTwoSquares(k*k);
            cout<<"ret:"<<ret<<endl;
        }
        cout<<"ret:"<<ret<<endl;
        return ret;
    }
    int isSumOfTwoSquares(int n) {
        int cnt = 0;
        for (int i = 1; i * i <= n; i++) {
            int j = std::sqrt(n - i * i);
            if (j * j + i * i == n) {
                cout<<"i:"<<i<<",j:"<<j<<",n:"<<n<<endl;
                if (j > 0)
                    cnt++;
            }
        }
        return cnt;
    }
};
