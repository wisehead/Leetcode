/*******************************************************************************
 *      file name: matrix_cells_in_distance_order.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/20-09:28:27                              
 *  modified time: 2020/09/20-09:28:27                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		multimap<int, vector<int>> mm;
		vector<vector<int>> res;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				int x = abs(i-r0) + abs(j-c0);
				vector<int> vec;
				vec.push_back(i);
				vec.push_back(j);
				mm.insert(pair<int, vector<int>>(x, vec));
			}
		}
		map<int, vector<int>>::iterator iter;
		for(iter = mm.begin(); iter != mm.end(); iter++)
		{
			res.push_back(iter->second);
			//Cout<<iter->first<<””<<iter->second<<end;
		}
		return res;
    }
};
int main()
{}
