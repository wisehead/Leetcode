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

    string process(vector<int>& B, int n) {
		vector<int> A(B.begin(), B.end());
		string res;
		cout<<"process"<<n<<endl;
		vector<int>::iterator it;
		it = find(A.begin(), A.end(), n);
		if (it == A.end()) return "";
		res.append(1, '0' + *it);
		A.erase(it);

		if (n==2)
		{
			for (it = A.begin(); it != A.end() && *it <= 3 ; it++);
			if (it == A.end())
				if (A[2] > 3 ) return "";
			if (it == A.begin()) return "";
			it--;
		}
		else if (n==1)
			it = A.end() - 1;
		else if (n==0)
			it = A.end() - 1;

		res.append(1, '0' + *it);
		A.erase(it);
		string tmp = getMinutes(A);
		if (tmp == "") return "";
		res += ":" + tmp;
		return res;
	}
    string largestTimeFromDigits(vector<int>& A) {
		string res;
		sort(A.begin(), A.end());
		vector<int>::iterator it;
		res = process(A,2);
		if (res != "") return res;
		res = process(A,1);
		if (res != "") return res;
		res = process(A,0);
		if (res != "") return res; return "";
    }
};
int main()
{
	Solution sol;
	int arr[] = {1,2,3,4};
	//int arr[] = {5,5,5,5};
	//int arr[] = {4,2,4,4};
	//int arr[] = {9,0,7,7};
	//int arr[] = {2,0,6,6};
	vector<int> vec(arr, arr+4);
	string res = sol.largestTimeFromDigits(vec);
	cout<<"res:"<<res<<endl;
}
