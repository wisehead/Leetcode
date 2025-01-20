/*******************************************************************************
 *      file name: number_of_longest_increasing_subsequence.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/20- 1:01                                    
 * modified time: 25/01/20- 1:01                                    
 *******************************************************************************/
#include <iostream>
vector<int> nums;
bool cmp(int ix1, int ix2){
    if(nums[ix1] != nums[ix2]) return nums[ix1] < nums[ix2];
    return ix1 > ix2;
}

class Solution {
public:

    class bitNode{
        public:
        int freq,max_length;
        bitNode(){
            freq = 0;
            max_length = 0;
        }
    };

    int n;
    vector<bitNode> bit;

    int findNumberOfLIS(vector<int>& Nums) {
        n = Nums.size();
        vector<int> sorted;
        for(int i= 0; i < n; i++) sorted.push_back(i);
        nums = Nums;
        sort(sorted.begin(),sorted.end(),cmp);

        bit = vector<bitNode>(n+1);

        for(int ix : sorted){
            int max_length = get_Max(ix);
            if(max_length == 0){
                update(ix,1,1);
                continue;
            }
            int freq = get_Freq(ix,max_length);
            update(ix,max_length + 1,freq);
        }

        int max_length = get_Max(n-1);
        return get_Freq(n-1,max_length);
    }


    int get_Max(int ix){
        ix++;
        int ans = 0;
        while(ix){
            ans = max(ans,bit[ix].max_length);
            ix -= ix & -ix;
        }
        return ans;
    }

    int get_Freq(int ix, int max_length){
        ix++;
        int ans = 0;
        while(ix){
            if(bit[ix].max_length == max_length){
                ans += bit[ix].freq;
            }
            ix -= ix & -ix;
        }
        return ans;
    }

    void update(int ix , int max_length, int freq){
        cout<<"1 ix:"<<ix<<endl;
        ix++;
        cout<<"2 ix:"<<ix<<endl;
        while(ix <= n){
            if(bit[ix].max_length < max_length){
                bit[ix].max_length = max_length;
                bit[ix].freq = freq;
            }
            else if(bit[ix].max_length == max_length){
                bit[ix].freq+= freq;
            }
            ix += ix & -ix;
            cout<<"3 ix:"<<ix<<endl;
        }
    }
};
