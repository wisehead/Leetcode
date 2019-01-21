/*******************************************************************************
 *      file name: X_of_a_kind_in_a_deck_of_cards.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/21-15:14:07                              
 *  modified time: 2019/01/21-15:14:07                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
		map<int, int> mm;
		int size = deck.size();
		for (int i = 0; i < size; i++)
		{
			int x = deck[i];
			if (mm.count(x))
			{
				mm[x]++;
			}
			else
				mm[x] = 1;
		}
		int minv = 0;
		map<int, int>::iterator it = mm.begin();
		minv = it->second;
		for (; it != mm.end(); it++)
		{
			cout<<"it->second:"<<it->second<<endl;
			if(it->second < minv)
				minv = it->second;
		}
		cout<<"minv:"<<minv<<endl;

		for (int i = minv; i >=2; i--)
		{
			cout<<"i:"<<i<<endl;
			bool flag = false;
			for (it = mm.begin(); it != mm.end(); it++)
			{
				if(it->second % i != 0)
				{
					flag = true;
					break;
				}
			}
			if (!flag) 
				return true;
		}
		return false;
    }
};
int main()
{
	int arr[] = {1,2,3,4,4,3,2,1};
	vector<int> vec(arr, arr+8);
	Solution sol;
	bool ret = sol.hasGroupsSizeX(vec);
	cout<<"ret:"<<ret<<endl;
}
