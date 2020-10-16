/*******************************************************************************
 *      file name: design_browser_history.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/16-11:19:09                              
 *  modified time: 2020/10/16-11:19:09                              
 *******************************************************************************/
#include <iostream>
using namespace std;
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        data.push_back(homepage);
        pos = 0;
    }
    
    void visit(string url) {
        data.erase(data.begin() + pos + 1, data.end());
        data.push_back(url);
        pos++;
    }
    
    string back(int steps) {
        pos -= std::min(steps, pos);
        return data[pos];
    }
    
    string forward(int steps) {
        pos += min(steps, (int)(data.size()-1-pos));
        return data[pos];
    }
private:
    vector<string> data;
    int pos;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
int main()
{}
