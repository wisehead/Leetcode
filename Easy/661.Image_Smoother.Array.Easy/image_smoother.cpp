/*******************************************************************************
 *      file name: image_smoother.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/08-16:52:58                              
 *  modified time: 2018/09/08-16:52:58                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool isValid(int i, int j, int m, int n) {
		if (i<0 || i>=n || j<0 || j>=n) return false;
		return true;
	}
    vector<vector<int> > imageSmoother(vector<vector<int> >& M) {
		vector<vector<int> > res;
		int m = M.size();
		int n = M[0].size();
		for (int i = 0; i < m; i++ )
		{
			vector<int> vec;
			for (int j = 0; j < n; j++)
			{
                cout<<"i:"<<i<<"    j:"<<j<<endl;
				int temp = 0;
				int count = 0;
				if (isValid(i-1,j-1,m,n)) 
				{
					temp += M[i-1][j-1];
					count++;
				}
				if (isValid(i-1,j,m,n)) 
				{
					temp += M[i-1][j];
					count++;
				}
				if (isValid(i-1,j+1,m,n)) 
				{
					temp += M[i-1][j+1];
					count++;
				}
				if (isValid(i,j-1,m,n)) 
				{
					temp += M[i][j-1];
					count++;
				}
				if (isValid(i,j,m,n)) 
				{
					temp += M[i][j];
					count++;
				}
				if (isValid(i,j+1,m,n)) 
				{
					temp += M[i][j+1];
					count++;
				}
				if (isValid(i+1,j-1,m,n)) 
				{
					temp += M[i+1][j-1];
					count++;
				}
				if (isValid(i+1,j,m,n)) 
				{
					temp += M[i+1][j];
					count++;
				}
				if (isValid(i+1,j+1,m,n)) 
				{
					temp += M[i+1][j+1];
					count++;
				}
				temp = temp/count;
                //cout<<"lineno:"<<__LINE__<<endl;
				//temp = (M[i-1][j-1] + M[i-1][j] + M[i-1][j+1] + M[i][j-1] + M[i][j] + M[i][j+1] + M[i+1][j-1] + M[i+1][j] + M[i+1][j+1])/9; 
				vec.push_back(temp);

			}
			res.push_back(vec);
		}
		return res;
    }
	/*
    vector<vector<int> > imageSmoother(vector<vector<int> >& M) {
		vector<vector<int> > res;
		int m = M.size();
		int n = M[0].size();
		for (int i = 0; i < m; i++ )
		{
			vector<int> vec;
			for (int j = 0; j < n; j++)
			{
                cout<<"i:"<<i<<"    j:"<<j<<endl;
				int temp = 0;

				// 4 corners
				if (i==0 && j==0)
				{
                    cout<<"lineno:"<<__LINE__<<endl;
                    if (j+1 <n && i+1 <m)
					    temp = (M[i][j] + M[i][j+1] + M[i+1][j] + M[i+1][j+1]) / 4; 
                    else 
                    {
                        if (j+1 >=n && i+1>=m)
                            temp = M[i][j];
                        else if (j+1>=n)
                            temp = (M[i][j] + M[i+1][j])/2;
                        else
                            temp = (M[i][j] + M[i][j+1])/2;
                    }
					vec.push_back(temp);
					continue;
				}
				if( i==0 && j==n-1)
				{
                    cout<<"lineno:"<<__LINE__<<endl;
					temp = (M[i][j-1] + M[i][j] + M[i+1][j-1] + M[i+1][j]) / 4; 
					vec.push_back(temp);
					continue;
				}
				if (i==m-1 && j== 0 )
				{
					temp = (M[i-1][j] + M[i-1][j+1] + M[i][j] + M[i][j+1])/4;
					vec.push_back(temp);
					continue;
				}
				if (i==m-1 && j==n-1)
				{
                    cout<<"lineno:"<<__LINE__<<endl;
					temp = (M[i-1][j-1] + M[i-1][j] + M[i][j-1] + M[i][j])/4; 
					vec.push_back(temp);
					continue;
				}

				if (i==0 && (i+1)<m )
				{
                    cout<<"lineno:"<<__LINE__<<endl;
					temp = (M[i][j-1] + M[i][j] + M[i][j+1] + M[i+1][j-1] + M[i+1][j] + M[i+1][j+1])/6;
					vec.push_back(temp);
					continue;
				}
				if(i==m-1 && (i-1)>=0)
				{
                    cout<<"lineno:"<<__LINE__<<endl;
					temp = (M[i-1][j-1] + M[i-1][j] + M[i-1][j+1] + M[i][j-1] + M[i][j] + M[i][j+1])/6; 
					vec.push_back(temp);
					continue;
				}
				if(j==0 && (j+1)<n && (i-1)>=0 && (i+1))
				{
                    cout<<"lineno:"<<__LINE__<<endl;
					temp = (M[i-1][j] + M[i-1][j+1] + M[i][j] + M[i][j+1] + M[i+1][j] + M[i+1][j+1])/6; 
					vec.push_back(temp);
					continue;
				}
				if (j==n-1 && (j-1)>=0)
				{
                    cout<<"lineno:"<<__LINE__<<endl;
					temp = (M[i-1][j-1] + M[i-1][j] + M[i][j-1] + M[i][j] + M[i+1][j-1] + M[i+1][j])/6; 
					vec.push_back(temp);
					continue;
				}
				if ((i-1)>=0 && (i+1)<m && (j-1)>=0 && (j+1)<n)
				{
                    cout<<"lineno:"<<__LINE__<<endl;
					temp = (M[i-1][j-1] + M[i-1][j] + M[i-1][j+1] + M[i][j-1] + M[i][j] + M[i][j+1] + M[i+1][j-1] + M[i+1][j] + M[i+1][j+1])/9; 
					vec.push_back(temp);
				}
			}
			res.push_back(vec);
		}
		return res;
    }
	*/
};
                   
int main()
{}
