/*******************************************************************************
 *      file name: product_of_the_last_k_numbers.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/06-20:39:33                              
 *  modified time: 2020/10/06-20:39:33                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        size = 0;
        pos = -1;
    }
    
    void add(int num) {
        data.push_back(num);
        if (num == 0) pos = size;
        
        if (size == 0)
            res.push_back(num);
        else
        {
            if (res[size-1] == 0)
                res.push_back(num);
            else
                res.push_back(res[size-1]*num);
        }
        ++size;
        
    }
    
    int getProduct(int k) {
        if (size-k-1 < pos) return 0;
        if (size-k-1 == pos) return res[size-1];
        return res[size-1] / res[size-k-1];
    }
private:
    vector<int> data;
    vector<int> res;
    int pos;
    int size;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
int main()
{}
