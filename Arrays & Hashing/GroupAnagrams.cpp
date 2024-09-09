// input -> ["eat", "tea", "tan", "ate", "nat", "bat" ]
// output -> group the anagrams
// [ [eat, tea, ate], [tan, nat], [bat] ]

// Approach 1 - HashMap and sorting - TC = O(nKLogK) - SC = O(N)
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> map;
  int n = strs.size();
  string temp;

  for(int i=0; i<n; i++){
    temp = strs[i];
    // sort the string.
    sort(strs[i].begin(), strs[i].end());
    // sorted string is the key, temp string is the value chained to it.
    map[strs[i]].push_back(temp);
  }
  vector<vector<string>> ans;
  for(auto i=map.begin(); i != map.end(); i++){
    ans.push_back(i -> second);
  }
  return ans;
}

