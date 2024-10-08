// problem 875
// problem similar to leetcode-2187-Min Time to complete trips.
// difference with 2187 ques is only the initialization of 'r' variable.
// TC -> O(n * log(maxEle)
// SC -> O(1);
class Solution {
public:
    /*
    Similar to problem 2187 -> Min time to complete trips
    */
    bool canEatAll(vector<int>& piles, int mid, int h) {
        int actualHours = 0;
        for(int &x: piles) {
            actualHours += x/mid;
            if(x % mid != 0) {
                actualHours++;
            }
        }
        return actualHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        // only difference from 2187 is 'r' variable..
        int r = *max_element(piles.begin(), piles.end());

        while(l < r) {
            int mid = l + (r - l) / 2;
            if(canEatAll(piles, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
