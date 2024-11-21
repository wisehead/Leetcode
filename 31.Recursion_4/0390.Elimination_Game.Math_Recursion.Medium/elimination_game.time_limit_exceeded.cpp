/*******************************************************************************
 *      file name: elimination_game.cpp                                               
 *         author: hui chen. (c) 24                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 24/11/21-11:11                                    
 * modified time: 24/11/21-11:11                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    int lastRemaining(int n) {
        vector<int> vec(n,0);
        for (int i = 0; i < n; i++) {
            vec[i] = i+1;
        }
        int i = 1;
        bool left_to_right = (i%2);
        int ret = do_remove(vec,left_to_right);
        while (ret > 1) {
            i++;
            left_to_right = i%2;
            ret = do_remove(vec,left_to_right);
        }
        return vec[0];
    }

    int do_remove(vector<int> &vec, bool left_to_right) {
        int n = vec.size();
        if (n==1) return 1;
        int start = 0;
        if (!left_to_right && n%2 == 0) start = 1;
        for (int i = start; i < vec.size();) {
                vec.erase(vec.begin()+i);
                if (i < vec.size()) {
                    i++;
                }
        }

        return vec.size();
    }
};
