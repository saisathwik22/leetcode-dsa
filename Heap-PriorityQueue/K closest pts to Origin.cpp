// leetcode 973
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        vector<vector<int>> ans;

        for(int i = 0; i < points.size(); i++) {
            maxHeap.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], make_pair(points[i][0], points[i][1])});
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        while(!maxHeap.empty()) {
            ans.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
