/*******************************************************************************
 *      file name: number_of_equivalent_domino_pairs.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/01/18-11:42:50                              
 *  modified time: 2020/01/18-11:42:50                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void print_vec(vector<int>& vec)
    {
        vector<int>::iterator it;
        cout << "the results is:"<< endl;
        for (it = vec.begin(); it != vec.end(); it++)
        {
            cout << *it << " ";
        }
        cout<<endl;
    }
    
	int com(int n) {
		return n*(n-1)/2;
	}

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		int sum = 0, cnt = 1, n = dominoes.size();
		for (auto &e : dominoes) 
			sort(e.begin(), e.end());
		sort(dominoes.begin(), dominoes.end());
		for (int i = 1; i < n; i++)
		{
            if (dominoes[i] == dominoes[i-1])
			{
				cnt++;
			}
			else
			{
				sum += com(cnt);
				cnt = 1;
			}
		}
        sum += com(cnt);
		return sum;
    }
};
int main()
{}
