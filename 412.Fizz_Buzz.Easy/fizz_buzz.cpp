/*******************************************************************************
 *      file name: fizz_buzz.cpp                                               
 *         author: hui chen. (c) 17                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 17/10/16-10:10                                    
 * modified time: 17/10/16-10:10                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;
class Solution {
public:
    /*
     * @param n: An integer
     * @return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        // write your code here
        vector<string> result;
        for (int i=1; i<=n; i++)
        {
			stringstream ss;
			string str_i;
			ss<<i; 
			ss>>str_i;
			if (i % 3 != 0 && i % 5 != 0)
			{
				result.push_back(str_i);
				continue;
			}
            if (i % 3 == 0 && i % 5 == 0)
			{
				result.push_back("fizz buzz");
			}
			else
            {
                if (i % 3 == 0)
					result.push_back("fizz");
                if (i % 5 == 0)
                    result.push_back("buzz");
            }
        }
        return result;
    }

	void print_vec(vector<string>& vec)
	{
		vector<string>::iterator it;
		for (it = vec.begin(); it != vec.end(); it++)
			cout << *it << endl;
	}
};

int main()
{
	Solution sol;
	vector<string> output = sol.fizzBuzz(20);
	sol.print_vec(output);
}
