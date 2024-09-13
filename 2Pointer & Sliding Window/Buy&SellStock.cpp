// Buy and sell stock, maximize the profit.
int buySellStock(vector<int>& nums) {
  int mini = nums[0], profit = 0, n = nums.size();

  for(int i = 1; i < n; i++) {
    int cost = nums[i] - mini;
    profit = max(cost, profit);
    mini = min(nums[i], mini);
  }
  return profit;
}
