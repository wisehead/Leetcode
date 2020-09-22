/*******************************************************************************
 *      file name: happy_num.cpp                                               
 *         author: Hui Chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/12/12-12:12                                    
 *  modified time: 17/12/12-12:12                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
		if (n <= 0)
			return false;
		vector<int> vec;
		set<int> myset;
		int temp = n;
		uint64_t sum = n;
		int count = 0;
		while (sum != 1 && count < 10000)
		{
			//min:-2147483648  max:2147483647
	 		vec.clear();
		    temp = sum;
			set<int>::iterator iter;
			if((iter = myset.find(temp)) != myset.end())
			{
				break;
			}
			myset.insert(temp);
			for (uint64_t base=10; temp > 0; )
			{
				int x = temp % base; 
				vec.push_back(x);
				temp = temp/base;
				cout<<"x is:	"<<x<<";temp is:	"<<temp<<endl;
			}
			vector<int>::iterator it;
			sum = 0;
			for (it = vec.begin(); it != vec.end(); it++)
			{
				sum += (*it)*(*it); 
			}
			cout<<"sum is:	"<<sum<<endl;
			count++;
		}
		if (sum == 1)
			return true;
		else
			return false;
    }
};

int main()
{
	Solution sol;
	sol.isHappy(11);
}
