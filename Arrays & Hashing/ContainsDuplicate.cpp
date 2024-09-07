// check if given array contains any element which occurs atleast twice.
// return true or false.

// input - [1,2,3,1] output - true

// Approach 1 - brute force - TC = O(n*n) , SC = O(1)
for(int i=0 -> n){
  for(int j=1 -> n){
    compare each element with remaining elements.
  }
}
// Approach 2 - better solution - TC = O(nLogn) SC= O(1)
sort the array;
start iteration from arr[1];
if nums[i] == nums[i-1] -> then true, else false after the end of iteration;

// Approach 3 - Optimal Solution - TC = O(n) , SC = O(n)
// - iterate the loop, before inserting a specific element into the set, check if that element is already present or not.
// - Hash Set allows user to insert an element at a TC of O(1), which sums up to O(n).

use unordered_set<int> s;
for(i=0 --> n){
  if(s.find(nums[i]) != s.end()) return true;
  s.insert(nums[i]);
}
return false;
