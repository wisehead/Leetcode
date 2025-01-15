#include <vector>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(n+1,0);
        if (n == 0) return 0;
        nums[1] = 1;
        if (n == 1) return 1;
        int ret = 0;
        for (int i = 2; i <= n; i++) {
            if (i%2 == 0) nums[i] = nums[i/2];
            else nums[i] = nums[(i-1)/2] + nums[(i-1)/2 + 1];
            if (nums[i] > ret) ret = nums[i];
        }
        return ret;
    }
};

int main() {}