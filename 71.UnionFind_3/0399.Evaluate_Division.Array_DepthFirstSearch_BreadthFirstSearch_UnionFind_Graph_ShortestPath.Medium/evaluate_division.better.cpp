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
        int N = _equations.size();
        for (int i = 0; i < N; i++) {
            auto vec = _equations[i];
            mp[vec] = _values[i];
            ss.insert(vec[0]);
            ss.insert(vec[1]);
        }
        valid();

        for (auto vec : queries) {
            if (vec[0] == vec[1] && ss.count(vec[0])) {
                res.push_back(1.0);
                continue;
            }
            if (mp.count(vec)) {
                res.push_back(mp[vec]);
            } else {
                swap(vec[0], vec[1]);
                if (mp.count(vec)) {
                    double ret = mp[vec];
                    ret = 1/ret;
                    res.push_back(ret);
                } else {
                    res.push_back(MINUS);
                }
            }
        }

        return res;
    }

    void valid() {
        for (int i = 0; i < _equations.size(); i++) {
            vector<string> v1 = _equations[i];
            double val1 = _values[i];
            double ret = 0;
            for (int j = i+1; j < _values.size(); j++) {
                vector<string> v2 = _equations[j];
                double val2 = _values[j];
                vector<string> vec(2,"");
                if (v2[0] == v1[0]) {
                    vec[0] = v2[1];
                    vec[1] = v1[1];
                    ret = val1/val2;
                } else if (v2[0] == v1[1]) {
                    vec[0] = v1[0];
                    vec[1] = v2[1];
                    ret = val1*val2;
                } else if (v2[1] == v1[0]) {
                    vec[0] = v2[0];
                    vec[1] = v1[1];
                    ret = val1*val2;
                } else if (v2[1] == v1[1]) {
                    vec[0] = v1[0];
                    vec[1] = v2[0];
                    ret = val1/val2;
                }
                vector<string> vecxx(2,"");
                vecxx[0] = vec[1];
                vecxx[1] = vec[1];
                if (!mp.count(vec) && !mp.count(vecxx)) {
                    _equations.push_back(vec);
                    _values.push_back(ret);
                    mp[vec] = ret;
                    ss.insert(vec[0]);
                    ss.insert(vec[1]);
                }
            }
        }
    }
private:
    vector<vector<string>> _equations;
    vector<double> _values;
    map<vector<string>, double> mp;
    set<string> ss;

};
int main()
{}
