/*******************************************************************************
 *      file name: path_crossing.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/11/24-09:59:34                              
 *  modified time: 2021/11/24-09:59:34                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    void move(int& x, int&y, char type) {
        switch (type) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            default:
                break;
        }
    }
    bool isPathCrossing(string path) {
        set<vector<int>> ss;
        int x = 0, y = 0;
        vector<int> vec(2,0);
        ss.insert(vec);
        //ss.insert(vector<int> {0,0});
        for (auto c : path) {
            move(x, y, c);
            vec[0] = x;
            vec[1] = y;
            if (ss.count(vec)) return true;
            ss.insert(vec);
        }
        return false;
    }

};
int main()
{}
