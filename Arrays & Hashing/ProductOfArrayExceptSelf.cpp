// input -> nums = [1,2,3,4]
// output -> ans = [24, 12, 8, 6]
// ans[i] = product of all array elements except nums[i]
// division operator not allowed since '0' generates error.

// Approach 1:

// prefix array -> to store prefix product
// postfix array -> to store postfix product

// nums = [1,2,3,4]
// prefix[0] = nums[0] = 1, prefix[1] = nums[0]*nums[1] = 2, prefix[2] = nums[0]*nums[1]*nums[2] = 6, prefix[3] = nums[0]*nums[1]*nums[2]*nums[3] = 24
// prefix -> [1.2.6.24]
// postfix --> same prefix process but from last element
// postfix[3] = nums[3] = 4, postfix[2] = nums[3]*nums[2] = 12, postfix[1] = nums[3]*nums[2]*nums[1] = 24, postfix[0] = nums[3]*nums[2]*nums[1]*nums[0] = 24
// postfix -> [24,24,12,4]

// prefix[i] = nums[i]*nums[i-1]*nums[i-2]*.....
// postfix[i] = nums[i]*nums[i+1]*nums[i+2]*....
// ans[i] = prefix[i-1]*postfix[i+1]

// ans[0] = postfix[1] = 24 (prefix before 0 not available)
// ans[1] = prefix[0] * postfix[2] = 12
// ans[2] = prefix[1] * postfix[3] = 8
// ans[3] = prefix[2] = 6 (postfix beyond 3 not available)

// output -> ans = [24,12,8,6]
// TC -> O(n) SC -> O(n) due to prefix postfix arrays
// optimize and compute without extra arrays

// Approach 2 - computing prefix and postfix in output array only.

// nums = [1,2,3,4] pre=1, ans = [], start from nums[0]
// at nums[0] = 1, place pre=1 in ans[0] --> ans = [1] --> pre=nums[0]*pre = 1
// at nums[1] = 2, place pre=1 in ans[1] --> ans = [1,1] --> pre=nums[1]*pre = 2
// at nums[2] = 3, place pre=2 in ans[2] --> ans = [1,1,2] --> pre=nums[2]*pre = 6
// at nums[3] = 4, place pre=6 in ans[3] --> ans = [1,1,2,6] --> pre=nums[3]*pre = 24
// after prefix operations ans = [1,1,2,6]

// nums = [1,2,3,4] post=1, ans = [1,1,2,6], start from nums[3]
// at nums[3] = 4, * post=1 in ans[3] --> ans = [1,1,2,6] --> post = 1*nums[3] = 4
// at nums[2] = 3, * post=4 in ans[2] --> ans = [1,1,8,6] --> post = 4*nums[2] = 12
// at nums[1] = 2, * post=12 in ans[1] --> ans = [1,12,8,6] --> post = 12*nums[1] = 24
// at nums[0] = 1, * post=24 in ans[0] --> ans = [24,12, 8, 6] --> post = 24(leave)

// final ans array after prefix and postfix operations --> ans = [24, 12, 8, 6]
// TC -> O(n) SC -> O(1) [Space complexity modified due to computations in output array itself].

vector<int> productExceptSelf(vector<int>& nums){
  int n = nums.size();
  vector<int> ans(n,1);

  int prefix = 1;
  for(int i=0; i<n; i++) {
    ans[i] = prefix;
    prefix = prefix * nums[i];
  }

  int postfix = 1;
  for(int i=n-1; i>=0; i--){
    ans[i] = ans[i] * postfix;
    postfix = postfix * nums[i];
  }
  return ans;
}

