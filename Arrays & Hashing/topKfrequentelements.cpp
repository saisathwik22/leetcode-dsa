// input -> [1,1,1,2,2,3] k=2
// output -> top-k elements with most frequency. -> [1,2]

// TC = O(n) SC = O(n+n)

vector<int> topKFrequent(vector<int>& nums, int k) {
  int n = nums.size();
        
  unordered_map<int, int> m;
  // hash the elemenst to hash map
  for (int i = 0; i < n; i++) {
    m[nums[i]]++;
  }
        
  vector<vector<int>> buckets(n + 1);
  for (auto it = m.begin(); it != m.end(); it++) {
    // array elements pushed to index position which is equal to its frequency.
     buckets[it->second].push_back(it->first);
  }
        
  vector<int> result;
        
  for (int i = n; i >= 0; i--) {
    if (result.size() >= k) {
      break;
    }
    // if bucket is not empty then push it to result array.
    if (!buckets[i].empty()) {
      result.insert(result.end(), buckets[i].begin(), buckets[i].end());
    }
  }
        
  return result;
        
}
