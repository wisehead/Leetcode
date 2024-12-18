/*******************************************************************************
 *      file name: tweet_counts_per_frequency.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/14-11:21:47                              
 *  modified time: 2020/10/14-11:21:47                              
 *******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class TweetCounts {
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        vector<int> vec;
        if (ht.count(tweetName)) {
            vec = ht[tweetName];
            int size = vec.size();
            for (int i = 0; i < vec.size(); i++) {
                if (time < vec[i]) 
                {
                    vec.insert(vec.begin()+i,time);
                    break;
                }
            }
            if (size == vec.size()) vec.push_back(time);
        } else {     
            vec.push_back(time);
        }
        ht[tweetName] = vec;
        /*
        for (auto e : vec) {
            cout<<"e1:"<<e<<endl;
        }
        cout<<endl;
        */
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int delta = 1;
        if (freq == "minute") delta = 60;
        else if (freq == "hour") delta = 3600;
        else if (freq == "day") delta = 3600*24;
        vector<int> res;
        vector<int> vec = ht[tweetName];
        int k = 0;
        //cout<<"startTime:"<<startTime<<"    endTime:"<<endTime<<"   delta:"<<delta<<endl;
        /*
        for (auto e : vec) {
            cout<<"e:"<<e<<endl;
        }
        cout<<endl;
        */
        for (int start = startTime; start <= endTime; start += delta) {
            int cnt = 0;
            int end = min(startTime + delta, endTime);
            int j = 0;
            for (; j < vec.size(); j++) {
                end = min(start + delta, endTime);
                if (vec[j] < start) {
                    continue;
                } else if (vec[j] == start) {    
                    cnt++;
                } else if (vec[j] < end) {
                    cnt++;
                } else break;
                
            } 
            res.push_back(cnt);
            //cout<<"start:"<<start<<"    end:"<<end<<"   cnt:"<<cnt<<endl;
        }
        return res;
    }
private:
    map<string, vector<int>> ht;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
int main()
{}
