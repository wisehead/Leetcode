/*******************************************************************************
 *      file name: island_perimeter.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/07/20-21:30:41                              
 *  modified time: 2018/07/20-21:30:41                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int> >& grid) {
		int n = grid.size();
		cout<<"n is:"<<n<<endl;
		int m = grid[0].size();
		cout<<"m is:"<<m<<endl;
		int num_ones = 0;
		int num_edge = 0;
		for (int i = 0; i < n; i++)
		{
			cout<<"i is:"<<i<<endl;
			for (int j = 0; j<m; j++)
			{
				cout<<"j is:"<<j<<endl;
				if(grid[i][j])
					num_ones++;
				if(j > 0 && (grid[i][j]& grid[i][j-1]))
					num_edge++;
				if(i > 0 && (grid[i][j]& grid[i-1][j]))
					num_edge++;
			}
		}
		return num_ones*4 - num_edge*2;
    }
};
int main()
{
	int arr1[4] = {0,1,0,0};
	vector<int> v1(arr1, arr1+4);
	int arr2[4] = {1,1,1,0};
	vector<int> v2(arr2, arr2+4);
	int arr3[4] = {0,1,0,0};
	vector<int> v3(arr3, arr3+4);
	int arr4[4] = {1,1,0,0};
	vector<int> v4(arr4, arr4+4);
	vector<vector<int> >vec;
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	Solution sol;
	int ret = sol.islandPerimeter(vec);
	cout<<"ret is:"<<ret<<endl;
}
