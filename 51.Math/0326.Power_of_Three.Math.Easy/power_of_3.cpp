/*******************************************************************************
 *      file name: power_of_3.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/06- 1:01                                    
 *  modified time: 18/01/06- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
		int array[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
		set<int> s;
		s.insert(array, array+20);
		set<int>::iterator it;
		it = s.find(n);
		return !(it == s.end());
    }
};
int main()
{
	Solution sol;
	int n = 0;
	bool ret = false;
	for (; n< 100; n++)
	{
		ret = sol.isPowerOfThree(n);
		cout<<"ret for "<<n<<" is:"<<ret<<endl;
	}
}
