// leetcode1046
// GOOGLE AMAZON
// Approach - Brute Force
// TC - O(n*n*logn) SC - O(1)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int high = -1;
        int secondHigh;
        while(stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int a = stones.back();
            stones.pop_back();
            int b = stones.back();
            stones.pop_back();

            stones.push_back(abs(a - b));
        }
        return stones[0];
    }
};
// Approach - MAX Heap
// TC - O(nlogn)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i : stones) {
            pq.push(i);
        }
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a != b) {
                pq.push(abs(a - b));
            }
        }
        if(pq.size()) {
            return pq.top();
        }
        return 0;
    }
};
