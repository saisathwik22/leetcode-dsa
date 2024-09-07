// TWO SUM:
// input - [2,1,5,3] target = 4;
// if there are any two elements whose sum is target, them return the indicies of those two elements.

vector<int> twoSum(vector<int>& nums, int target) {
        
    int n = nums.size();
    unordered_map<int, int> hash;
    for(int i=0; i<n; i++) {
      int diff = target - nums[i];
      if(hash.find(diff) != hash.end()) {
        return {hash[diff], i};
      }
      hash.insert({nums[i], i});
    }
    return {};
}

// - use unordered map <value, index>
// - iterate through the array, diff = target - nums[i]
// - check if this diff is already present in hashmap, if present then return the index of that value, and current array num index.
// - else insert the current num and its index into hashmap.
// - return empty {} if no such indecies are found.

  Time Complexity = O(n) , Space Complexity = O(n)
