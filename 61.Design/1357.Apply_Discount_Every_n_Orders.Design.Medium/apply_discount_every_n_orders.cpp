/*******************************************************************************
 *      file name: apply_discount_every_n_orders.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/15-09:28:07                              
 *  modified time: 2020/10/15-09:28:07                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for (int i = 0; i < products.size(); i++) {
            ht[products[i]] = prices[i];
        }
        N = n;
        this->discount = discount;
        cnt = 0;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        ++cnt;
        double ret = 0;
        for (int i = 0; i < product.size(); i++) {
            ret += ht[product[i]] * amount[i];
        }
        
        //cout<<"getBill: bill= "<<ret<<" rate= "<<rate<<endl;
        if (cnt % N == 0) {
            ret -=  (discount * ret)/100;
        };
        
        return ret;
    }
private:
    unordered_map<int, int> ht;
    int N;
    int discount;
    int cnt;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
int main()
{}
