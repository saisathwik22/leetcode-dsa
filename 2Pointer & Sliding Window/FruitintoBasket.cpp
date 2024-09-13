// Pick Toys question from sliding window playlist.

int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), i = 0, j = 0, ans = INT_MIN;
        if(n == 1) return 1;
        unordered_map<int, int> map;
        while(j < n) {
            map[fruits[j]]++;
            if(map.size() < 2) j++;
            else if(map.size() == 2) {
                ans = max(ans, j - i + 1);
                j++;
            }
            else if(map.size() > 2) {
                while(map.size() > 2) {
                    map[fruits[i]]--;
                    if(map[fruits[i]] == 0) map.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        if(map.size() == 1) {
            auto it = map.begin();
            return it -> second;
        }
        return ans;
    }
