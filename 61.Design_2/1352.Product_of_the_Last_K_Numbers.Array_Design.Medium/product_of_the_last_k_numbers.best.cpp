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
    }
    
    vector<int> A = {1};
    void add(int a) {
        if (a)
            A.push_back(A.back() * a);
        else
            A = {1};
    }

    int getProduct(int k) {
        return k < A.size() ? A.back() / A[A.size() - k - 1]  : 0;
    }

};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
int main()
{}
