/*******************************************************************************
 *      file name: max_chunks_to_make_sorted.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/22-09:44:01                              
 *  modified time: 2019/05/22-09:44:01                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int check(vector<int>& arr, int s, int e) {
        for (int i = s; i <= e; i++)
        {
            if(arr[i] < s) return -1;
            if (arr[i] > e) 
                e = arr[i];
            //cout<<"arr["<<i<<"]"<<arr[i]<<endl;
        }
            
        cout<<"return true"<<endl;
        return (e-s);
    }
    int maxChunksToSorted(vector<int>& arr) {
		int count = 0;
		for (int i = 0; i < arr.size(); )
		{
			if (arr[i] - i == 0)
            {
                count++;
                i++;
            }
            else if (arr[i] - i > 0)
            {
                int x = arr[i] - i;
                int r = check(arr, i, i+x);
                cout<<"r:"<<r<<endl;
                if (r > 0)
                {
                    i += (r+1);
                    count++;
                }
                else
                    return 1;
            }
            else
            {
                cout<<"arr["<<i<<"]"<<arr[i]<<endl;
                i++;
            }
		}
		return count;
    }
};
int main()
{}
