/*******************************************************************************
 *      file name: prime_arrangements.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/11/13-16:29:11                              
 *  modified time: 2020/11/13-16:29:11                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    Solution() {
        //int arr[] = {2,3,5,7,11,13,17,19,23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 91, 97};
        vector<int> vec = {2,3,5,7,11,13,17,19,23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 91, 97};
        //vector<int> vec(arr, arr+26);
        set<int> st(vec.begin(), vec.end());     
        s = st;
    }

    
    bool isPrime(int n) {
        cout<<"n:"<<n<<"    s.count("<<n<<"):"<<s.count(n)<<endl;
        return s.count(n) > 0;
    }

	bool valid(vector<int> & vec) {
		for (int i = 0; i < vec.size(); i++) {
			if (isPrime(vec[i]) && !isPrime(i+1)) return false;
		}
		return true;
	}
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)    {
        if (begin >= num.size()) {
            // one permutation instance
            result.push_back(num);
            return;
        }
        
        for (int i = begin; i < num.size(); i++) {
            //if (!isPrime(num[i]) || isPrime(num[i]) && isPrime(i+1))
		   	{
                swap(num[begin], num[i]);
                permuteRecursive(num, begin + 1, result);
                // reset
                swap(num[begin], num[i]);
            }
        }
    }
    
    int numPrimeArrangements(int n) {
        vector<vector<int> > result;
        vector<int> num;
        for (int i = 1; i <= n; i++) num.push_back(i);
		int cnt = 0;
        permuteRecursive(num, 0, result);
		for (auto v : result) {
			if (!valid(v)) continue;
			cnt++;
			cout<<endl;
			for (auto e : v) {
				cout<<" "<<e;
			}
			cout<<endl;
		}
		cout<<"cnt:"<<cnt<<endl;
        return cnt;
    }
private:
    set<int> s;
};

int main() {
	Solution sol;
	sol.numPrimeArrangements(5);
}

