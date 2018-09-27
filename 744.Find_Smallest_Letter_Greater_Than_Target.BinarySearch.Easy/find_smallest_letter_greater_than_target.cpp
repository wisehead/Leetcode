/*******************************************************************************
 *      file name: find_smallest_letter_greater_than_target.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/27-16:08:28                              
 *  modified time: 2018/09/27-16:08:28                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int search(vector<char>& nums, char target) {
		int left = 0;
		int right = nums.size()-1;
		int mid = (left + right)/2;
		while(left <= right) {
			mid = (left + right)/2;
			if(nums[mid] < target) {
				left = mid+1;
			} else if(nums[mid] > target) {
				right = mid-1;
			}
			else
				break;
		}
		//cout<<"c	f	j"<<endl;
		//cout<<"target:"<<target<<endl;
		cout<<"left:"<<left<<"	right:"<<right<<"	mid:"<<mid<<endl;
		//cout<<endl;
		if (left <= right) return mid + 1;
		return left;
	}
    char nextGreatestLetter(vector<char>& letters, char target) {
		int pos = search(letters, target);
        cout<<"pos is:"<<pos<<endl;
        while(letters[pos] == target) pos++;
		if (pos == letters.size()) pos = 0;
		return letters[pos];
    }
};
int main()
{
	char arr1[3] = {'c', 'f', 'j'};
	vector<char> vec1(arr1, arr1+3);
	char target = 'a';
	Solution sol;
	sol.nextGreatestLetter(vec1, target);
	target = 'c';
	sol.nextGreatestLetter(vec1, target);
	target = 'd';
	sol.nextGreatestLetter(vec1, target);
	target = 'g';
	sol.nextGreatestLetter(vec1, target);
	target = 'j';
	sol.nextGreatestLetter(vec1, target);
	target = 'k';
	sol.nextGreatestLetter(vec1, target);
}
