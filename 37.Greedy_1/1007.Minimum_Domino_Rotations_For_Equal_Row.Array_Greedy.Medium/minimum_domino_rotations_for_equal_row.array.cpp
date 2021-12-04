/*******************************************************************************
 *      file name: minimum_domino_rotations_for_equal_row.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/07/12-09:52:44                              
 *  modified time: 2019/07/12-09:52:44                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool contains(int arr[], int x) {
        return (arr[0] == x || arr[1] == x);
    }
    int minDominoRotations(vector<int>& A, vector<int>& B) {
		int n = A.size();
		if (n == 0) return 0;
		//unordered_map<int, int> ma, mb;
        int arrA[2] = {0};
        int arrB[2] = {0};
		int x1 = A[0], x2 = B[0];
		arrA[0] = 1;
        arrA[1] = 0;
        arrB[1] = 1;
        arrB[0] = 0;

		for (int i = 1; i < n; i++)
		{
            //if (!contains(arrA, A[i]) && !contains(arrB, B[i])) return -1;
            if (x1 != A[i] && x2 != A[i] &&  x1 != B[i] && x2 != B[i]) return -1;
			int x = A[i];
            if (x1 == x)
                arrA[0]++;
            else if (x2 == x)
                arrA[1]++;
            
			int y = B[i];
            if (x1 == y)
                arrB[0]++;
            else if (x2 == y)
                arrB[1]++;
        cout<<"i:"<<i<<endl;
        cout<<"arrA[0]:"<<arrA[0]<<"  arrA[1]:"<<arrA[1]<<endl;
        cout<<"arrB[0]:"<<arrB[0]<<"  arrB[1]:"<<arrB[1]<<endl;            
            if ((arrA[0] + arrB[0] < i+1) && (arrA[1] + arrB[1] < i+1))return -1;
		}

		if (arrA[0] + arrB[0] >= n || arrA[1] + arrB[1] >= n)
		{
			if (arrA[0] + arrB[0] >= n && arrA[1] + arrB[1] >= n)
			{
				int cnt1 = min(n - arrA[0], n - arrB[0]);
				int cnt2 = min(n - arrA[1], n - arrB[1]);
				return min(cnt1, cnt2);
			}
			if (arrA[0] + arrB[0] >= n)
				return min(n - arrA[0], n - arrB[0]);
			return min(n - arrA[1], n -arrB[1]);
		}
		return -1;
    }
};
int main()
{}
