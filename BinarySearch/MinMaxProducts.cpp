// leetcode 2064

// Binary Search
// Similar to KOKO Eating Bananas
// TC - O(m * log(maxValue)) SC - O(1)
class Solution {
public:
    bool isPossible(int x, vector<int>& quantities, int n) {
        for(int products : quantities) {
            n -= (products + x - 1) / x;
            if(n < 0) {
                return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid, quantities, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
