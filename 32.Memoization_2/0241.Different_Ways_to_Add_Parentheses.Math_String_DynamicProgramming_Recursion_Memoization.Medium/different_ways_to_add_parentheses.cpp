/*******************************************************************************
 *      file name: different_ways_to_add_parentheses.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/19-11:43:33                              
 *  modified time: 2021/08/19-11:43:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int get_first_op (string exp) {
        int i = 0;
        for (i = 0; i < exp.length(); i++) {
            if (!isdigit(exp[i])) {
                break;
            }
        }        
        return i;
    }
    
    int get_next_op (string exp, int pos) {
        int i = 0;
        for (i = pos; i < exp.length(); i++) {
            if (!isdigit(exp[i])) {
                break;
            }
        }        
        return i;
    }
    
    int get_last_op (string exp) {
        int i = 0;
        for (i = exp.length()-1; i >= 0; i--) {
            if (!isdigit(exp[i])) {
                break;
            }
        }        
        return i;
    }    
    
    int cal(int e1, int e2, char op) {
        int ret = 0;
        switch(op) {
            case '+':
                ret = e1+e2;break;
            case '-':
                ret = e1 - e2; break;
            case '*':
                ret = e1*e2;break;
            default:
                break;
        }
        return ret;        
    }
    
    int compute(string exp) {
        char op;
        int ret = 0;
        int i = get_first_op(exp);
        op = exp[i];
        string a = exp.substr(0,i);
        string b = exp.substr(i+1);
        //cout<<"a:"<<a<<",b:"<<b<<endl;
        int e1 = stoi(a);
        int e2 = stoi(b);
        //cout<<"e1:"<<e1<<",e2:"<<e2<<endl;
        ret = cal(e1, e2, op);
        //cout<<"exp:"<<exp<<", ret:"<<ret<<endl;
        return ret;
    } 
    
    
    vector<int> diffWaysToCompute(string expression) {
        //cout<<":::"<<expression<<endl;
        vector<int> res;
        int first_op = get_first_op(expression);
        if (first_op == expression.length()) {
            int ret = stoi(expression);
            res.push_back(ret);
            return res;
        }
        int last_op = get_last_op(expression);
        if (first_op == last_op){
            int ret = compute(expression);
            res.push_back(ret);
            return res;
        }
        
        while (first_op <= last_op) {
            //cout<<"first_op:"<<first_op<<endl;
            vector<int> vec1 = diffWaysToCompute(expression.substr(0,first_op));
            //int a = stoi(expression.substr(0,first_op));
            char op = expression[first_op];
            vector<int> vec2 = diffWaysToCompute(expression.substr(first_op+1));
            for (auto e1 : vec1) {
                for (auto e2 : vec2) {
                    int ret = cal(e1, e2, op);
                    //cout<<"e1:"<<e1<<",e2:"<<e2<<",ret:"<<ret<<endl;
                    //st.insert(ret);   
                    res.push_back(ret);
                }
            }
            first_op = get_next_op(expression, first_op+1);
        }

        //res.assign(st.begin(), st.end());      
        return res;
    }
};
int main()
{}
