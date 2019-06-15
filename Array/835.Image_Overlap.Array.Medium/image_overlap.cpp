/*******************************************************************************
 *      file name: image_overlap.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/06/15-10:40:21                              
 *  modified time: 2019/06/15-10:40:21                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int overlap(vector<vector<int>>& A, vector<vector<int>>& B, 
			int start_i1, int start_j1, int end_i1, int end_j1, 
			int start_i2, int start_j2, int end_i2, int end_j2)
	{
        //cout<<"start_i1:"<<start_i1<<"  start_j1:"<<start_j1<<endl;
        //cout<<"end_i1:"<<end_i1<<"  end_j1:"<<end_j1<<endl;
        //cout<<"start_i2:"<<start_i2<<"  start_j2:"<<start_j2<<endl;
        //cout<<"end_i2:"<<end_i2<<"  end_j2:"<<end_j2<<endl;
		int cnt = 0;
		int x1 = start_i1, x2 = start_i2;
		int y1 = start_j1, y2 = start_j2;
		for (;x1 <= end_i1 && x2 <= end_i2; x1++, x2++)
		{
            y1 = start_j1; y2 = start_j2;
			for (;y1 <= end_j1 && y2 <= end_j2; y1++, y2++)
			{
                //cout<<"A["<<x1<<"]["<<y1<<"]:"<<A[x1][y1]<<endl;
                //cout<<"B["<<x2<<"]["<<y2<<"]:"<<B[x2][y2]<<endl;
				if (A[x1][y1]&&B[x2][y2])
					cnt++;
			}
		}
		return cnt;

	}
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int ret = 0;
		int n = A[0].size();
		for (int i=0; i < n; i++)
		{
			for (int j=0; j < n; j++)
			{
                //cout<<"i:"<<i<<"    j:"<<j<<endl;
				int temp = overlap(A, B, 0, 0, i, j, n-1-i, n-1-j, n-1, n-1);
				ret = max(ret, temp);
                //cout<<"temp:"<<temp<<endl;
				temp = overlap(A, B, 0, j, i, n-1, n-1-i, 0, n-1, n-1-j);
				ret = max(ret, temp);
                //cout<<"temp:"<<temp<<endl;
				temp = overlap(A, B, i, 0, n-1, j, 0, n-1-j, n-1-i, n-1);
				ret = max(ret, temp);
                //cout<<"temp:"<<temp<<endl;
				temp = overlap(A, B, i, j, n-1, n-1, 0, 0, n-1-i, n-1-j);
				ret = max(ret, temp);
                //cout<<"temp:"<<temp<<endl;
			}
		}
		return ret;
    }
};
int main()
{}
