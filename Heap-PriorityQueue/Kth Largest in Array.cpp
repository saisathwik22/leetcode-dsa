// Leetcode 215
// AMAZON, FLIPKART, MICROSOFT, CISCO, SNAPDEAL, SAP LABS, ACCOLITE, ABCO, ROCKSTAND
// Approach - Brute Force - Sorting 
// TC - O(n*logn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};

// Approach - MIN Heap
// TC - O(n*logk) worst case - k == n
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i : nums) {
            minHeap.push(i);
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};

// Approach - Quick Select Algorithm
// Hoare's Algorithm
// TC - O(n) - avg, O(n*n) worst case
class Solution {
public:
    int partitionAlgo(vector<int>& arr, int L, int R) {
        int P = arr[L];
        int i = L + 1, j = R;
        while(i <= j) {
            if(arr[i] < P && arr[j] > P) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
            if(arr[i] >= P) i++;
            if(arr[j] <= P) j--;
        }
        swap(arr[L], arr[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int L = 0, R = n - 1;
        int pivotIndex = 0;
        while(true) {
            pivotIndex = partitionAlgo(nums, L, R);
            if(pivotIndex == k - 1) break;
            else if(pivotIndex > k - 1) R = pivotIndex - 1;
            else L = pivotIndex + 1;
        }
        return nums[pivotIndex];
    }
};
