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
    vector<int> t;
    vector<int> a;
    int k;
    LUPrefix(int n) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        k = n;
        t.resize(4*n,0);
        a.resize(n,0);
        tree(0,k-1,0);
    }
    
    void upload(int video) {
        a[video - 1] = 1;
        int v = video-1;
        update(0, 0,k-1,v);
    }
    
    int longest() {
        return t[0];
    }

 private:
    void update(int ind , int tl , int tr, int pos)
    {
        if(tl == tr)
        {
            t[ind] = 1;
            return;
        }
        int tm = (tl+tr)/2;

        if(pos<=tm)
        {
            update(ind*2+1,tl,tm,pos);
        }
        else
        {
            update(ind*2+2,tm+1,tr,pos);
        }
        t[ind] = comb(t[2*ind+1],t[2*ind+2],tm,tl,tr);
    }

    int comb(int l, int r, int mid ,int tl, int tr)
    {
        if(l == mid-tl+1)
        {
            return l+r;
        }
        else
        {
            return l;
        }
    }
    void tree(int tl,int tr,int ind)
    {
        if(tl == tr)
        {
            t[ind] = a[tl];
        }
        else
        {
            int tm = (tl+tr)/2;
            tree(tl,tm,2*ind+1);
            tree(tm+1,tr,2*ind+2);
            t[ind] = comb(t[2 * ind + 1], t[2 * ind + 2], tm,tl, tr);
        }
    }
};
/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
