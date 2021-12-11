/*******************************************************************************
 *      file name: k-th_symbol_in_grammer.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/11-17:59:09                              
 *  modified time: 2021/12/11-17:59:09                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int get_n_bit(vector<char>& vec, int n, int k) {
        //cout<<"n:"<<n<<",k:"<<k<<endl;
        unsigned long long int masks[] = {1,2,4,8,16,32,64,128};
        int index = (k-1) / 8;
        k = k % 8;
        int offset = (n-k)%8;
        //cout<<"index:"<<index<<",offset:"<<offset<<endl;
        int v = vec[index];
        if (v & masks[offset]) return 1;
        return 0;
    }
    int kthGrammar(int n, int k) {
        vector<char> vec; 
        int N = 0;
            if (n == 1) {
                vec.push_back(0);
                N = 1;
            } else if (n == 2) {
                vec.push_back(1);
                N = 2;
            }
            else if (n==3) {
                vec.push_back(6);
                N = 4;
            }
            else {
                vec.push_back(105);
                N = 8;
            }
            
    
	    
	    for (int level = 5; level <= n; level++) {
		    vector<char> v2;
		    for (auto c : vec) {
			    char x = c ^ 0b11111111;
			    v2.push_back(x);
                
                if ((v2.size()+ vec.size())*8 >= k) {
                    vec.insert(vec.end(), v2.begin(), v2.end());
                    return get_n_bit(vec, N, k); 
                }
                
		    }
		    vec.insert(vec.end(), v2.begin(), v2.end());
            //if (vec.size() >= k) break;
	    }
        return get_n_bit(vec, N, k); 
    }
    
    //string f(string )
};
