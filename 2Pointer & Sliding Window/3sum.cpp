// 3 Sum problem - GOOGLE
// input -> array given nums[]
// output -> return triplets [[], [], ... ] such that nums[i] + nums[j] + nums[k] === 0, where i!=j!=k!=i
// [-1, 0, 1, 2, -1, -4] input
// output -> [ [-1,-1,2], [-1,0,1] ]

// Brute Force Approach
// TC = O(n*n*n*log(no. of unique triplets)
// SC = O(no. of triplets) * 2

vector<vector<int>> triplet(int n, vector<int>& nums) {
  vector<vector<int>> ans;
  set<vector<int>> st;
  for(int i=0; i<n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
        if(nums[i] + nums[j] + nums[k] == 0) {
          vector<int> temp = {nums[i], nums[j], nums[k] };
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
      }
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// Better solution - Hashing
// TC = O(n*n*logM)
// SC = O(n + no. of unique triplets * 2)

vector<vector<int>> triplet(int n, vector<int>& nums) {
  set<vector<int>> st;
  for(int i = 0; i<n; i++) {
    set<int> hashSet;
    for(int j = i+1; j < n; j++) {
      int third = -(nums[i] + nums[j]);
      if(hashSet.find(third) != hashSet.end()) {
        vector<int> temp = {nums[i], nums[j], third};
        sort(temp.begin(), temp.end());
        st.insert(temp);
      }
      hashSet.insert(nums[j]);
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// Optimal Solution
// TC = O(n*n) + O(nlogn)
// SC = O(no. of unique triplets)

vector<vector<int>> triplet(int n, vector<int>& nums) {
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  for(int i = 0; i<n; i++) {
    if(i > 0 && nums[i] == nums[i-1]) continue;
    int j = i + 1, k = n - 1;
    while(j < k) {
      int sum = nums[i] + nums[j] + nums[k];
      if(sum < 0) j++;
      else if(sum > 0) k--;
      else {
        vector<int> temp = {nums[i], nums[j], nums[k]};
        ans.push_back(temp);
        j++;
        k--;
        while(nums[j] == nums[j-1]) j++;
        while(nums[k] == nums[k+1]) k--;
      }
    }
  }
  return ans;
}
