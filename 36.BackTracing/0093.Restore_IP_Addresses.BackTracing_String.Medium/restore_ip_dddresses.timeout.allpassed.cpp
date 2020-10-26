/*******************************************************************************
 *      file name: restore_ip_dddresses.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/26-22:40:13                              
 *  modified time: 2020/10/26-22:40:13                              
 *******************************************************************************/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    
	bool isIP(const char* str)
	{
		int a,b,c,d;
		char temp[100];
		if((sscanf(str,"%d.%d.%d.%d",&a,&b,&c,&d))!=4)
			return false;
		sprintf(temp,"%d.%d.%d.%d",a,b,c,d);
		if(strcmp(temp,str) != 0)
			return false;
		if(!((a <= 255 && a >= 0)&&(b <= 255 && b >= 0)&&(c <= 255 && c >= 0)&&(d <= 255 && d >= 0)))
			return false;
		else
			return true;
	}
		
	int digits_num(string s) {
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '.') ++cnt;
		}
		return cnt;
	}

    int dot_num(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') ++cnt;
        }
        return cnt;
    }
    
    int get_1st_num(string s) {
        int pos = s.find('.');
        if (pos == string::npos) return -1;
        string str = s.substr(0, pos);
        //cout<<"str:"<<str<<endl;
        //cout<<"pos:"<<pos<<endl;
        int i = -1;
        if (str.length() <= 3)
            i = std::stoi(str);
        return i;
    }


    void fun(vector<string> &res,string &temp, string s, int start, int len){
        if (dot_num(temp) > 4) return;
        //cout<<"temp:"<<temp<<"  start:"<<start<<"   len:"<<len<<endl;
        if(start==len && isIP(temp.c_str()) && digits_num(temp) == len ){
            //cout<<"temp:"<<temp<<"  start:"<<start<<"   len:"<<len<<endl;
            res.push_back(temp);
            return;
        }
        if (start >= len) return;
        for(int i = start; i<len; i++){
            temp.append(1, s[i]);
            fun(res,temp,s, i+1, len);
            temp.append(1, '.');
            int x = get_1st_num(temp);
            if (x >= 0 && x <= 255) 
                fun(res,temp,s, i+1, len);
            temp.pop_back();
            temp.pop_back();
            //cout<<"temp after pop:"<<temp<<endl;
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        string test = "192.168.1.1";
        int x = get_1st_num(test);
        cout<<"x:"<<x<<endl;        
        vector<string> res;
        if(s.length() == 0 || s.length() > 12)return res;
        string temp;
        fun(res,temp, s, 0, s.length());
        return res;
    }
    
};
int main()
{}
