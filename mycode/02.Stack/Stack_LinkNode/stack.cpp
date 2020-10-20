/*******************************************************************************
 *      file name: stack.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/09/14-15:17:25                              
 *  modified time: 2020/09/14-15:17:25                              
 *******************************************************************************/
#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int v;
    Node* next;
};

class MyStack {
public:
    MyStack() {
        _qhead = nullptr;
    }
    
    ~MyStack() {
        while (_qhead) {
            Node* tmp = _qhead;
            _qhead = tmp->next;
            delete tmp;
        }
    }
    
    void push(int x)
    {
        Node* node = new Node;
        node->v = x;
        node->next = nullptr;
        node->next = _qhead->next;
        _qhead = node;
    }
    
    int pop() {
        int ret = -1;
        Node* tmp = NULL;
        if (_qhead)
        {
            tmp = _qhead;
            _qhead = tmp->next;
            ret = tmp->v;
            delete tmp;
            return ret;
        }
        return ret;
    }
    
    int top() {
        if (_qhead)
            return _qhead->v;
        return -1;
    }
    
private:
    Node* _qhead;
};

int main()
{}
