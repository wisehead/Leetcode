/*******************************************************************************
 *      file name: peeking_iterator.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/11-16:18:48                              
 *  modified time: 2020/10/11-16:18:48                              
 *******************************************************************************/
#include <iostream>
using namespace std;
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    flag = false;
        temp = 0;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (flag) return temp;
        if (hasNext()) {
            temp = Iterator::next();
            flag = true;
        }
        return temp;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (flag) {
            flag = false;
            return temp;
        }
        return Iterator::next();
	}
	
	bool hasNext() const {
        if (flag) return true;
	    return Iterator::hasNext();
	}
private:
    bool flag;
    int temp;
};
int main()
{}
