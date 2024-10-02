// TC -> O(n square) brute force

// TC -> O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && temp[i] >= temp[st.top()]) {
                st.pop();
            }
            if(st.empty()) {
                ans[i] = 0;
            }
            else {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};
