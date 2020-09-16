/*******************************************************************************
 *      file name: majority_element.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/04/12-10:05:52                              
 *  modified time: 2019/04/12-10:05:52                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*
    思路：摩尔投票升级版，超过n/3的数最多只能有两个；
    先选出两个候选人A,B,遍历数组，如果投A（等于A），则A的票数++;如果投B，B的票数++；
    如果A,B都不投（即与A，B都不相等）,那么检查此时是否AB中候选人的票数是否为0，如果为0,则成为新的候选人；
    如果A,B两个人的票数都不为0，那么A,B两个候选人的票数均--；
    遍历结束后选出两个候选人，但是这两个候选人是否满足>n/3，还需要再遍历一遍数组，找出两个候选人的具体票数
     */
    vector<int> majorityElement(vector<int>& nums) {
		vector<int> res;
        if (nums.empty())
            return res;
        //初始化，定义两个候选人以及对应的票数
        int candidateA=nums[0];
        int candidateB=nums[0];
        int countA=0;
        int countB=0;

        // 遍历数组
        for (auto num:nums){
            if (num==candidateA){ //投A
                countA++;
                continue;
            }

            if (num==candidateB){// 投B
                countB++;
                continue;
            }
            //此时A,B都不投,检查是否有票数为0情况，如果为0，则更新候选人
            if (countA==0){
                candidateA=num;
                countA++;
                continue;
            }

            if (countB==0){
                candidateB=num;
                countB++;
                continue;
            }

            //此时两个候选人的票数都大于1，且当前选名不投AB，那么A,B对应的票数都要--;
            countA--;
            countB--;
        }

        // 上一轮遍历找出了两个候选人，但是这两个候选人是否均满足票数大于N/3仍然没法确定，需要重新遍历，确定票数
        countA=0;
        countB=0;

        for (auto num:nums){
            if (num==candidateA){
                countA++;
            }else if (num==candidateB){
                countB++;
            }
        }

        if (countA>nums.size()/3) res.push_back(candidateA);
        if (countB>nums.size()/3) res.push_back(candidateB); 
        return res;
    }

};
int main()
{}
