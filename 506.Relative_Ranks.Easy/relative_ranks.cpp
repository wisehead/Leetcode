/*******************************************************************************
 *      file name: relative_ranks.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/08/21-09:21:07                              
 *  modified time: 2018/08/21-09:21:07                              
 *******************************************************************************/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
struct athletes 
{
    int score,index;
};
class Solution {
public:
	string int2str(const int &int_temp)  
	{  
        stringstream stream;  
        stream<<int_temp;  
        string string_temp=stream.str();   //此处也可以用 stream>>string_temp  
		return string_temp;
	}  

    static bool comp(const athletes &a, const athletes &b){
        if (a.score > b.score)
            return true;
        else if (a.score == b.score  && a.index > b.index)
            return true;
        else                ///这里的else return false非常重要！！！！！
            return false;
    }

    vector<string> findRelativeRanks(vector<int>& nums) {
		int size = nums.size();
		vector<string> res(size);
		vector<athletes> vec;
		for (int i=0; i < size; i++)
		{
			athletes temp;
			temp.score = nums[i];
			temp.index = i;
			vec.push_back(temp);
		}
		sort(vec.begin(), vec.end(), comp);
		for (int i=0; i< vec.size(); i++)
		{
			int index = vec[i].index;
			int score = vec[i].score;
			if (i == 0)
				res[index] = "Gold Medal";
			else if (i == 1)
				res[index] = "Silver Medal";
			else if (i == 2)
				res[index] = "Bronze Medal";
			else
				res[index] = int2str(i+1);
		}

		for (int i=0; i< res.size(); i++)
		{
			cout<<"res["<<i<<"] is:"<<res[i]<<endl;
		}

		return res;
    }
};
int main()
{
	int arr[5] = {5,4,3,2,1};
	vector<int> input(arr, arr+5);
	vector<string> res;
	Solution sol;
	res = sol.findRelativeRanks(input);
}
