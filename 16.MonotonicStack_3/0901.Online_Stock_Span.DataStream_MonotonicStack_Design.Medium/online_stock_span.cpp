/*******************************************************************************
 *      file name: online_stock_span.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/17- 1:01                                    
 * modified time: 25/01/17- 1:01                                    
 *******************************************************************************/
#include <iostream>
class StockSpanner {
public:
    StockSpanner() {
        vector<int> v = {INT_MAX,1};
        vec.push_back(v);
    }

    int next(int price) {
        int cnt = 0;
        int n = vec.size();
        vector<int> v = {price, 1};
        for (int i = n-1; i >= 0; --i) {
            if (vec[i][0] == price) {
                v[1] += vec[i][1];
                vec.push_back(v);
                break;
            } else if (vec[i][0] < price) {
                int cnt = vec[i][1];
                v[1] += cnt;
                i = i - cnt + 1;
            } else {
                vec.push_back(v);
                break;
            }
        }
        return v[1];
    }
public:
    vector<vector<int>> vec;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
