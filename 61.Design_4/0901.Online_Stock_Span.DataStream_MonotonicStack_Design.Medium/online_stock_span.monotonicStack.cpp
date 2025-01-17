/*******************************************************************************
 *      file name: online_stock_span.monotonicStack.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/17- 1:01                                    
 * modified time: 25/01/17- 1:01                                    
 *******************************************************************************/
#include <iostream>
class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {

    }

    int next(int price) {
        int span=1;
        while(!st.empty() && st.top().first <= price){
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};
