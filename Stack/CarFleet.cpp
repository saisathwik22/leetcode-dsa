

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<float> st;
        vector<pair<int, float>> temp;
        for(int i=0; i<n; i++) {
            temp.push_back({position[i], float(target - position[i])/speed[i]});
        }
        sort(temp.begin(), temp.end());
        for(auto x: temp) {
            float time = x.second;
            while(st.size() && time >= st.top()) st.pop();
            st.push(time);
        }
        return st.size();
    }
};
