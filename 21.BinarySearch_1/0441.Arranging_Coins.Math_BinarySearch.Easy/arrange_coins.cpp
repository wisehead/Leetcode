/*******************************************************************************
 *      file name: arrange_coins.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/06/30- 6:06                                    
 *  modified time: 18/06/30- 6:06                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {
		//vector<int> vec;
		int remain = n;
		for (int i=1;i<=n;i++)
		{
			remain = remain - i;
            if (remain == 0)
                return i;
			if (remain < 0)
				return (i-1);
		}
		return n;
    }
};


int main()
{
	Solution sol;
	int ret = sol.arrangeCoins(2);
	cout<<"ret is:"<<ret<<endl;
}
