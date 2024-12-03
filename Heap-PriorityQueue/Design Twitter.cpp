// leetcode 355
// Approach sorting
// TC - O(n*m + tlogt) for getNewsFeed() & O(1) for remaining methods.
// SC - O(N*m + N*M)
class Twitter {
    int time;
    unordered_map<int, unordered_set<int>>followMap;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
public:
    Twitter() : time(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> feed = tweetMap[userId];
        for(int followeeId: followMap[userId]) {
            feed.insert(feed.end(), tweetMap[followeeId].begin(), tweetMap[followeeId].end());
        }
        sort(feed.begin(), feed.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
        vector<int> res;
        for(int i = 0; i < min(10, (int)feed.size()); i++) {
            res.push_back(feed[i].second);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

// Approach HEAP
// TC - O(n) for getNewsFeed() and O(1) for rest of the methods. 
// SC - O(N*m + N*M + n)
// n - total number of followeeIDS linked with userId, m = max number of tweets by user, 
// N = total number of userIds , M = max number of followees for any user.
class Twitter {
    int count;
    unordered_map<int, vector<vector<int>>> tweetMap;
    unordered_map<int, set<int>> followMap;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minHeap(compare);

        followMap[userId].insert(userId);
        for(int followeeId : followMap[userId]) {
            if(tweetMap.count(followeeId)) {
                const vector<vector<int>>& tweets = tweetMap[followeeId];
                int index = tweets.size() - 1;
                minHeap.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }
        while(!minHeap.empty() && res.size() < 10) {
            vector<int> curr = minHeap.top();
            minHeap.pop();
            res.push_back(curr[1]);
            int index = curr[3];
            if(index > 0) {
                const vector<int>& tweet = tweetMap[curr[2]][index - 1];
                minHeap.push({tweet[0], tweet[1], curr[2], index - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

