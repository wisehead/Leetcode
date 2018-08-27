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
        int len = flowerbed.size();
        int zeros = 0;
        int count = 0;
        for (int i = 0; i < len; i++)
        {
            if (flowerbed[i] == 0) 
            {
                if (i==0)
                {
                    while (flowerbed[i] == 0 && i < len)
                    {
                        zeros++;
                        i++;
                    }
                    if (i == len)
                    {
                        count += (zeros+1)/2;
                        break;
                    }
                    count += zeros/2;
                    zeros = 0;
                    i--;
                    continue;
                }
                if (flowerbed[i-1] == 0)
                    zeros++;
                else
                    zeros=1;
                if (i == len -1)
                    count += zeros/2;
            }
            else
            {
                if (flowerbed[i-1] == 0)
                    count += (zeros - 1)/2;
            }
        }
        return (count >= n);
    }
};
int main()
{}
