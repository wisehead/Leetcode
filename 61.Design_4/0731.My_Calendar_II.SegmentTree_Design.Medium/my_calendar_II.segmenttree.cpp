/*******************************************************************************
 *      file name: my_calendar_II.segmenttree.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/12/18-12:12                                    
 * modified time: 24/12/18-12:12                                    
 *******************************************************************************/
#include <iostream>
class Node{
    public:
        int s;
        int t;
        Node *left;
        Node *right;

        Node(int s, int t){
            this->s = s;
            this->t = t;
            left = NULL;
            right = NULL;
        }
};

class MyCalendarTwo {
public:
    Node *root;
    vector<pair<int,int>> check;

    MyCalendarTwo() {
        root = NULL;
    }

    bool dfs(int s, int t, Node* &curr, bool check){
        if(!curr){
            if(check == true){
                return 1;
            }
            curr = new Node(s,t);
            return 1;
        }

        if(curr && t <= curr->s){
            return dfs(s,t,curr->left,check);
        }
        if(curr && s >= curr->t){
            return dfs(s,t,curr->right,check);
        }
        return 0;
    }

    bool book(int start, int end) {
        if(!dfs(start,end,root,1)){
            return false;
        }

        for(auto c : check){
            if(c.first < end && start < c.second){
                int overlapMin = max(c.first, start);
                int overlapMax = min(c.second, end);
                dfs(overlapMin,overlapMax,root,0);
            }
        }
        check.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
