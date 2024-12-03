// leetcode 621
// FACEBOOK META
// Approach - MAX Heap
// TC - O(n) SC - O(1)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();
        unordered_map<char, int> mp;
        for(char &ch : tasks) {
            mp[ch]++;
        }
        priority_queue<int> pq;
        int time = 0;
        for(auto &it : mp) {
            pq.push(it.second);
        }
        while(!pq.empty()) {
            vector<int> temp;
            for(int i = 1; i<=p+1; i++) {
                if(!pq.empty()) {
                    temp.push_back(pq.top() - 1);
                    pq.pop();
                }
            }
            for(int &freq : temp) {
                if(freq > 0) {
                    pq.push(freq);
                }
            }
            if(pq.empty()) {
                time += temp.size();
            }
            else {
                time += (p + 1);
            }
        }
        return time;
    }
};
// Approach - GREEDY
class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();
        if(p == 0) {
            return n;
        }
        vector<int> counter(26, 0);
        for(char &ch : tasks) {
            counter[ch - 'A']++;
        }
        sort(counter.begin(), counter.end());
        int gaps = counter[25] - 1;
        int idleSpots = gaps * p;
        for(int i = 24; i >= 0; i--) {
            idleSpots -= min(gaps, counter[i]);
        }
        if(idleSpots > 0) {
            return n + idleSpots;
        }
        return n;
    }
};
