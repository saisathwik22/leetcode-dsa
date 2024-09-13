// Longest substring without repeating characters.
int lengthOfLongestSubstring(string s) {
        int n = s.length(), i = 0, j = 0, maxSize = 0;
        unordered_map<char, int> map;
        while(j < n) {
            map[s[j]]++;
            if(map.size() > j - i + 1) {
                j++;
            }
            else if(map.size() == j - i + 1) {
                maxSize = max(maxSize, j - i + 1);
                j++;
            }
            else if(map.size() < j - i + 1) {
                while(map.size() < j - i + 1) {
                    map[s[i]]--;
                    if(map[s[i]] == 0) {
                        map.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxSize;
    }
