// problem 2187
// similar to problem 875 - KOKO eating bananas..
// TC -> O(n * log(minVal*totalTrips))
// SC -> O(1)
// only difference with 875 ques is r variable ..
class Solution {
public:
    bool possible(vector<int>& time, long long givenTime, int totalTrips) {
        long long actualTrips = 0;
        for(int &t: time) {
            actualTrips += givenTime/t;
        }
        return actualTrips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long l = 1;
        long long r = (long long) *min_element(time.begin(), time.end())*totalTrips;
        while(l < r) {
            long long midTime = l + (r - l) / 2;
            if(possible(time, midTime, totalTrips)) {
                r = midTime;
            } else {
                l = midTime + 1;
            }
        }
        return l;
    }
};
