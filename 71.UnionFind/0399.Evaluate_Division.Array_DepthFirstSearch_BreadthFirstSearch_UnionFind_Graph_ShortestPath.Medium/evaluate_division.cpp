/*******************************************************************************
 *      file name: evaluate_division.cpp                                               
 *         author: Hui Chen. (c) 2022                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2022/01/16-20:20:39                              
 *  modified time: 2022/01/16-20:20:39                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        double MINUS = -1.0;
        _equations = equations;
        _values = values;
        valid();
        set<string> ss;
        
        map<vector<string>, double> mp;
        int N = _equations.size();
        for (int i = 0; i < N; i++) {
            auto vec = _equations[i];
            //cout<<"vec[0]:"<<vec[0]<<",vec[1]:"<<vec[1]<<",values[i]:"<<_values[i]<<endl;
            mp[vec] = _values[i];
            ss.insert(vec[0]);
            ss.insert(vec[1]);
        }
        
        for (auto vec : queries) {
            //cout<<"vec[0]:"<<vec[0]<<",vec[1]:"<<vec[1]<<endl;
            if (vec[0] == vec[1] && ss.count(vec[0])) {
                res.push_back(1.0);
                continue;
            }
            if (mp.count(vec)) {
                //cout<<"------1----"<<endl;
                res.push_back(mp[vec]);
            } else {
                //cout<<"------2----"<<endl;
                swap(vec[0], vec[1]);
                //cout<<"vec[0]:"<<vec[0]<<",vec[1]:"<<vec[1]<<endl;
                if (mp.count(vec)) {
                    //cout<<"------3----"<<endl;
                    double ret = mp[vec];
                    ret = 1/ret;
                    res.push_back(ret);
                } else {
                    //cout<<"------4----"<<endl;
                    res.push_back(MINUS);
                }
            }
        }
        
        return res;
    }
    
    bool exist(vector<string> vec) {
        for (auto v : _equations) {
            if (v[0] == vec[0] && v[1] == vec[1]) return true;
            if (v[0] == vec[1] && v[1] == vec[0]) return true;
        }
        return false;
    }
    void valid() {
        vector<vector<string>> res;
        vector<double> vals;
        //int N = _equations.size();
        for (int i = 0; i < _equations.size(); i++) {
            vector<string> v1 = _equations[i];
            double val1 = _values[i];
            for (int j = i+1; j < _values.size(); j++) {
                vector<string> v2 = _equations[j];
                double val2 = _values[j];
                vector<string> vec(2,"");
                //cout<<"v1:"<<v1[0]<<","<<v1[1]<<";v2:"<<v2[0]<<","<<v2[1]<<endl;
                if (v2[0] == v1[0]) {
                    //cout<<"---------11------"<<endl;
                    vec[0] = v2[1];
                    vec[1] = v1[1];
                    if (!exist(vec)) {
                        _equations.push_back(vec);
                        _values.push_back(val1/val2);
                    }
                    
                } else if (v2[0] == v1[1]) {
                    //cout<<"---------12------"<<endl;
                    vec[0] = v1[0];
                    vec[1] = v2[1];
                    if (!exist(vec)) {
                        _equations.push_back(vec);
                        _values.push_back(val1*val2);
                    }
                } else if (v2[1] == v1[0]) {
                    //cout<<"---------13------"<<endl;
                    vec[0] = v2[0];
                    vec[1] = v1[1];
                    if (!exist(vec)) {
                        _equations.push_back(vec);
                        _values.push_back(val1*val2);
                    }                    
                } else if (v2[1] == v1[1]) {
                    //cout<<"---------14------"<<endl;
                    vec[0] = v1[0];
                    vec[1] = v2[0];
                    if (!exist(vec)) {
                        _equations.push_back(vec);
                        _values.push_back(val1/val2);
                    }
                } else {
                    //do nothing.
                    //cout<<"---------15------"<<endl;
                }
            }
        }
        //_equations.insert(_equations.end(), res.begin(), res.end());
        //_values.insert(_values.end(), vals.begin(), vals.end());
        return;
    }
private:    
    vector<vector<string>> _equations;
    vector<double> _values;
};
int main()
{}
