/*******************************************************************************
 *      file name: find_kth_bit_in_nth_binary_string.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/13-10:04:12                              
 *  modified time: 2021/12/13-10:04:12                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int N(int n) {
        int cnt = 1;
        for (int i = 2; i <=n; i++ ) {
            cnt = 2*cnt+1;
        }
        return cnt;
    }
    
    char updown(char c) {
        if (c == '0') return '1';
        return '0';
    }
    char findKthBit(int n, int k) {
        if (n==1) return '0';
        int cnt = N(n);
        //cout<<"n:"<<n<<",k:"<<k<<",cnt:"<<cnt<<endl;
        if (k*2 < cnt+1) return findKthBit(n-1, k);
        if (k*2 == cnt+1) return '1';
        return updown(findKthBit(n-1, cnt-k+1));
    }
};
int main()
{}
