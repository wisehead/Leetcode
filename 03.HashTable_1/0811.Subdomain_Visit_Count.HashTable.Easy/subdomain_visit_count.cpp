/*******************************************************************************
 *      file name: subdomain_visit_count.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/11/06-19:40:20                              
 *  modified time: 2018/11/06-19:40:20                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
		int len = cpdomains.size();
		map<string, int> res;
		vector<string> vec;
		for (int i = 0; i < len; i++)
		{
			string item = cpdomains[i];
			int url_pos = item.find(' ');
			string count_str = item.substr(0, url_pos); 
			int count = std::stoi(count_str);
			cout<<"count:"<<count<<endl;
			url_pos++;
			string url = item.substr(url_pos, item.length() - url_pos);
			cout<<"url:"<<url<<endl;
			while (url.length() > 0)
			{
				if (res.count(url))
				{
					res[url] += count;
				}
				else
					res[url] = count;
				int pos = url.find('.');
				if (pos != string::npos) 
					url = url.substr(pos + 1, url.length() - pos - 1);
				else
					break;
			} 
		}
		map<string, int>::iterator it;
		for (it = res.begin(); it != res.end(); it++)
		{
			string domain = it->first;
			int count = it->second;
			stringstream ss;
			ss<<count;
			string temp = ss.str();
			string item = temp + " " + domain;
			cout<<"item:"<<item<<endl;
			vec.push_back(item);
		}
		return vec;
    }
};
int main()
{}
