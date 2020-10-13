/*******************************************************************************
 *      file name: iterator_for_combination.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/13-09:35:32                              
 *  modified time: 2020/10/13-09:35:32                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        res = fun(characters, combinationLength);   
    }
    
    vector<string> fun(string characters, int combinationLength) {
        //cout<<"str:"<<characters<<" len:"<<combinationLength<<endl;
        vector<string> vec;
        if (characters.length() == 0 || combinationLength == 0) return vec;
        
        for (int i = 0; i < characters.size() - combinationLength +1; i++) {
            string prefix = string(1, characters[i]);
            vector<string> subvec = fun(characters.substr(i+1), combinationLength-1);
            if (subvec.size() == 0) 
                vec.push_back(prefix);
            else {
                for (auto e : subvec) {
                    string str = prefix + e;
                    //cout<<"str:" <<str<<endl;
                    vec.push_back(str);
                }
            }
            
        }
        return vec;
    }
    
    string next() {
        if (!hasNext()) return string("");
        string str = res[0];
        res.erase(res.begin());
        return str;
    }
    
    bool hasNext() {
        return res.size();
    }
private:
    vector<string> res;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main()
{}
