/*******************************************************************************
 *      file name: most_visited_sector_in_a_circular_track.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/12/11-16:32:53                              
 *  modified time: 2021/12/11-16:32:53                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> cnts(n+1, 0);
        int N = rounds.size();
        for (int i = 1; i < N; i++) {
            int start = rounds[i-1];
            for (int j = start; j != rounds[i]; ) {
                //cout<<"i:"<<i<<",j:"<<j<<endl;
                cnts[j]++;
                j = ((j+1)%n);
                if (j == 0) j = n;
            }
        }
        int index = rounds[N-1]%n;
        if (index == 0) index = n;
        cnts[index]++;
        
        int max1 = 0;
        for (int i = 0; i < n+1; i++) {
            if (cnts[i] > max1) max1=cnts[i];
        }
        vector<int> res;
        for (int i = 0; i < n+1; i++) {
            if (cnts[i] == max1) res.push_back(i);
        } 
        
        return res;
    }
};
int main()
{}
