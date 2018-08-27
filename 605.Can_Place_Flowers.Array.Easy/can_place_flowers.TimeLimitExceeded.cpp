/*******************************************************************************
 *      file name: can_place_flowers.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/27-12:29:39                              
 *  modified time: 2018/08/27-12:29:39                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n==0)
            return true;
		int len = flowerbed.size();
		int count = 0;
		vector<int> pos;
		for (int i = 0; i < len; i++)
		{
			if (i==0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
			{
				count++;
				pos.push_back(i);
				continue;
			}
			if (i== len-1 && flowerbed[i] == 0 && flowerbed[i-1] == 0)
			{
				count++;
				pos.push_back(i);
				continue;
			}
				
			if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
			{
				pos.push_back(i);
				count++;
			}
		}
        //cout<<"count is:"<<count<<endl;
        if (n==1 && count>= n)
            return true;
		if (count < n)
			return false;
		for (int i = 0; i < count; i++)
		{
			int index = pos[i];
			vector<int> newbed(flowerbed);
			newbed[index] = 1;
			if (canPlaceFlowers(newbed, n-1))
				return true;
		}
		return false;
    }
};
int main()
{}
