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
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target) return letters.front();
        int low = 0, high = letters.size() - 1;
        while (low < high) {
            auto mid = (low + high) / 2;
            if (target < letters[mid]) high = mid;
            else low = mid + 1;
        }
        return letters[low];
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
