#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int N = code.size();
        vector<int> res(N, 0);
        if (k == 0) return res;
        if (k > 0) {
            for (int i = 0; i < N; i++) {
                for (int j = 1; j <= k; j++) {
                    res[i] += code[(i+j)%N];
                }
            }
            
        } else {
            for (int i = 0; i < N; i++) {
                for (int j = 1; j <= -k; j++) {
                    res[i] += code[(i-j+N)%N];
                    //cout<<"i:"<<i<<",j:"<<j<<", res[i]:"<<res[i]<<endl;
                }
            }
        }
        return res;
        
    }
};

int main(){}