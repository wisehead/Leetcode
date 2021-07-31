/*******************************************************************************
 *      file name: combination_sum_II.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/05-09:53:40                              
 *  modified time: 2019/03/05-09:53:40                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            std::vector<std::vector<int> >::iterator it = find(res.begin(), res.end(), combination);
            if (it == res.end())
                res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            int tmp = candidates[i];
            combination.push_back(candidates[i]);
            candidates.erase(candidates.begin() + i);
            combinationSum(candidates, target - tmp, res, combination, i);
            candidates.insert(candidates.begin() + i, tmp);
            combination.pop_back();
        }
    }
};
int main()
{}
