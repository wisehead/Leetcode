/*******************************************************************************
 *      file name: best_time_to_buy_and_sell_stock_with_transaction_fee.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/15-10:05:45                              
 *  modified time: 2019/05/15-10:05:45                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy_state = 0;
        int i = 0;
        int buy_price = INT_MAX;
        int sell_price = INT_MAX;
        int profit = 0;
        stack<int> s_buy;
        stack<int> s_sell;
        while (i < n)
        {
            if (buy_state == 0 || buy_state == 1)
            {
                buy_price = INT_MAX;
                if (buy_state == 0 && !s_buy.empty())
                {
                    cout<<"aaa"<<endl;
                    buy_price = s_buy.top();
                    s_buy.pop();
                }
                buy_price = min(buy_price, prices[i]);
                i++;
                while (i < n && prices[i] <= prices[i-1])
                {
                    buy_price = min(buy_price, prices[i]);
                    i++;
                }
                cout<<"buy_price:"<<buy_price<<endl;
                if (i==n)break;
                if (s_sell.size() != s_buy.size())
                {   
                    cout<<"bbb"<<endl;
                    s_buy.push(buy_price);
                }
                else
                {
                    if (s_sell.empty())
                    {
                        cout<<"ccc"<<endl;
                        s_buy.push(buy_price);
                    }
                    else
                    {
                        cout<<"ddd"<<endl;
                        int last_sell = s_sell.top();
                        if (last_sell - buy_price <= fee)
                        {
                            cout<<"eee"<<endl;
                            s_sell.pop();
                        }
                        else
                        {
                            cout<<"fff"<<endl;
                            s_buy.push(buy_price);
                        }
                    }
                }
                
                
                buy_state = 2;
            }
            else
            {
                sell_price = prices[i];
                i++;
                while (i < n && prices[i] >= prices[i-1])
                {
                    sell_price = prices[i];
                    i++;
                }
                if (sell_price - buy_price > fee)
                {
                    cout<<"ggg"<<endl;
                    s_sell.push(sell_price);
                    buy_state = 1;
                }
                else
                {
                    cout<<"hhh"<<endl;
                    buy_state = 0;
                }
                cout<<"sell_price:"<<sell_price<<endl;
            }

        }
        cout<<"s_buy.size():"<<s_buy.size()<<endl;
        cout<<"s_sell.size():"<<s_sell.size()<<endl;
            if (s_buy.size() != s_sell.size())
                s_buy.pop();
            while (!s_buy.empty())
            {
                int buy = s_buy.top();
                int sell = s_sell.top();
                cout<<"buy:"<<buy<<"    sell:"<<sell<<endl;
                profit += (sell - buy - fee);
                s_buy.pop();
                s_sell.pop();
            }
        return profit;
    }
};
int main()
{}
