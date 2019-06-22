/*******************************************************************************
 *      file name: rle_iterator.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/06/22-08:48:04                              
 *  modified time: 2019/06/22-08:48:04                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
		vec.assign(A.begin(), A.end());
    }
    
	void printv()
	{
		for (auto e: vec)
			cout<<" "<<e;
		cout<<endl;
	}
    int next(int n) {
		int ret = -1;
		for (int i = 0; i < vec.size(); i += 2)
		{
			int cnt = vec[i];
			if (cnt <= n)
			{
				n -= cnt;
				if (n == 0 || i == vec.size() - 2) 
				{
                    if (n==0)
    					ret = vec[i+1];
					vec.erase(vec.begin(), vec.begin() + i + 2);
					break;
				}
			}
			else// cnt > n
			{
				vec[i] -= n;
				ret = vec[i+1];
				vec.erase(vec.begin(), vec.begin() + i);
				break;
			}
		}
		//printv();
		return ret;
    }
private:
	vector<int> vec;
};


/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
int main()
{}
