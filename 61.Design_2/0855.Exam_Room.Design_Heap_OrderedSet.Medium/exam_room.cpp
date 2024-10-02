/*******************************************************************************
 *      file name: exam_room.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/10/02-10:10                                    
 * modified time: 24/10/02-10:10                                    
 *******************************************************************************/
#include <iostream>
class ExamRoom {
public:
    ExamRoom(int n) {
        N = n;
    }

    int seat() {
        cout<<"seat() start"<<endl;
        // if (seats.empty()) {
        //     seats.insert(0);
        //     cout<<"seat() end, cur:"<<0<<endl;
        //     return 0;
        // }
        // if (seats.size() == 1 && seats.count(0)) {
        //     seats.insert(N-1);
        //     cout<<"seat() end, cur:"<<N-1<<endl;
        //     return N-1;
        // }

        int cur = 0;
        int dis = 0;

        if (seats.empty()) {
            seats.insert(0);
            cout<<"seat() end, cur:"<<0<<endl;
            return 0;
        }
        auto it = seats.begin();
        dis = *it;
        if (dis == 0)
            it++;
        while (it != seats.end()) {
            if (it == seats.begin()) {
                cout<<"*(it):"<<*(it)<<endl;
                cout<<"*prev(it):"<<*prev(it)<<endl;
            }
            // int temp = *it - *prev(it);
            // cout<<"temp:"<<temp<<",dis:"<<dis<<endl;
            // if (temp/2 > dis/2) {
            //     dis = temp;
            //     cur = *prev(it) + dis/2;
            // }

            int temp = (*it - *prev(it))/2;
            // cout<<"temp:"<<temp<<",dis:"<<dis<<endl;
            if (temp > dis) {
                dis = temp;
                cur = *prev(it) + dis;
            }
            // cout<<"cur:"<<cur<<endl;
            it++;
        }
        //calculate distance at the end
		if (dis < ((N - 1) - *(seats.rbegin()))) {
			cur = N - 1;
		}
        seats.insert(cur);
        cout<<"seat() end, cur:"<<cur<<endl;
        return cur;
    }

    void leave(int p) {
        cout<<"leave() p:"<<p<<endl;
        seats.erase(p);
    }
private:
    set<int> seats;
    int N;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
