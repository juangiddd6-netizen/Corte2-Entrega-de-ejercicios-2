#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Twitter {
private:
    
    int time = 0;

    struct Tweet {
        int id;
        int time;
        Tweet* next;

        Tweet(int id, int time) {
            this->id = id;
            this->time = time;
            next = nullptr;
        }
    };

    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, Tweet*> tweetMap;

public:

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        time++;

        Tweet* tweet = new Tweet(tweetId, time);

        if (tweetMap.count(userId)) {
            tweet->next = tweetMap[userId];
        }

        tweetMap[userId] = tweet;
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> result;

        auto cmp = [](Tweet* a, Tweet* b) {
            return a->time < b->time;
        };

        priority_queue<Tweet*, vector<Tweet*>, decltype(cmp)> pq(cmp);

        followMap[userId].insert(userId);

        for (int followee : followMap[userId]) {
            if (tweetMap.count(followee)) {
                pq.push(tweetMap[followee]);
            }
        }

        int count = 10;

        while (!pq.empty() && count--) {
            Tweet* tweet = pq.top();
            pq.pop();

            result.push_back(tweet->id);

            if (tweet->next) {
                pq.push(tweet->next);
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followMap.count(followerId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};