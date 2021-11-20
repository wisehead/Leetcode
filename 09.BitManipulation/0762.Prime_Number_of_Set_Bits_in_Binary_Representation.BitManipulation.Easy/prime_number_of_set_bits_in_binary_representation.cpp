/*******************************************************************************
 *      file name: prime_number_of_set_bits_in_binary_representation.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/10/05-11:32:23                              
 *  modified time: 2018/10/05-11:32:23                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool isPrime(int x) {
		int arr[8] = {2,3,5,7,11,13,17,19};
		vector<int> vec(arr, arr+8);
		vector<int>::iterator it = find(vec.begin(), vec.end(), x);
		return (it != vec.end());
	}

	bool countPrimeBits(int x) {
		int base = 1;
		int count = 0;
		for (int i=0; i < 20; i++)
		{
			int mask = 1 << i;
			if (base > x) break;
			if (x & mask) count++;
			base *= 2;
		}
		return isPrime(count);
	}
    int countPrimeSetBits(int L, int R) {
		int primeCnt = 0;
		for (int i=L; i <=R; i++)
		{
			if (countPrimeBits(i))
				primeCnt++;
		}
		return primeCnt;
    }
};
int main()
{}
