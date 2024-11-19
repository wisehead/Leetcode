/*******************************************************************************
 *      file name: throne_inheritance.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/18-18:06:37                              
 *  modified time: 2020/10/18-18:06:37                              
 *******************************************************************************/
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
using namespace std;
struct Node {
    bool alive;
    string name;
    vector<Node> child;
    Node(string str) {
        name = str;
        alive = true;
    }
};

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        vector<string> vec;
        ht[kingName] = vec;
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        ht[parentName].push_back(childName);
    }
    
    void death(string name) {
        dset.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> order_list;
        stack<string> st;
        st.push(king);
        while (!st.empty()) {
            string x = st.top();
            st.pop();
            if (!dset.count(x))
                order_list.push_back(x);
            vector<string> vec = ht[x];
            while (!vec.empty() ) {
                string e = vec.back();
                vec.pop_back();
                st.push(e);
            }
        }
        return order_list;
    }
private:
    string king;
    map<string, vector<string>> ht;
    set<string> dset;
    //vector<string> order_list;
    //stack<string> st;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
int main()
{}
