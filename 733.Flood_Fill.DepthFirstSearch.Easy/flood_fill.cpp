/*******************************************************************************
 *      file name: flood_fill.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/27-14:15:09                              
 *  modified time: 2018/09/27-14:15:09                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool is_pos_valid(int sr, int sc, int sr_max_len, int sc_max_len) {
		return (0 <= sr && sr < sr_max_len  && 0 <= sc && sc < sc_max_len);
	}
    void floodFill0(vector<vector<int> >& image, int sr, int sc, int oldColor, int newColor) {
		int sr_max_len = image.size();
		int sc_max_len = image[0].size();
        //cout<<"sr:"<<sr<<"  sc:"<<sc<<"sr_max_len:"<<sr_max_len<<"  sc_max_len:"<<sc_max_len<<endl;
		if (!is_pos_valid(sr, sc, sr_max_len, sc_max_len)) return;
        //cout<<"image[sr][sc]:"<<image[sr][sc]<<"   oldColor:"<<oldColor<<"  newColor:"<<newColor<<endl;
		if (image[sr][sc] != oldColor) return;
        if (image[sr][sc] == newColor) return;
		image[sr][sc] = newColor;
		floodFill0(image, sr - 1, sc, oldColor, newColor);
		floodFill0(image, sr, sc + 1, oldColor, newColor);
		floodFill0(image, sr + 1, sc, oldColor, newColor);
		floodFill0(image, sr, sc - 1, oldColor, newColor);
	}

    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
		cout<<"haha:"<<endl;
        int oldColor = image[sr][sc];
        cout<<"oldColor:"<<oldColor<<endl;
		floodFill0(image, sr, sc, oldColor, newColor);
		return image;
    }
};
int main()
{
	int arr[3] = {0,0,0};
	vector<int> vec1(arr, arr+3);
	int arr2[3] = {0,1,1};
	vector<int> vec2(arr2, arr2+3);
	vector<vector<int> > vec;
	vec.push_back(vec1);
	vec.push_back(vec2);
	Solution sol;
	vector<vector<int> > res;
	res = sol.floodFill(vec,1,1,1);
}
