class Twitter {
    unordered_map<int,vector<pair<int,int>>> tweets; // map of a list of tweets made by a user
    unordered_map<int,unordered_set<int>> follows; // List of users a user is following
    int t = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({t,tweetId});
        t += 1;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> myTweets = tweets[userId];
        vector<pair<int,int>> followersTweets;
        priority_queue<pair<int,int>> heap;
        for(int follower : follows[userId]){
            for(pair<int,int> tweet : tweets[follower]){
                followersTweets.push_back(tweet);
            }
        }
        for(pair<int,int> tweet : myTweets){
            heap.push(tweet);
        }
        for(pair<int,int> tweet : followersTweets){
            heap.push(tweet);
        }
        vector<int> feed;
        while((feed.size() < 10 and heap.size() > 0)){
            feed.push_back(heap.top().second);
            heap.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsheap(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */