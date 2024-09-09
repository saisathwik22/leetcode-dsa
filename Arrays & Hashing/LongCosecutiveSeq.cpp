// input -> [100, 4, 100, 1, 101, 3, 2, 1, 1]
// output -> return length of logest consecutive sequeunce -> 4
// 100, 101, 102 -> len = 3 | 1,2,3,4 -> len = 4


// Optimal : using unordered set
// TC --> O(n+n) approx, SC --> O(n)
// Accepted on leetcode..
// push elements into set data structure
// for nums[i], if nums[i]-1 is present --> move to next element in the set ds.
// if not present , choose that element and start sequence counting from that element, cnt=1 etc...

int longConsecSeq(vector<int>& nums) {
  if(nums.size() == 0) return 0;
  int longSq = 1;
  unordered_set<int> st;
  for(int i = 0; i<nums.size(); i++) st.insert(nums[i]);
  for(auto it : st) {
    if(st.find(it - 1) == st.end() ){
      int cnt = 1, x = it;
      while(st.find(x + 1) != st.end()){
        x++;
        cnt++;
      }
      longSq = max(longSq, cnt);
    }
  }
  return longSq;
}



// Better Solution: sorting the array
// TC --> O(nlogn) + O(n), SC --> O(1)
// Accepted at leetcode
int longConsecSeq(vector<int>& nums) {
  if(nums.size()==0) return 0;
  sort(nums.begin(), nums.end());
  int longSq = 1, currCnt = 0, lastSmall = INT_MIN;
  for(int i = 0; i<nums.size(); i++){
    if(nums[i] - 1 == lastSmall) {
      currCnt++;
      lastSmall = nums[i];
    }
    else if(nums[i] != lastSmall){
      currCnt = 1;
      lastSmall = nums[i];
    }
    longSq = max(longSq, currCnt);
  }
  return longSq;
}


// Brute Force: linear Search
// TC --> approx O(n*n), SC --> O(1)
// TLE on submission
bool linearSearch(vector<int>& arr, int num){
  for(int i = 0; i<n; i++) {
    if(arr[i] == num) return true;
  }
  return false;
}
int longConsecSq(vector<int>& nums) {
  int longSq = 1;
  for(int i = 0; i<nums.size(); i++) {
    int x = nums[i];
    int cnt = 1;
    while(linearSearch(nums, x+1) == true) {
      x++;
      cnt++;
    }
    longSq = max(longSq, cnt);
  }
  return longSq;
}
