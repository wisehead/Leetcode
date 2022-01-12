/*******************************************************************************
 *      file name: longest_absolute_file_path.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/12-11:41:27                              
 *  modified time: 2022/01/12-11:41:27                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution{
public:
	int lengthLongestPath(string input){
		stringstream ss(input);
        string data;
        int maxPathLength = 0;

		unordered_map<int,int> lengthAtEachDepth; //tab count(depth), length till that depth
		lengthAtEachDepth[0] = 0;

        while(getline(ss,data,'\n'))
        {
            int i = 0;
            while(data[i] == '\t') i++;
            string name;
            int len = 0, numOfTabs = i; //if index = 2 right after tabs means “\t\t” i.e. 2 tabs
            //above cover if [#tabs](https://leetcode.com/problems/longest-absolute-file-path) = 0
            if(i == 0) //root directory
            {
                name = data;
                lengthAtEachDepth[0] = name.size();
            }
            else
            {
                name = data.substr(i); //from the index after last \t to end
                lengthAtEachDepth[numOfTabs] = lengthAtEachDepth[numOfTabs-1] + 1 + name.size();
                //+1 is for the \ before we would append the name to the path
            }

            if(name.find('.') != string::npos) //file exists
            {
                if(lengthAtEachDepth[numOfTabs] > maxPathLength) maxPathLength = lengthAtEachDepth[numOfTabs];
            }
        }

		return maxPathLength;
    }
};
int main()
{}
