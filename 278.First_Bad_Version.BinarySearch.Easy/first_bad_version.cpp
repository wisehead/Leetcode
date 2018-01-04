/*******************************************************************************
 *      file name: first_bad_version.cpp                                               
 *         author: Hui Chen. (c) 18                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 18/01/04- 1:01                                    
 *  modified time: 18/01/04- 1:01                                    
 *******************************************************************************/
#include <iostream>
using namespace std;
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
		unsigned int left = 1, right = n, mid= (left + right)/2;
		while(left<right){
			mid = (left + right)/2;
            cout<<"mid is:"<<mid<<endl;
			if(isBadVersion(mid)) 
            {
                right = mid;   
                cout<<"right is:"<<right<<endl;
            }
			else
            {
                left = mid+1;
                cout<<"left is:"<<left<<endl;
            }
		}
		return left;
    }
};
int main()
{}
