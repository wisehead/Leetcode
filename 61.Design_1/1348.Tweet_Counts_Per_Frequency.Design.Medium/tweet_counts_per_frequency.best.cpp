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
    unordered_map<string, multiset<int>> all;
public:
    TweetCounts() {}
    
    void recordTweet(string tweetName, int time) {
        all[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int d = 86400;
        if (freq[0] == 'm') {
            d = 60;
        } else if (freq[0] == 'h') {
            d = 3600;
        }
        vector<int> r((endTime - startTime) / d + 1);
        const auto s = all.find(tweetName);
        if (s != all.end()) {
            for (auto t = s->second.lower_bound(startTime); t != s->second.end() && *t <= endTime; ++t) {
               ++r[(*t - startTime) / d];
            }
        }
        return r;
    }
};


/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
int main()
{}
