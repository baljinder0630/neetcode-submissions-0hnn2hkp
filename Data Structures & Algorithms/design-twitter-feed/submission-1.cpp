class Twitter {
public:
    unordered_map<int,unordered_set<int>> followers;
    int time;
    unordered_map<int,vector<pair<int,int>>> posts;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time++,tweetId});   
    }
    
    vector<int> getNewsFeed(int userId) {   
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (auto post : posts[userId]) {
            pq.push(post);
            if (pq.size() > 10) pq.pop();
        }
        for(auto it:followers[userId]){
            for(auto post:posts[it]){
                pq.push(post);
                if(pq.size() > 10)pq.pop();
            }
        }        
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
