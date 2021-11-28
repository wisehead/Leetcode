/*******************************************************************************
 *      file name: reformat_date.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/28-20:57:22                              
 *  modified time: 2021/11/28-20:57:22                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    string reformatDate(string date) {
        map<string, int> days;
        map<string, int> months;
        string arr_days[] = {"1st", "2nd", "3rd", "4th", "5th","6th", "7th", "8th", "9th", "10th","11th","12th", "13th", "14th", "15th", "16th","17th","18th","19th","20th","21st","22nd","23rd","24th","25th","26th","27th","28th","29th","30th", "31st"};
        string arr_mons[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for (int i = 0; i < 31; i++) 
            days[arr_days[i]] = i+1;
        for (int i = 0; i < 12; i++) 
            months[arr_mons[i]] = i+1;    
        
        string d, m, y;
        if (date[3] == ' ') {
            d = date.substr(0,3);
            m = date.substr(4,3);
            y = date.substr(8,4);
        } else {
            d = date.substr(0,4);
            m = date.substr(5,3);
            y = date.substr(9,4);            
        }
        //cout<<"y:"<<y<<",m:"<<m<<",d:"<<d<<endl;
        string res;
        res = y+"-";
        int mm = months[m];
        if (mm < 10) res += "0"+ std::to_string(mm) + "-";
        else res += std::to_string(mm)+"-";
        
        int dd = days[d];
        if (dd < 10) res += "0" + std::to_string(dd);
        else res += std::to_string(dd);
        
        return res;
    }
};
int main()
{}
