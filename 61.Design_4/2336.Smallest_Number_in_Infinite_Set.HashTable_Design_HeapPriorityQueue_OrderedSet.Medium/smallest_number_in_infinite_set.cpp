/*******************************************************************************
 *      file name: smallest_number_in_infinite_set.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/15- 1:01                                    
 * modified time: 25/01/15- 1:01                                    
 *******************************************************************************/
#include <iostream>
class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        lwm = 1;
    }

    int popSmallest() {
        int ret = 0;
        if (!add.empty()) {
            ret = *add.begin();
            add.erase(ret);
        } else {
            ret = lwm++;
        }
        return ret;
    }

    void addBack(int num) {
        if (num < lwm) {
            add.insert(num);
        }
    }
public:
    set<int> add;
    int lwm;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
