/*******************************************************************************
 *      file name: uncommon_words_from_two_sentences.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/09-13:50:01                              
 *  modified time: 2019/01/09-13:50:01                              
 *******************************************************************************/
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> count;
        istringstream iss(A + " " + B);
        while (iss >> A) count[A]++;
        vector<string> res;
        for (auto w: count)
            if (w.second == 1)
			{
				cout<<w.first<<endl;
                res.push_back(w.first);
			}
        return res;
    }
};
int main()
{
	Solution sol;
	string A = "this apple is sweet", B = "this apple is sour"; 
	vector<string> res;
	res = sol.uncommonFromSentences(A, B);
}
