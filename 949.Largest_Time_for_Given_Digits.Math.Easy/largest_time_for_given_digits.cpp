/*******************************************************************************
 *      file name: largest_time_for_given_digits.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/02/02-20:48:57                              
 *  modified time: 2019/02/02-20:48:57                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	string getMinutes(vector<int>& A) {
		cout<<"A[0]:"<<A[0]<<"	A[1]:"<<A[1]<<endl;
		string res;
		if (A[1]*10 + A[0] > 59)
		{
			if (A[0]*10 + A[1] > 59)
				return "";
			else
			{
				res.append(1, '0' + A[0]);
				res.append(1, '0' + A[1]);
			}
		}
		else
		{
			res.append(1, '0' + A[1]);
			res.append(1, '0' + A[0]);
		}
		return res;
	}
    string largestTimeFromDigits(vector<int>& A) {
		string res;
		sort(A.begin(), A.end());
		vector<int>::iterator it;
		// first digit is 2
		cout<<"39"<<endl;
		it = find(A.begin(), A.end(), 2);
		if (it != A.end())
		{
			cout<<"42"<<endl;
			res.append(1, '0' + *it);
			A.erase(it);
			for (it = A.begin(); it != A.end() && *it <= 3 ; it++);
			if (it == A.end())
			{	
				if (A[2] > 3 ) return "";
			}
			if (it == A.begin()) return "";

			it--;
			res.append(1, '0' + *it);
			A.erase(it);
			string tmp = getMinutes(A);
			if (tmp == "") return "";
			res += ":" + tmp;
			cout<<"res:"<<res<<endl;
		} else
		{
			cout<<"52"<<endl;
			it = find(A.begin(), A.end(), 1);
			if (it != A.end())
			{
				res.append(1, '0' + *it);
				A.erase(it);
				it = A.end() - 1;
				res.append(1, '0' + *it);
				A.erase(it);
				string tmp = getMinutes(A);
				if (tmp == "") return "";
				res += ":" + tmp;
				cout<<"res"<<res<<endl;
			}
			else
			{
				cout<<"66"<<endl;
				it = find(A.begin(), A.end(), 0);
				if (it != A.end())
				{
					res.append(1, '0' + *it);
					A.erase(it);
					it = A.end() - 1;
					res.append(1, '0' + *it);
					A.erase(it);
					string tmp = getMinutes(A);
					if (tmp == "") return "";
					res += ":" + tmp;
					cout<<"res"<<res<<endl;
				}
				else
					return "";
			}
		}
		return res;
    }
};
int main()
{
	Solution sol;
	//int arr[] = {1,2,3,4};
	//int arr[] = {5,5,5,5};
	//int arr[] = {4,2,4,4};
	//int arr[] = {9,0,7,7};
	int arr[] = {2,0,6,6};
	vector<int> vec(arr, arr+4);
	string res = sol.largestTimeFromDigits(vec);
	cout<<"res:"<<res<<endl;
}
