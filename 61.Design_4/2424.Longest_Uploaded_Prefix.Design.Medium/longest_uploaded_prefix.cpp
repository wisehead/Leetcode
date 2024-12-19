/*******************************************************************************
 *      file name: longest_uploaded_prefix.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/12/19-12:12                                    
 * modified time: 24/12/19-12:12                                    
 *******************************************************************************/
#include <iostream>
class LUPrefix {
public:
    LUPrefix(int n) {
        vec.resize(n+2);
        fill(vec.begin(), vec.end(), 0);
        vec[0] = 1;
        lwm = 0;
    }

    void upload(int video) {
        // cout<<"start video:"<<video<<endl;
        vec[video] = 1;
        while (lwm < vec.size()) {
            if (vec[lwm] == 0) {
                lwm--;
                break;
            }
            lwm++;
        }
        // cout<<"end lwm:"<<lwm<<endl;
    }

    int longest() {
        return lwm;
    }
public:
    vector<int> vec;
    int lwm;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
