class Solution {
public:
    vector<int> NSL(vector<int>& arr, int n) {
        // pair<value,index>
        stack<pair<int, int>> st;
        vector<int> left;
        int PseudoIndex = -1;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                left.push_back(PseudoIndex);
            } else if (st.top().first < arr[i]) {
                left.push_back(st.top().second);
            } else {
                while (!st.empty() && st.top().first >= arr[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    left.push_back(PseudoIndex);
                } else {
                    left.push_back(st.top().second);
                }
            }
            st.push({arr[i], i});
        }
        return left;
    }

    vector<int> NSR(vector<int>& arr, int n) {
        // pair<value,index>
        stack<pair<int, int>> st;
        vector<int> right;
        int PseudoIndex = n;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                right.push_back(PseudoIndex);
            } else if (st.top().first < arr[i]) {
                right.push_back(st.top().second);
            } else {
                while (!st.empty() && st.top().first >= arr[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    right.push_back(PseudoIndex);
                } else {
                    right.push_back(st.top().second);
                }
            }
            st.push({arr[i], i});
        }
        reverse(right.begin(), right.end());
        return right;
    }

    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0; // Edge case: empty array
        
        vector<int> Left = NSL(arr, n);
        vector<int> Right = NSR(arr, n);
        vector<int> width(n), Area(n);

        for (int i = 0; i < n; i++) {
            width[i] = Right[i] - Left[i] - 1;
        }

        for (int i = 0; i < n; i++) {
            Area[i] = arr[i] * width[i];
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (Area[i] > maxi) {
                maxi = Area[i];
            }
        }

        return maxi;
    }
};

