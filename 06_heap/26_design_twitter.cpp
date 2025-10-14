/*
https://leetcode.com/problems/design-twitter/description/


Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 

Example 1:

Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
 

Constraints:

1 <= userId, followerId, followeeId <= 500
0 <= tweetId <= 104
All the tweets have unique IDs.
At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.
A user cannot follow himself.
*/

class Twitter {
public:
    struct Compare{
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            return a.first < b.first; // max-heap
        }
    };

    // Follow -> map<userId, set of followee userId's> -> O(1)
    // [1, [2,3,4]]
    unordered_map<int, unordered_set<int>> followee;

    // Post Tweet -> map<userId, LL (inserting at front along with counter) -> O(1)
    // [1, [ {5,3}, {2,1}]] (count, tweetId)
    unordered_map<int, deque<pair<int,int>>> tweets;
    int count = 1; // using as a time stamps for latest news

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_front({count, tweetId});
        count++;
    }
    

    // Like merge k sorted lists -> get top 10 counts
    // get all followees tweets and user's tweets
    // eg - [1, [{5,3}, {2,1}]],  [3, [ {4,2}, {3,4}]]
    // now merge [{5,3}, {2,1}], [ {4,2}, {3,4}] like k sorted lists

    vector<int> getNewsFeed(int userId) {
        vector<deque<pair<int,int>>> arr; // store tweets of userId's
        vector<int> ans;

        arr.push_back(tweets[userId]); // push user's tweets
        unordered_set<int> followeeId = followee[userId];
        for (auto &x : followeeId) {
            arr.push_back(tweets[x]);
        }

        priority_queue < pair<int,int>, vector<pair<int,int>>, Compare > pq;

        for (int i = 0; i < arr.size(); i++) {
            for (auto &p : arr[i]) pq.push(p);
        }

        int k = 10;
        while (!pq.empty() && k--) {
            // ✅ Change 3: pq.top() gives a pair, not a deque
            auto top = pq.top();
            pq.pop();

            ans.push_back(top.second); // push tweetId
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        // [1, [2,3,4]] -> add 5 and become [1, [2,3,4,5]] --> O(1)
        followee[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // [1, [2,3,4,5]] -> remove 5 and become [1, [2,3,4]] --> O(1)
        followee[followerId].erase(followeeId);
    }
};