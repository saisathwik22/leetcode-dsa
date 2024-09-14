string minWindow(string s, string t) {
        int i = 0, j = 0, start = 0, minLen = INT_MAX;
        unordered_map<char, int> map;
        for(auto it: t) map[it]++;
        int count = map.size();
        
        while(j < s.size()) {
            if(map.find(s[j]) != map.end()) {
                map[s[j]]--;
                if(map[s[j]] == 0) count--;
            }
            if(count == 0){
                while(count == 0) {
                    if(map.find(s[i]) != map.end()) {
                        map[s[i]]++;
                        if(map[s[i]] == 1) {
                            count++;
                            if(j - i + 1 < minLen){
                                minLen = j-i+1;
                                start = i;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        } 
        if(minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
