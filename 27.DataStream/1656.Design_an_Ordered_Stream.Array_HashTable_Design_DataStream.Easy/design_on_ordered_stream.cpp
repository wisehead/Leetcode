/*******************************************************************************
 *      file name: design_on_ordered_stream.cpp                                               
 *         author: hui chen. (c) 22                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 22/08/16- 8:08                                    
 * modified time: 22/08/16- 8:08                                    
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) {
        vec.resize(n);
        start = 0;
        end = 1;
    }

    vector<string> insert(int idKey, string value) {
        vector<string> res;
        vec[idKey-1] = value;
        if (idKey > end) end = idKey;
        for (int i = start; i < end; i++) {
            if (vec[i] != "") {
                res.push_back(vec[i]);
                start = i+1;
            } else
                break;
        }
        return res;
    }
private:
    vector<string> vec;
    int start;
    int end;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main() {
}
