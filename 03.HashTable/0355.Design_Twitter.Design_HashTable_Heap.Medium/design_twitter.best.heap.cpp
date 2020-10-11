/*******************************************************************************
 *      file name: design_twitter.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/11-18:17:02                              
 *  modified time: 2020/10/11-18:17:02                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

class Twitter {
private:    
   unordered_map<int, set<int>> fo;
   unordered_map<int, vector<pair<int, int>>> t;
   long long time; 

public:
/** Initialize your data structure here. */
Twitter() {
    time = 0;
}

/** Compose a new tweet. */
void postTweet(int userId, int tweetId) {
    t[userId].push_back({time++, tweetId});
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int, int>> maxHeap; 
    for (auto it=t[userId].begin();it!=t[userId].end();++it)
        maxHeap.push(*it);
    for (auto it1=fo[userId].begin();it1!=fo[userId].end();++it1){
        int usr = *it1; // get target user
        for (auto it2=t[usr].begin();it2!=t[usr].end();++it2)
            maxHeap.push(*it2);
    }   
    vector<int> res;
    while(maxHeap.size()>0) {
        res.push_back(maxHeap.top().second);
        if (res.size()==10) break;
        maxHeap.pop();
    }
    return res;
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void follow(int followerId, int followeeId) {
    if (followerId != followeeId)
        fo[followerId].insert(followeeId);
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void unfollow(int followerId, int followeeId) {
    fo[followerId].erase(followeeId);
}
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
int main()
{
  Twitter* obj = new Twitter();
  //obj->postTweet(userId,tweetId);
  //vector<int> param_2 = obj->getNewsFeed(userId);
  //obj->follow(followerId,followeeId);
  //obj->unfollow(followerId,followeeId);
  vector<int> param_2;
  vector<string> commands = {"postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","getNewsFeed","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","getNewsFeed","postTweet","unfollow","postTweet","postTweet","postTweet","getNewsFeed","postTweet","postTweet","getNewsFeed","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","follow","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","follow","postTweet","postTweet","postTweet","postTweet","follow","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","getNewsFeed","postTweet","postTweet","getNewsFeed","postTweet","postTweet","follow","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","getNewsFeed","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","unfollow","postTweet","postTweet","unfollow","getNewsFeed","postTweet","postTweet","follow","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","unfollow","getNewsFeed","postTweet","postTweet","postTweet","unfollow","postTweet","postTweet","postTweet","postTweet","unfollow","postTweet","postTweet","postTweet","getNewsFeed","postTweet","postTweet"};

  vector<vector<int>> args = {{11,994},{4,303},{1,113},{18,309},{8,905},{6,605},{1,210},{15,15},{1,88},{1,704},{8},{9,59},{4,851},{13,974},{2,133},{15,255},{15,662},{16,21},{13,227},{17},{5,603},{10,7},{5,816},{7,792},{12,260},{5},{4,586},{1,645},{20},{15,171},{16,18},{3,812},{15,153},{12,726},{6,508},{17,817},{5,6},{3,667},{5,599},{13,353},{11,282},{7,226},{18,423},{13,875},{2,738},{6,727},{7,374},{19,811},{8,418},{2,179},{3,476},{9,15},{16,8},{19,827},{17,203},{13,246},{14,8},{13,750},{4,595},{1,793},{17,995},{11,589},{2,115},{18,870},{15,426},{18,953},{10,318},{10,419},{2,164},{9},{18,854},{3,394},{17},{4,834},{4,349},{2,16},{13,534},{3,773},{4,292},{5,951},{17,554},{4,646},{6,412},{15,548},{8,188},{5,539},{18,732},{8,591},{11,733},{1,517},{8,156},{13,331},{11,889},{12,782},{11},{2,578},{16,487},{12,640},{14,112},{10,901},{8,807},{7,818},{7,627},{14,9},{4,522},{7,505},{9,13},{3},{1,971},{18,808},{1,17},{7,197},{7,361},{2,986},{17,6},{7,211},{15,342},{5,538},{1,711},{11,863},{17,339},{5,656},{4,402},{1,514},{11,566},{12,11},{12},{19,899},{19,526},{20,799},{4,1},{17,363},{7,845},{15,329},{17,369},{18,18},{15,848},{5,928},{18,105},{18},{17,785},{11,457}};
    for (int i = 0; i < commands.size(); i++)
    {
        int x = args[i][0];
        int y = 0; 
		if (args[i].size() > 1)
			y = args[i][1];
        if (commands[i] == "postTweet")
            obj->postTweet(x,y);
        else if (commands[i] == "follow")
            obj->follow(x,y);
        else if (commands[i] == "unfollow")
            obj->unfollow(x,y);
        else if (commands[i] == "getNewsFeed")
            param_2 = obj->getNewsFeed(x);
        else
            cout<<"ERROR!"<<endl;

    }

}
